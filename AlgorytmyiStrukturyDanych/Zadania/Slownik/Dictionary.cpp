#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include "Common.h"
#include "Dictionary.h"
#include "DictionaryTest.h"

using namespace std;

//------------------------------- Funkcje obsługi pary

Para* newPara(string klucz, int wartosc) {
	Para* para = new Para;
	para->klucz = klucz;
	para->wartosc = wartosc;
	return para;
};

void destroyPara(Para* para) {
	delete para;
}

//---------------------------- Funkcje obsługi słownika

//Funckje pomoznicze
Para* odczytajZListy(list<Para*> lista, int index) { //Odczytanie z listy elementu o indeksie index
	auto iter = lista.begin(); //Pobranie iteratora
	advance(iter, index); //Przesunięcie iteratora na pozycję do usunięcia
	return *iter; //
}

Para* usunZListy(list<Para*> lista, int index) { //Usunięcie z listy elementu o indeksie index
	auto iter = lista.begin(); //Pobranie iteratora
	advance(iter, index); //Przesunięcie iteratora na pozycję do usunięcia
	Para* para = *iter; //Pobieranie wskaźnika do pary do usunięcia 
	lista.erase(iter); //usun wartosc
	return para; //zwroc wartosc w postaci pary
}

//Obsługa mapy
Map* newMap(int tabSize) {
	//Dokonaj implementacji funkcji. Stwórz słownik konstruktorem listy: list<Para*>()
	assert(tabSize > 0);
	Map *mapa = new Map();
	mapa -> tabSize = tabSize;
	mapa -> numElements = 0;
	mapa -> tab = new list<Para*>[tabSize];
	return mapa;
};

void destroyMap(Map* map) {
	for (int i = 0; i < map->tabSize; i++) {		
		list<Para*> list = map->tab[i]; //Pobranie listy 
		list.clear(); //wyczyszczenie elementów listy
	}	
	delete[] map->tab;
	delete map;
}

int funkcjaMieszajaca(Map* map, string klucz) {
	//Dokonaj implementacji funkcji. Do realizacji możesz skorzystać z funkcji hashCode	
	if (map!= nullptr && map-> tab != nullptr) {
		int hash = 0;
		for (char ch: klucz) {
			int chInt = (int)ch;
			hash += chInt*71;
		}
		return hash % map->tabSize;
	}
	return NaN;
}

int znajdzIndeksKlucza(list<Para*> list, string klucz) {
	int i = 0;
	for (Para* p : list) {
		if (p->klucz == klucz) {
			return i;
		}
		i++;
	}
	return -1;
}

bool znajdzKlucz(std::list<Para*> lista, std::string klucz) { //Informuje czy w slowniku znajduje sie dany klucz
	return znajdzIndeksKlucza(lista, klucz) > -1;
}
void wstaw(Map* map, string klucz, int wartosc) {
	//Dokonaj implementacji funkcji. Do realizacji możesz skorzystać z funkcji funkcjaMieszajaca, znajdzIndeksKlucza
	//UWAGA: dodanie do listy możesz zrealizować za pomocą funkcji: lista.push_front(element)
	int idTablicy = funkcjaMieszajaca(map,klucz);
	int idWListy = znajdzIndeksKlucza(map->tab[idTablicy],klucz);
	


}

int odczytaj(Map* map, string klucz) {
	//Dokonaj implementacji funkcji. Do realizacji możesz skorzystać z funkcji funkcjaMieszajaca, znajdzIndeksKlucza oraz odczytajZListy	
}

int usun(Map* map, string klucz) {
	//Dokonaj implementacji funkcji. Do realizacji możesz skorzystać z funkcji funkcjaMieszajaca, znajdzIndeksKlucza oraz usunZListy	
}

int rozmiar(Map* map) {
	return map->numElements;
}

//=================================================================================================

void DictionaryTest() {
	cout << "Test slownik" << endl;
	int val, liczbaElementow;
	Map* map = newMap(5);

	liczbaElementow = rozmiar(map);
	cout << " Poczatkowa liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((liczbaElementow == 0) ? "OK" : "ERROR") << endl;

	wstaw(map, "a", 1);
	liczbaElementow = rozmiar(map);
	cout << "dodaje <a,1>" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((liczbaElementow == 1) ? "OK" : "ERROR") << endl;
	
	wstaw(map, "b", 2);
	liczbaElementow = rozmiar(map);
	cout << "dodaje <b,2>" << " liczba elementów: " << liczbaElementow ;
	cout << " Wynik: " << ((liczbaElementow == 2) ? "OK" : "ERROR") << endl;

	wstaw(map, "c", 3);
	liczbaElementow = rozmiar(map);
	cout << "dodaje <c,3>" << " liczba elementów: " << liczbaElementow ;
	cout << " Wynik: " << ((liczbaElementow == 3) ? "OK" : "ERROR") << endl;

	wstaw(map, "d", 4);
	liczbaElementow = rozmiar(map);
	cout << "dodaje <d,4>" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((liczbaElementow == 4) ? "OK" : "ERROR") << endl;
	
	val = odczytaj(map, "b");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <b," << val << ">" << " liczba elementów: " << liczbaElementow ;
	cout << " Wynik: " << ((val == 2) && (liczbaElementow == 4) ? "OK" : "ERROR") << endl;

	wstaw(map, "c", 5);
	liczbaElementow = rozmiar(map);
	cout << "Aktualizacja C =>, było <c,3> powinno byc <c,5>" << " liczba elementow: " << liczbaElementow;	
	cout << " Wynik: " << ((liczbaElementow == 4) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "c");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <c," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 5) && (liczbaElementow == 4) ? "OK" : "ERROR") << endl;

	wstaw(map, "e", 6);
	liczbaElementow = rozmiar(map);
	cout << "dodaje e <e,6>" << " liczba elementow: " << liczbaElementow;
	cout << " Wynik: " << ((liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	wstaw(map, "z", 7);
	liczbaElementow = rozmiar(map);
	cout << "dodaje e <z,7>" << " liczba elementow: " << liczbaElementow;
	cout << " Wynik: " << ((liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "a");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <a," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 1) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "b");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <b," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 2) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "c");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <c," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 5) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "d");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <d," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 4) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "e");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <e," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 6) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "z");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <z," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 7) && (liczbaElementow == 6) ? "OK" : "ERROR") << endl;
	cout << "Usun b" << endl;

	usun(map, "b");
	liczbaElementow = rozmiar(map);
	cout << "odczytuje element ktorego nie ma <b,X>" << " liczba elementów: " << liczbaElementow ;
	cout << " Wynik: " << ((liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "b");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <b," << val << ">" << " Powinno byc " << "NaN" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == NaN) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "a");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <a," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 1) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "c");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <c," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 5) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "d");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <d," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 4) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "e");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <e," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 6) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;

	val = odczytaj(map, "z");
	liczbaElementow = rozmiar(map);
	cout << "odczytalem <z," << val << ">" << " liczba elementów: " << liczbaElementow;
	cout << " Wynik: " << ((val == 7) && (liczbaElementow == 5) ? "OK" : "ERROR") << endl;	

	destroyMap(map);
}