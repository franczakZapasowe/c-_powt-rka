#pragma once
#include <string>
#include <list>

struct Para { //Para elementów, która w rzeczywistości będzie przechowywana w mapie (tablicy asocjacyjnej)
	std::string klucz; //Klucz
	int wartosc; //Wartosc
};

Para* newPara(std::string klucz, int wartosc); //Stworzenie i zainicjowanie nowej pary
void destroyPara(Para* para); //Usunięcie danej pary.

struct Map {
	std::list<Para*>* tab; //Tablica list elementów 
	int tabSize; //Rozmiar tablicy
	int numElements; //Całkowita liczba rekordów w mapie
};

Map* newMap(int tabSize); //Stworzenie nowej mapy
void destroyMap(Map* map); //Usuniecie mapy i zwolnienie pamieci
int usun(Map* map, std::string klucz); //Usuniecie alementu ze slownika
int odczytaj(Map* map, std::string klucz); //Odczytanie wrtosci o okreslonym kluczu ze slownika
void wstaw(Map* map, std::string klucz, int wartosc); //Dodanie wartosci o okreslonym kluczu do slownika
bool znajdzKlucz(std::list<Para*> lista, std::string klucz); //Informuje czy w slowniku znajduje sie dany klucz

