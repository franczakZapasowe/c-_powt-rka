#include <iostream>
#include "Common.h"
#include "ListA.h"

using namespace std;

ListA* newAList() {
	ListA* list = new ListA;
	list->tabSize = 5;
	list->tab = new int[list->tabSize];
	list->counter = 0;
	return list;
}

void destroyAList(ListA* list) {
	if (list != nullptr) {
		delete[] list->tab;
		delete list;
	}
}

void resize(ListA* list) {
	//To jest funkcja pomocnicza, słuzaca do zmiany rozmiaru tablicy
	if (list != nullptr) {
		int rozmiar = list->tabSize *2;
		int *tab2 = new int[rozmiar];
		for (int i = 0; i < list->counter; i++) {
			tab2[i] = list->tab[i];
		}
		int counter2 = list->counter;
		delete [] list->tab;
		list -> tab = tab2;
		list->counter = counter2;
		list -> tabSize = rozmiar;
	}
}

void addToAList(ListA* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	if (list != nullptr) {
		// jesli licznik jest poza tablica -> resize
		if (list->counter == list->tabSize) {
			resize(list);
		}
			list->tab[list->counter] = value;
			list->counter++;
	}
}

int getFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	if (list != nullptr) {
		if (index >=0 && index < list->counter) {
			return list->tab[index];
		}else {
			return NaN;
		}
	}
}

int removeFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	if (list != nullptr) {
		if (index >= 0 && index < list->counter) {
			int usuniety = list->tab[index];
			int j = index + 1;
			for (; j < list->counter; j++) {
				list->tab[j-1] = list->tab[j];
			}
			list -> counter--;
			return usuniety;
		}
		return NaN;
	}
}

int sizeA(ListA* list) {
	return list->counter;
}

auto_ptr<IteratorA> getAIterator(ListA* list) {
	//Tutaj dokonaj implementacji funkcji
	if (list != nullptr) {
		auto_ptr<IteratorA> it(new IteratorA);
		it -> list = list;
		it ->counter = 0;
		return it;
	}
	return auto_ptr<IteratorA>(nullptr);

}

int iterateA(IteratorA* iterator) {
	//Tutaj dokonaj implementacji funkcji
	if (iterator != nullptr && iterator->list != nullptr) {
		if (iterator -> counter < iterator -> list->counter) {
			int val = iterator -> list->tab[iterator -> counter];
			iterator -> counter++;
			return val;
		}
	}
	return NaN;
}
