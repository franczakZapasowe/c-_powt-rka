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
	if (list!=NULL) {
		Element* element = newElement(value);
		if (list -> first == NULL) {
			list->first = element;
			list ->last = element;
			list->rozmiar++;
		}
		else {
			list->last->next = element;
			list->last = element;
			list->rozmiar++;
		}
	}
}

Element* search(ListP* list, int value) {
	//Tutaj dokonaj implementacji funkcji
	if (list!=nullptr) {
		Element* curr = list->first;
		while (curr != nullptr && curr->value != value) {
			curr = curr->next;
		}
		return curr;
	}
	return NULL;
}

int getFromPList(ListP* list, int index) {
	//Tutaj dokonaj implementacji funkcji
	if (list!=NULL) {
		if (index >=0 && index < list->rozmiar) {
			Element *curr = list -> first;
			for (int i = 0; i < index && curr!=nullptr; i++) {
				curr = curr->next;
			}
			return curr->value;
		}
	}
	return NaN;
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
			if (prev != NULL) { // Zabezpieczenie na wypadek, gdyby lista miała tylko 1 element
				prev->next = NULL;
			}
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
	if (list!=NULL) {
		IteratorP *iter = new IteratorP;
		iter->list = list;
		iter->curr = list->first;
		iter->counter = 0;

		return auto_ptr<IteratorP>(iter);
	}
	return auto_ptr<IteratorP>(NULL);

}

int iterateP(IteratorP* iterator) {
	int value = 0;
	//Tutaj dokonaj implementacji funkcji
	if (iterator!=NULL && iterator->curr != NULL) {
		value = iterator->curr->value;
		iterator->curr = iterator->curr->next;
		iterator->counter++;
		return value;
	}
	return NaN;
}
