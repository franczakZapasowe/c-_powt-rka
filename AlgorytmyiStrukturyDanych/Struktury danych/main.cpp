#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#define TOERIA
#ifdef TOERIA
// -------------------------- LISTA JEDNOKIERUNKOWA ----------------------
struct WezelJednokierunkowy {
    int wartosc;
    WezelJednokierunkowy * nastepny; //wskaznik na kolejny element
};

void wyswietlListe(WezelJednokierunkowy * glowa) {
    WezelJednokierunkowy * biezacy = glowa;
    while (biezacy != nullptr) {
        std::cout << biezacy->wartosc <<" -> ";
        biezacy = biezacy->nastepny; // skaczemy do kolejnego wezla
    }
    std::cout<<"nulptr\n";
}

// 1. BUDOWA WĘZŁA
struct WezelDrzewa {
    int wartosc;
    WezelDrzewa * lewy;
    WezelDrzewa * prawy;

    WezelDrzewa(int val) {
        wartosc = val;
        lewy = nullptr;
        prawy = nullptr;
    }
};

// 2. WSTAWIANIE REKURENCYJNE (Zasada BST: mniejsze na lewo, większe na prawo)
// Przekazujemy wskaźnik przez referencję (*&), żeby móc go fizycznie zmienić!

void wstaw(WezelDrzewa *&korzen, int nowaWartosc) {
    if (korzen==nullptr) {
        korzen = new WezelDrzewa(nowaWartosc);
        return;
    }

    //jezeli wartosc jest mniejsza to na lewo
    if (nowaWartosc< korzen->wartosc) {
        wstaw(korzen->prawy, nowaWartosc);
    }
    else if (nowaWartosc> korzen->wartosc) {
        wstaw(korzen->prawy,nowaWartosc);
    }
}

// 3. WYPISYWANIE IN-ORDER (Lewy -> Korzeń -> Prawy)
// Ten rodzaj przejścia GWARANTUJE wypisanie liczb od najmniejszej do największej.
void wypiszInOrder(WezelDrzewa*korzen) {
    if (korzen!=nullptr) {
        wypiszInOrder(korzen->lewy);
        std::cout<<korzen->wartosc<<" ";
        wypiszInOrder(korzen->prawy);
    }
}

// 4. CZYSZCZENIE PAMIĘCI (Post-order: Lewy -> Prawy -> Korzeń)
// Nie możesz zniszczyć korzenia, dopóki nie zniszczysz jego dzieci!
void usunDrzewo(WezelDrzewa*korzen) {
    if (korzen!=nullptr) {
        usunDrzewo(korzen->lewy);
        usunDrzewo(korzen->prawy);
        delete korzen;
    }
}

int main() {
    // -------------------------- LISTA JEDNOKIERUNKOWA ----------------------
    WezelJednokierunkowy * pierwszy = new WezelJednokierunkowy(10,nullptr);
    WezelJednokierunkowy * drugi = new WezelJednokierunkowy(20,nullptr);
    WezelJednokierunkowy * trzxeci = new WezelJednokierunkowy(30,nullptr);

    pierwszy->nastepny = drugi;
    drugi ->nastepny = trzxeci;
    std::cout<<"Lista jednokierunkowa:\n";
    wyswietlListe(pierwszy);
    delete pierwszy;
    delete drugi;
    delete trzxeci;
    std::cout<<"\n\n\n";

    // ----------------------------LISTA DWUKIERUNKOWA -------------------------------
    std::list<int> mojaLista;
    mojaLista.push_back(1);
    mojaLista.push_back(2);
    mojaLista.push_back(3);

    std::cout<<"Lista dwukierunkowa\n";
    std::list<int>::iterator it;
    for (it = mojaLista.begin(); it != mojaLista.end(); ++it) {
        std::cout<<*it<<"  ";
    }

    // operacje na iteratorze
    it = mojaLista.begin();
    ++it;

    //wstawi element przed atualna pozycje iteratora
    mojaLista.insert(it, 6);
    std::cout<<"\nPo wstawieniu 6:\n";
    for (it = mojaLista.begin(); it != mojaLista.end(); ++it) {
        std::cout<<*it<<"  ";
    }

    //usuwanie elementu
    it = mojaLista.begin();
    ++it;
    ++it;
    mojaLista.erase(it);

    std::cout << "\nPo usunieciu: ";
    for (it = mojaLista.begin(); it != mojaLista.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";


    //---------------------------------LISTA TABLICOWA
    std::cout<<"VECTOR\n";
    std::vector<int>magazyn;
    std::cout<<"Poczatek - rozmiar: "<<magazyn.size()
            <<", Pojemnosc: "<<magazyn.capacity()<<"\n\n";

    std::cout<<"Dodawanie elementow:\n";
    for (int i = 1; i<=5; i++) {
        magazyn.push_back(i*10);
        std::cout << "Wstawiono " << i * 10
                  << " | Rozmiar: " << magazyn.size()
                  << " | Pojemnosc: " << magazyn.capacity() << "\n";
    }
    std::cout << "\n";
    std::cout<<"Odczyt elementu: "<<magazyn[2]<<std::endl;
    std::cout<<"Bezpieczny odczy: "<<magazyn.at(2)<<std::endl;

    std::cout<<"Wypisywanie calosci jak zwykla tablica:\n";
    for (int i = 0; i<magazyn.size(); ++i) {
        std::cout<<magazyn[i]<<" ";
    }
    std::cout<<"\n";

    //wstawienie w srodek
    magazyn.insert(magazyn.begin()+1, 99);
    std::cout << "Po wstawieniu w srodek: ";
    for (int i = 0; i < magazyn.size(); ++i) {
        std::cout << magazyn[i] << " ";
    }
    std::cout << "\n\n";

    //usuwanie lementu:
    magazyn.erase(magazyn.begin()+1);
    std::cout << "Po usuwaniu w srodek: ";
    for (int i = 0; i < magazyn.size(); ++i) {
        std::cout << magazyn[i] << " ";
    }
    std::cout << "\n\n";
    magazyn.pop_back();
    for (int i = 0; i < magazyn.size(); ++i) {
        std::cout << magazyn[i] << " ";
    }

    // lepiej rezerowac pamiec jezeli wiemy ile bedzie elementow
    std::vector<int>magazyn2;
    magazyn2.reserve(100);
    std::cout<<"\nPrzy rezerowaniu: "<<magazyn2.capacity();


    //--------------------------STOS-------------------------------
    std::stack<int>stos;
    stos.push(1);
    stos.push(2);
    stos.push(3);
    // teraz 3 na samej gorze
    std::cout<<"\n\nOperacje na stsie:\n";
    std::cout<<"Rozmiar: "<<stos.size()<<std::endl;

    // po stosie nie mozna iterowac petla for
    // mozna patrzec tylko na to co jest na samej gorze
    std::cout<<"Pdczyt elementow:\n";
    while (!stos.empty()) {
        int gora = stos.top();
        std::cout<<"Na samej gorze: "<<gora<<std::endl;
        stos.pop();
    }

    //-----------------------------KOLEJKA
    std::queue<int>kolejka;
    kolejka.push(1); // 1 element
    kolejka.push(2); // 2 element
    kolejka.push(3); // 3 element

    std::cout << "--- OPERACJE NA KOLEJCE (FIFO) ---\n";
    std::cout << "Rozmiar kolejki: " << kolejka.size() << "\n";

    while (!kolejka.empty()) {
        int pierwszy = kolejka.front();
        int ostatni = kolejka.back();
        std::cout<<"Pierwszy: "<<pierwszy<<" ostatni: "<<ostatni<<std::endl;
        kolejka.pop();
    }

    //-----------------------------TABLICA ASOCJACYJNA
    std::cout<<"\nTABLICA ASOCJACYJNA:\n";
    // typ klucza, wartosc
    std::unordered_map<std::string,double>cennik;

    cennik["Kawa"] = 15.50;
    cennik["Herbata"]= 12.00;
    cennik["Ciasto"]= 9.99;

    cennik.insert({"Woda",5.00});
    std::cout<<"Rozmiar: "<<cennik.size()<<std::endl;
    //odczyt elementu
    std::cout<<"Cena kwy to: "<<cennik["Kawa"]<<" PLN"<<std::endl;

    // WYSZUKIWANIE (Czy klucz istnieje?)
    // Używamy metody .find(), która zwraca iterator.
    // Jeśli nie znajdzie klucza, zwróci iterator wskazujący na .end()
    std::string szukanyProdukt = "Kanapka";

    if (cennik.find(szukanyProdukt) != cennik.end()) {
        std::cout << "Znaleziono! " << szukanyProdukt << " kosztuje " << cennik[szukanyProdukt] << " PLN\n";
    }else {
        std::cout << "Brak produktu: " << szukanyProdukt << " w systemie.\n";
    }

    //usuwanie elementow
    cennik.erase("Herbata");
    std::cout<<"Wypisanie elementow:\n";
    for (auto it = cennik.begin(); it!=cennik.end(); ++it) {
        std::cout<<"- "<<it->first<<" "<<it->second<<std::endl;
    }

    //-------------------------------set
    std::set<int>unikalneLiczby;

    unikalneLiczby.insert(50);
    unikalneLiczby.insert(10);
    unikalneLiczby.insert(90);
    unikalneLiczby.insert(10); // Próba dodania duplikatu! Zostanie zignorowana.
    unikalneLiczby.insert(30);

    std::cout << "--- ZBIOR (std::set) ---\n";
    std::cout << "Rozmiar zbioru (powinno byc 4, bo odrzucilo duplikat): "
              << unikalneLiczby.size() << "\n\n";

    std::cout << "Elementy w zbiorze (magicznie posortowane): ";
    for (auto it = unikalneLiczby.begin(); it != unikalneLiczby.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    int szukana = 30;
    // Metoda .count() zwraca 1 (jeśli istnieje) lub 0 (jeśli nie), bo to zbiór unikalny!
    if (unikalneLiczby.count(szukana) == 1) {
        std::cout << "Znaleziono liczbe " << szukana << " w zbiorze!\n";
    }

    // Albo uzywajac iteratora i funkcji find():
    if (unikalneLiczby.find(99) == unikalneLiczby.end()) {
        std::cout << "Liczby 99 nie ma w zbiorze.\n";
    }

    // 4. USUWANIE
    unikalneLiczby.erase(50);
    std::cout << "Usunieto liczbe 50.\n";


    //------------------------------map
    std::map<std::string,int>wynikiEgzaminu;
    wynikiEgzaminu["Zelent"] = 95;
    wynikiEgzaminu["Adamczyk"] = 70;
    wynikiEgzaminu["Nowak"] = 88;

    // Nadpisanie wyniku (Nowak poprawił egzamin)
    wynikiEgzaminu["Nowak"] = 100;

    std::cout << "--- MAPA (std::map) ---\n";
    // ODCZYT KONKRETNEGO KLUCZA
    std::cout << "Wynik Zelenta to: " << wynikiEgzaminu["Zelent"] << " pkt\n\n";


    // WYSZUKIWANIE BEZPIECZNE (Żeby nie dodać przypadkiem pustego klucza)
    std::string poszukiwany = "Kowalski";
    if (wynikiEgzaminu.find(poszukiwany) != wynikiEgzaminu.end()) {
        std::cout << "Wynik Kowalskiego: " << wynikiEgzaminu[poszukiwany] << "\n";
    } else {
        std::cout << poszukiwany << " nie pisal egzaminu.\n\n";
    }

    std::cout<<"Lista wynikow egzaminu:\n";
    for (auto it = wynikiEgzaminu.begin(); it != wynikiEgzaminu.end(); ++it) {
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    return 0;

    //-------------------------drzewo
    WezelDrzewa *glowneDrzewo = nullptr;
    std::cout << "Buduje Binarne Drzewo Poszukiwan (BST)...\n";
    wstaw(glowneDrzewo, 50); // To staje się głównym korzeniem
    wstaw(glowneDrzewo, 30);
    wstaw(glowneDrzewo, 70);
    wstaw(glowneDrzewo, 20);
    wstaw(glowneDrzewo, 40);
    wstaw(glowneDrzewo, 60);
    wstaw(glowneDrzewo, 80);
    std::cout << "\nWypisywanie In-Order (powinno byc posortowane rosnaco):\n";
    wypiszInOrder(glowneDrzewo);
    std::cout << "\n";

    // Pamiętaj o zwolnieniu pamięci na koniec programu!
    usunDrzewo(glowneDrzewo);


}


#else

//implementacja kolejki za pomoca vector
void menu() {
    std::cout<<"Wybierz co chcesz zroibc na kolejce:\n";
    std::cout<<"1 - dodanie elementu\n";
    std::cout<<"2 - usuniecie elementu\n";
    std::cout<<"3 - wypisanie wszystkich elementu\n";
    std::cout<<"4 - Zamknij program4\n";
    std::cout<<"Wybor: ";
}

void dodawanieELementu(std::vector<int>& mojaLista) {
    int n;
    std::cout<<"Podaj wartosc jaka chcesz dodac: ";
    std::cin>>n;
    mojaLista.push_back(n);
}
void usuwanieElementu(std::vector<int>& mojaLista) {
    if (!mojaLista.empty()) {
        mojaLista.erase(mojaLista.begin());
    }else {
        std::cout<<"Kolejka jest pusta\n";
    }

}
void wypisanieElementu(const std::vector<int>& mojaLista) {
    if (!mojaLista.empty()) {
        for (int i = 0; i < mojaLista.size(); ++i) {
            std::cout<<mojaLista[i]<<" ";
        }
    }else {
        std::cout<<"Kolejka jest pusta";
    }
    std::cout<<"\n";
}

int main() {

    std::vector<int>kolejka;
    int operacja;

    while (operacja!=4) {
        menu();
        std::cin>>operacja;

        switch (operacja) {
            case 1: dodawanieELementu(kolejka);
                break;
            case 2: usuwanieElementu(kolejka);
                break;
            case 3: wypisanieElementu(kolejka);
                break;
            case 4: break;
            default: menu();
        }
        if (operacja!=4) {
            std::cout<<"\nWcisnij Enter, aby kontynuwac...";
            std::cin.ignore(1000,'\n');
            std::cin.get();
            std::system("clear");
        }
    }

    return 0;
}


#endif
