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
}

void addToAList(ListA* list, int value) {
	//Tutaj dokonaj implementacji funkcji
}

int getFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
}

int removeFromAList(ListA* list, int index) {
	//Tutaj dokonaj implementacji funkcji
}

int sizeA(ListA* list) {
	return list->counter;
}

auto_ptr<IteratorA> getAIterator(ListA* list) {
	//Tutaj dokonaj implementacji funkcji
}

int iterateA(IteratorA* iterator) {
	//Tutaj dokonaj implementacji funkcji
}
