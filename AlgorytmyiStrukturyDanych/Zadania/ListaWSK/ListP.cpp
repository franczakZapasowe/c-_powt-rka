#include <iostream>
#include "Common.h"
#include "ListP.h"

using namespace std;

Element* newElement(int value);

ListP* newPList() {
	ListP* list = new ListP;
	list->first = NULL;
	list->last = NULL;
	list->rozmiar = 0;
	return list;
}

void destroyPList(ListP* list) {
	if (list != NULL) {
		while (list->first != NULL) {
			Element* curr = list->first;
			if (list->first == list->last) list->first = NULL;
			else list->first = list->first->next;
			delete curr;
		}
		delete list;
	}
}

void addToPList(ListP* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	Element* element = newElement(value);
	if (list!=nullptr) {
		list->last -> next= element;
		list->rozmiar++;
	}else {
		list -> first = element;
		list->last = element;
		list->rozmiar++;
	}
}

Element* search(ListP* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	Element* curr = list->first;
	if (list!=nullptr) {
		while (curr->value != value) {
			curr = curr->next;
		}
	}
	return curr;
}

int getFromPList(ListP* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	Element *curr = list -> first;
	if (list!=nullptr) {
		for (int i = 1; i < index; i++) {
			curr = curr->next;
		}
	}
		return curr->value;
}

Element* newElement(int value) {
	Element* element = new Element;
	element->value = value;
	element->next = NULL;
	return element;
}

int removeFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	Element* prev = NULL;
	while (curr != NULL && i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	int value;
	if (curr == NULL) { //Będzie null jeśli lista jest pusta
		list->last = prev;
		value = NaN;
	}
	else { 
		if (prev != NULL) { //Sprawdzant czy to nie pierwszy element listy		
			prev->next = curr->next;			
		}
		else {
			list->first = curr->next;
		}		
		if (curr->next == NULL) { //Jak koniec kolejki
			list->last = prev;
		}
		value = curr->value;
		list->rozmiar--;
		delete curr;
	}
	return value;
}

int sizeP(ListP* list) {
	if (list!=NULL)
		return list->rozmiar;
	return NaN;
}

auto_ptr<IteratorP> getPIterator(ListP* list) {
	//Tutaj dokonaj implementacji funkcji
}

int iterateP(IteratorP* iterator) {
	//Tutaj dokonaj implementacji funkcji
}
