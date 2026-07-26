#pragma once

struct Node { //Pojedynczy węzeł drzewa
	Node* lewy;
	Node* prawy;
	Node* ojciec;
	int wartosc;
};

struct Drzewo { //Struktura opisująca drzewo
	Node* korzen; //Korzeń drzewa
};

Drzewo* newDrzewo(); //Stworzenie nowego drzewa

void  destroyDrzewo(Drzewo* drzewo); //Zniszczenie drzewa

void wstaw(Drzewo* drzewo, int wartosc); //Dodanie wartości do drzewa

int minimum(Drzewo* drzewo); //Znalezienie najmniejszej wartości

int nastepnik(Drzewo* drzewo, int wartosc); //Znalezienie następnika dla podanej wartości

bool czyJest(Drzewo* drzewo, int wartosc); //Sprawdzenie czy w drzewie jest poszukiwany element

int usun(Drzewo* drzewo, int wartosc); //Usunięcie określonego elementu z drzewa

void wyswietl(Drzewo* drzewo); //Wypisanie drzewa na ekranie

