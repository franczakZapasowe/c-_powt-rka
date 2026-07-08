#include <cstring>
#include <iostream>
#include <ctime>


#define WERSJA 3
#if(WERSJA == 1)

enum class TypFiltru {
    LowaPass = 0,
    HighaPass = 1,
    BandPass = 2
};

const char* const NAZWY_FILTRU[]={
    "LowaPass", "HighaPass", "BandPass"
};

using Czestotliowsc = double;
using PoziomDb = double;

struct ModelEq {
    TypFiltru typFiltru = TypFiltru::LowaPass;
    Czestotliowsc czestotliowsc = 0.0;
    PoziomDb poziomDb = 0.0;
};

struct KanalAudio {
    double *bufor = nullptr;
    ModelEq modelEq;
    const char nazwaSciezki[100];
};

std::ostream& operator<<(std::ostream&str, KanalAudio const&audio) {
    str << "Nazwa sciezki: "<<audio.nazwaSciezki<<"\ntyp filtru: "<<NAZWY_FILTRU[(int)audio.modelEq.typFiltru]
        <<"\nCzestotliwosc: "<<audio.modelEq.czestotliowsc<<"\nPoziom db: "<<audio.modelEq.poziomDb<<std::endl;
    return str;
}

int main() {
//     Kontekst: Projektujesz architekturę danych dla cyfrowego korektora (EQ) i kompresora w C++.
//     Musisz zgrupować parametry sygnału w twarde struktury, żeby uniknąć bałaganu w pamięci podczas przetwarzania buforów audio.
// Wymagania:
//     Utwórz enum class TypFiltru z wartościami: LowPass, HighPass, BandPass. Przypisz im ręcznie twarde klucze liczbowe (np. 1, 2, 3).
//     Użyj nowego standardu aliasów (z using), aby stworzyć typ Czestotliwosc (jako double) oraz PoziomDb (jako double).
//     Zbuduj strukturę ModulEQ. Ma zawierać pole z typem filtru oraz dwie zmienne nowo zdefiniowanych typów (Czestotliwosc i PoziomDb).
//     Zadbaj o inicjalizację pól wartościami domyślnymi.
//     Zbuduj strukturę główną KanalAudio. Ma zawierać: nazwę ścieżki (jako tablicę char),
//     surowy wskaźnik na bufor próbek (double*) oraz instancję składową ModulEQ (tzw. kompozycja – slajd 24).
//     Wyzwanie: Przeciąż operator << dla struktury KanalAudio, aby móc jedną instrukcją cout << mojKanal;
//     elegancko wypisać na ekranie nazwę ścieżki, typ przypiętego filtru (jako tekst, a nie liczbę!) i jego parametry.

    srand(time(0));
    double bufor[100];
    for (double & i : bufor) {
        i = rand() / (RAND_MAX + 1.0);
    }

    ModelEq modelEq;
    modelEq.typFiltru = TypFiltru::HighaPass;
    modelEq.czestotliowsc = 0.7;
    modelEq.poziomDb = 2.0;

    KanalAudio audio = {bufor, modelEq, "Pierwsza sciezka"};
    std::cout<<audio<<std::endl;
    return 0;
}
#endif

#if WERSJA == 2
struct Trader {
    int id;
    double kapital;
    bool aktywnosc;
};
struct Tranzakcja {
    const Trader* kupujacy;
    const Trader* sprzedajacy;
    double wolumen = 0;
};

bool operator>(Tranzakcja const &tranzakcja1, Tranzakcja const &tranzakcja2) {
    if (tranzakcja1.wolumen > tranzakcja2.wolumen) {
        return true;
    }
    return false;
}
Tranzakcja operator +(Tranzakcja const &tranzakcja1, Tranzakcja const &tranzakcja2) {
    Tranzakcja nowaTranzkacja = {tranzakcja1.kupujacy, tranzakcja2.sprzedajacy, tranzakcja1.wolumen+tranzakcja2.wolumen};
    return nowaTranzkacja;
}
int main() {

//     Kontekst: Piszesz niskopoziomowy moduł pamięci dla bota giełdowego. Bot musi błyskawicznie analizować transakcje między różnymi traderami na rynku.
//     Kopiowanie danych traderów przy każdej transakcji zabiłoby wydajność, więc musisz użyć asocjacji wskaźnikowej.
// Wymagania:
//     Zbuduj strukturę Trader (pola: ID, kapitał, status aktywności).
//     Zbuduj strukturę Transakcja. Zamiast kopiować dane traderów, musi ona zawierać dwa bezpieczne pola wskaźnikowe (asocjacja – slajd 25):
//     stały wskaźnik na kupującego (const Trader* kupujacy) i stały wskaźnik na sprzedającego (const Trader* sprzedajacy), oraz wartość transakcji (double wolumen).
//     Przeciążanie (Slajd 29): Przeciąż operator > dla dwóch instrukcji typu Transakcja, tak aby zwracał true,
//     jeśli wolumen pierwszej transakcji jest większy od drugiej.
//     Logika wskaźnikowa: Przeciąż operator + dla struktur Transakcja. Wynikiem dodawania T1 + T2 ma być zwrócenie przez wartość nowej Transakcji, w której:
//         Wolumen to suma wolumenów T1 i T2.
//         Kupującym zostaje kupujący z T1.
//         Sprzedającym zostaje sprzedający z T2.
//     W main utwórz trzech traderów, zbuduj z nich dwie transakcje (przez podanie adresów &), zsumuj je operatorem + do trzeciej i \
//     wypisz adresy pamięci traderów, żeby udowodnić, że nie sklonowałeś ludzi, tylko przepiłeś wskaźniki.
    Trader t1 = {1, 100, true};
    Trader t2 = {2, 200, true};
    Trader t3 = {3, 300, true};

    std::cout<<"Adresy traderow przed tranzakcja:\n";
    std::cout<<"Trader 1 adres: "<<&t1<<std::endl;
    std::cout<<"Trader 2 adres: "<<&t2<<std::endl;
    std::cout<<"Trader 3 adres: "<<&t3<<std::endl;

    Tranzakcja tranzakcja1 ={&t1,&t2,150};
    Tranzakcja tranzakcja2 ={&t2,&t3,350};
    Tranzakcja tranzanzakcja3;
    std::cout<<"Wartosc tranzakcji przed dodaniem: "<<tranzanzakcja3.wolumen<<std::endl;
    tranzanzakcja3 = tranzakcja1 + tranzakcja2;
    std::cout<<"Wartosc tranzakcji po dodaniu: "<<tranzanzakcja3.wolumen<<std::endl;
    std::cout<<"Trder 3 adres (sprawdzany przez tranzakcje3): "<<tranzanzakcja3.kupujacy<<std::endl;
    std::cout<<"Trder 3 adres (sprawdzany przez tranzakcje3): "<<tranzanzakcja3.sprzedajacy<<std::endl;
}
#endif

#if WERSJA == 3

struct Uzytkownik {
    int klucz_publiczny;
};
struct Pakiet {
    const Uzytkownik* nadawca;
    const Uzytkownik* odbiorca;
    char tresc[200];
};
Pakiet utworzPoziomZaufany(const Uzytkownik &nad, const Uzytkownik &odb, const char* wiadomosc) {
    Pakiet nowypakiet = {&nad,&odb};
    strcpy(nowypakiet.tresc, wiadomosc);
    return nowypakiet;
}
void wypisz(Pakiet const *pakiety, int rozmiar) {
    for (int i=0; i<rozmiar; i++) {
        std::cout<<"Klucz: "<<pakiety[i].nadawca->klucz_publiczny
        <<" Wysyla do: "<<pakiety[i].odbiorca->klucz_publiczny
        <<" "<<pakiety[i].tresc<<std::endl;
    }
}
int main() {

//     Kontekst: Zarządzasz dziennikiem zaszyfrowanych pakietów w architekturze P2P.
//     Musisz napisać system, który generuje logi komunikacji,
//     działając na tablicy struktur.
// Wymagania:
//     Stwórz strukturę Uzytkownik (pole: klucz publiczny / nazwa).
//     Stwórz strukturę Pakiet reprezentującą wiadomość. Ma zawierać wskaźnik na nadawcę (Uzytkownik* nadawca),
//     wskaźnik na odbiorcę (Uzytkownik* odbiorca) i samą treść.
//     W main stwórz dwóch użytkowników i tablicę na 5 Pakietów (tablica struktur – slajd 28).
//     Wyzwanie architektoniczne:
//     Napisz potężną funkcję (poza main), która ma następującą sygnaturę:
//     Pakiet utworzPoziomZaufany(const Uzytkownik &nad, const Uzytkownik &odb, const char* wiadomosc);
//     Zwróć uwagę, że funkcja ma utworzyć lokalnie nową strukturę Pakiet, przypiąć jej adresy (konwertując z referencji na wskaźnik!) i
//     zwrócić całą strukturę przez wartość prosto do tablicy (podobnie jak na slajdzie 27 z umowWizyte).
//     Użyj tej funkcji do wygenerowania 3 pakietów i wstawienia ich do tablicy w main. Następnie napisz drugą funkcję iterującą
//     pętlą for po tej tablicy (wymaga przesłania tablicy struktur i jej rozmiaru), która wypisze za pomocą operatora -> logi w formacie:
//     "Klucz A wysłał do Klucz B: [treść]".

    Uzytkownik u1 = {123};
    Uzytkownik u2 = {313};
    Pakiet p1 = utworzPoziomZaufany(u1,u2,"ADA");
    Pakiet p2 = utworzPoziomZaufany(u1,u2,"ADA");
    Pakiet p3 = utworzPoziomZaufany(u1,u2,"ADA");
    Pakiet pakiety[5] = {p1,p2,p3};
    wypisz(pakiety,3);
}
#endif