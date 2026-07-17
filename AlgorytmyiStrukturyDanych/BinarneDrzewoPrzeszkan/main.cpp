#include <iostream>

struct Wezel{
    int wartosc;
    Wezel *lewy = nullptr;
    Wezel *prawy = nullptr;
};

void wypisz(Wezel *wezel) {
    if (wezel != nullptr) {
        wypisz(wezel->lewy);
        std::cout << wezel->wartosc << " ";
        wypisz(wezel->prawy);
    }
}
bool search(Wezel *wezel, int x) {
    if (wezel == nullptr) return false;
    if (wezel->wartosc == x) return true;

    if (x < wezel->wartosc) return search(wezel->lewy, x);
    if (x> wezel->wartosc) return search(wezel->prawy, x);
    return false;
}

void insert(Wezel *&wezel, int x) {
    if (wezel == nullptr) {
        wezel = new Wezel;
        wezel->wartosc = x;
        wezel->lewy = nullptr;
        wezel->prawy = nullptr;
    }else if (x < wezel->wartosc) {
        insert(wezel->lewy, x);
    }else if (x > wezel->wartosc) {
        insert(wezel->prawy, x);
    }
}

void usun(Wezel *&wezel, int x) {
    if (wezel == nullptr) return;
    if (x < wezel->wartosc) {
        usun(wezel->lewy, x);
    }
    else if (x > wezel->wartosc) {
        usun(wezel->prawy, x);
    }
    else {
        //przypadek gdy wezel nie ma dzieci
        if (wezel->lewy == nullptr && wezel->prawy == nullptr) {
            delete wezel;
            wezel = nullptr;
        }
        //przypadek gdy tylko 1 dziecko (prawe)
        else if (wezel->lewy == nullptr && wezel->prawy != nullptr) {
            Wezel *doUsunieca = wezel;
            wezel = wezel->prawy;
            delete doUsunieca;
        }
        //przypadek gdy tylko 1 dziecko (lewe)
        else if (wezel->lewy != nullptr && wezel->prawy == nullptr) {
            Wezel *doUsuniecia = wezel;
            wezel = wezel->lewy;
            delete doUsuniecia;
        }
        //przypadek z 2 dzieci
        else  {
         Wezel *nastepnik = wezel ->prawy;
            while (nastepnik->lewy != nullptr) {
                nastepnik = nastepnik->lewy;
            }
            wezel ->wartosc = nastepnik->wartosc;
            usun(wezel->prawy, nastepnik->wartosc);
        }
    }
}

int main() {

    Wezel *korzen = nullptr;
    std::cout<<"Budowa drzewa: \n";

    insert(korzen, 50); // Korzen
    insert(korzen, 30); // Lewe poddrzewo
    insert(korzen, 70); // Prawe poddrzewo
    insert(korzen, 20); // Lisc po lewej
    insert(korzen, 40); // Ma tylko jedno dziecko
    insert(korzen, 45); // Dziecko wezla 40
    insert(korzen, 60); // Lisc po prawej
    insert(korzen, 80); // Lisc po prawej

    std::cout << "Zawartosc drzewa (rosnaco): ";
    wypisz(korzen);
    std::cout << "\n\n";

    std::cout << "--- TEST WYSZUKIWANIA ---\n";
    std::cout << "Czy jest liczba 45? " << (search(korzen, 45) ? "TAK" : "NIE") << "\n";
    std::cout << "Czy jest liczba 99? " << (search(korzen, 99) ? "TAK" : "NIE") << "\n\n";

    std::cout << "--- TESTY USUWANIA ---\n";

    // Test Przypadku 1 (Usuwanie liscia)
    std::cout << "Usuwam 20 (lisc)...\n";
    usun(korzen, 20);
    std::cout << "Drzewo po usunieciu: ";
    wypisz(korzen);
    std::cout << "\n\n";

    // Test Przypadku 2 (Usuwanie z jednym dzieckiem)
    std::cout << "Usuwam 40 (ma jedno dziecko - 45)...\n";
    usun(korzen, 40);
    std::cout << "Drzewo po usunieciu: ";
    wypisz(korzen);
    std::cout << "\n\n";

    // Test Przypadku 3 (Usuwanie z dwojgiem dzieci)
    std::cout << "Usuwam 50 (korzen, ma dwoje dzieci)...\n";
    usun(korzen, 50);
    std::cout << "Drzewo po usunieciu (nastepnik 60 powinien wejsc na szczyt): ";
    wypisz(korzen);
    std::cout << "\n\n";

    std::cout << "Wszystkie testy zaliczone. Dobra robota, inzynierze!\n";

    return 0;
}