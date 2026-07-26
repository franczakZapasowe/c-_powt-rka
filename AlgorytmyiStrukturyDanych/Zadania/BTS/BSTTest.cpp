#include <iostream>
#include "Common.h"
#include "BST.h"

using namespace std;

void BSTTest() {
	cout << "Test drzewo BST" << endl;
	//Stworzenie drzzewa składającego się z elementów
	int tab[] = { 7, 15, 5, 1, 9, 10, 2, 6, 20 };
	Drzewo* drzewo = newDrzewo(); //Zainicjowanie drzewa
	for (int i : tab)
	{
		wstaw(drzewo, i); //Dodawanie do drzewa kolejnych węzłów
	}
	wyswietl(drzewo); //Wypisanie drzewa na ekranie

	//Sprawdzenie kolejnych metod drzewa - do wykonania manualnego prez studenta 
	cout << "Odnajdywanie" << endl;
	cout << "-------Odnajdywanie wartosci 8, nie wystepuje-------" << endl;
	cout << "Czy jest 8: " << czyJest(drzewo, 8) << endl; 
	cout << "-------Odnajdywanie wartosci 6, obecna na liscie-------" << endl;
	cout << "Czy jest 6: " << czyJest(drzewo, 6) << endl;
	cout << "-------Minimum drzewa-------" << endl;
	cout << minimum(drzewo) << endl;
	cout << "-------Nastepnik wartosci 6 to 7-------" << endl;
	cout << nastepnik(drzewo,6) << endl;
	int doUsuniecia = 7;
	cout << "-------Usuwanie " << doUsuniecia << "-------" << endl;
	cout << "Usunalem: " << usun(drzewo, doUsuniecia) << endl;
	cout << "-------Drzewo po usunieciu-------" << endl;
	wyswietl(drzewo);
	cout << "Następnik 6 to 9: " << (nastepnik(drzewo, 6) == 9 ? "Ok" : "!!!Blad!!!") << endl;
	doUsuniecia = 9;
	cout << "-------Usuwanie " << doUsuniecia << "-------" << endl;
	cout << "Usunalem: " << usun(drzewo, doUsuniecia) << endl;
	cout << "-------Drzewo po usunieciu-------" << endl;
	wyswietl(drzewo);
	cout << "Następnik 6 to 10: " << (nastepnik(drzewo, 6) == 10 ? "Ok" : "!!!Blad!!!") << endl;
	doUsuniecia = 5;
	cout << "-------Usuwanie " << doUsuniecia << "-------" << endl;
	cout << "Usunalem: " << usun(drzewo, doUsuniecia) << endl;
	cout << "-------Drzewo po usunieciu-------" << endl;
	wyswietl(drzewo);
	cout << "Następnik 6 to 10: " << (nastepnik(drzewo, 6) == 10 ? "Ok" : "!!!Blad!!!") << endl;
	doUsuniecia = 1;
	cout << "-------Usuwanie " << doUsuniecia << "-------" << endl;
	cout << "Usunalem: " << usun(drzewo, doUsuniecia) << endl;
	cout << "-------Drzewo po usunieciu-------" << endl;
	wyswietl(drzewo);
	cout << "Następnik 6 to 10: " << (nastepnik(drzewo, 6) == 10 ? "Ok" : "!!!Blad!!!") << endl;
	doUsuniecia = 2;
	cout << "-------Usuwanie " << doUsuniecia << "-------" << endl;
	cout << "Usunalem: " << usun(drzewo, doUsuniecia) << endl;
	cout << "-------Drzewo po usunieciu-------" << endl;
	wyswietl(drzewo);
	cout << "Następnik 6 to 10: " << (nastepnik(drzewo, 6) == 10 ? "Ok" : "!!!Blad!!!") << endl;
}