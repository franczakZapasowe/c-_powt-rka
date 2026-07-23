#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype> 
#define ZADANIE 3

#if(ZADANIE == 1)

bool aplikujLimiter(double*tab, int rozmiar, double threshold, int&ile){
    bool czyCzyste = false;    
    for (int i = 0; i<rozmiar; i++){
            if (tab[i] > threshold ){
            ile++;
            tab[i] = threshold;
            czyCzyste = true;
        } else if (tab[i] < threshold * -1.0){
            ile++;
            tab[i] = threshold * -1.0;
            czyCzyste = true;
        }
    }
    return czyCzyste;
}

void wypisz(double *tab, int n){
    for(int i = 0; i<n; i++)
    {
        std::cout<<"Pomiar nr. "<<i<<" : "<<tab[i]<<"\n";
    }
}

int main(){
    // Zadanie 1: Twardy Limiter Sygnału (Operacje w miejscu i wielokrotny zwrot)
    // Kontekst: Pisząc wtyczki audio (np. kompresory) w C++, musisz przetwarzać
    // tablice próbek dźwiękowych w czasie rzeczywistym. Funkcja musi modyfikować bufor 
    // i jednocześnie raportować kilka parametrów do interfejsu użytkownika.
    // Wymagania:
    // Stwórz funkcję aplikujLimiter. 
    // Funkcja ma zwracać typ bool (zwraca true, jeśli sygnał wymagał 
    // jakiejkolwiek interwencji limitera,
    //      false jeśli sygnał był wystarczająco cichy i czysty).
    // Funkcja przyjmuje cztery argumenty:
    //     Wskaźnik na surową tablicę double (bufor próbek audio).
    //     Rozmiar bufora (int).
    //     Wartość progową, tzw. Threshold (typu double, np. 0.8).
    //     Zmienną typu int przekazywaną przez referencję (do zliczania, 
    //         ile dokładnie próbek zostało przyciętych).
    // Działanie: 
    // Funkcja przechodzi przez bufor. Jeśli wartość bezwzględna próbki przekracza Threshold 
    // (czyli jest większa niż 0.8 lub mniejsza niż -0.8), 
    // ma ją brutalnie "uciąć" do wartości progowej 
    // (odpowiednio 0.8 lub -0.8). Równocześnie ma inkrementować licznik przyciętych próbek, 
    // który dostała przez referencję.
    // Przetestuj to w funkcji głównej na wymyślonej tablicy i wydrukuj po wywołaniu 
    // zmodyfikowany bufor oraz statystyki.
    srand(time(0));
    bool isClean = false;
    constexpr int ROZMIAR = 10;
    double threshold = 0.8;
    int ile = 0;
    double tab[ROZMIAR]={};
    for(int i = 0; i< ROZMIAR; i++){
        tab[i] = ((double)rand() / RAND_MAX) * 2.7 - 1.4;
    }
    std::cout<<"Wartosci sygnalu:\n";
    wypisz(tab,ROZMIAR);
    std::cout<<"\nWartosc po trehsold:\n";
    isClean = aplikujLimiter(tab,ROZMIAR,threshold,ile);
    wypisz(tab,ROZMIAR);
    std::cout<<"\nIlosc sygnalow: "<<ile<<"\n";
    std::cout<<"Czy limiter byl uzyty: "<<isClean<<"\n";

    return 0;
}
#endif

   


#if(ZADANIE == 2)

 double znajdzNajlepszaSerie(const double tab[],int rozmiar, int &dlugoscSeri, const double* &wsk){
        double rekord_suma = 0;
        int aktualna_dlugosc = 0;
        double suma = 0;

        for (int i = 0; i < rozmiar; i++){
            if (tab[i]>0){
                aktualna_dlugosc += 1; // zwikszamy wartosc dlugosci seri
                suma+=tab[i];  // zwiekszamy sume
            }else{
               if((aktualna_dlugosc > dlugoscSeri) || (aktualna_dlugosc == dlugoscSeri && rekord_suma < suma)){
                    wsk = & tab[i - aktualna_dlugosc];
                    dlugoscSeri = aktualna_dlugosc;
                    rekord_suma = suma;
               }
                suma = 0;
                aktualna_dlugosc = 0;
            }
        }
        if((aktualna_dlugosc > dlugoscSeri) || (aktualna_dlugosc == dlugoscSeri && rekord_suma < suma)){
                wsk = & tab[rozmiar- aktualna_dlugosc];
                    dlugoscSeri = aktualna_dlugosc;
                    rekord_suma = suma;
               }

        return rekord_suma;
    }
int main(){
//     Kontekst: Analizujesz historię transakcji z bota tradingowego. Masz potężną tablicę zysków i strat (P&L). 
//     Musisz znaleźć najdłuższy, nieprzerwany ciąg zyskownych transakcji (tzw. Winning Streak).
// Wymagania:
//     Stwórz funkcję znajdzNajlepszaSerie. Funkcja ma zwracać przez return wartość double (sumę wygenerowanego profitu z tego najlepszego ciągu).
//     Funkcja przyjmuje cztery argumenty:
//     Tablicę double z historią sald. Musi być absolutnie zabezpieczona słowem kluczowym const, 
//     aby algorytm analityczny przypadkowo nie sfałszował danych finansowych.
//     Rozmiar tablicy (int).
//     Dwa wskaźniki przekazane do funkcji, które posłużą jako "pojemniki" na wyniki: int* dlugoscSerii oraz wskaźnik na wskaźnik 
//     (lub referencję do wskaźnika), pod którym funkcja zapisze adres w pamięci, gdzie ten najlepszy ciąg się fizycznie zaczyna w tablicy.
//     Działanie: Funkcja ma przeanalizować dane, znaleźć najdłuższy nieprzerwany ciąg liczb większych od zera. 
//     Jeśli znajdzie remis w długości, bierze ten o większym zysku całkowitym.
//     Wynikiem działania funkcji jest wpisanie do argumentów wskaźnikowych odpowiedniej długości i adresu startowego, 
//     a z samej funkcji wyplucie (przez return) sumy zysku z tej serii.
    srand(time(0));
    constexpr int ROZMIAR = 15;
    const double tab[ROZMIAR] = {
    34.52, -12.87, 89.10, 4.25, -76.99, 
    51.34, 18.05, 93.67, -45.12, 8.75, 
    -67.33, 22.11, 85.45, 99.95, 58.78
    }; 
    int dlugosc_seri = 0;
    int *wsk_dlugosc_seri =  &dlugosc_seri;
    const double *wskaznik = tab;
   
    
    double wynik = znajdzNajlepszaSerie(tab, ROZMIAR, *wsk_dlugosc_seri, wskaznik);
    std::cout<<"Suma: "<<wynik;
    std::cout<<"\nDlugosc seri: "<<*wsk_dlugosc_seri;
    std::cout<<"\nWartosc poczatku ciagu: "<<*wskaznik<<" Adres elementu w pamieci: "<<wskaznik;

    std::cout<<std::endl<<std::endl;
   
    return 0;
}
#endif

#if(ZADANIE == 3)

    bool czyUkrytyPalindrom(const char*lewy, const char* prawy){

        // m o 3# r o m a
        // k a j a k
        if (lewy >= prawy){
                return true;
            }

        if(isalpha(*lewy) && isalpha(*prawy) ){
            if(tolower(*lewy) == tolower(*prawy)){
                lewy ++;
                prawy --;
                return czyUkrytyPalindrom(lewy,prawy);
            }else{
                return false;
            }
        } 
        // jezeli prawy nie jest litera 
        else if (!isalpha(*prawy)){
            prawy--;
            return czyUkrytyPalindrom(lewy, prawy);
        }
        // jezeli lewy nie jest litera 
        else if (!isalpha(*lewy) ){
            lewy++;
            return czyUkrytyPalindrom(lewy, prawy);
        }

        return false;
    }
int main(){

//     Kontekst: To zadanie zniszczy Twoje przyzwyczajenia do pętli. Całość musi odbyć się na stosie wywołań. Pracujemy na surowych znakach i liczbach.
// Wymagania:
//     Stwórz funkcję czyUkrytyPalindrom. Funkcja zwraca typ bool.
//     Funkcja przyjmuje tylko dwa argumenty: wskaźnik na początek tekstu (const char* lewy) oraz wskaźnik na koniec tekstu (const char* prawy).
//     Bezwzględny zakaz używania pętli (for, while, do-while). Cała logika przesuwania się po tekście musi być rekurencyjna.
//     Działanie: Funkcja sprawdza, czy badany wycinek tekstu jest palindromem (czyta się tak samo z obu stron).
//         Haczyk 1: Tekst zawiera spacje, znaki interpunkcyjne i cyfry (np. "A l 3# i l a"). Funkcja ma to całkowicie ignorować i brać pod uwagę TYLKO litery alfabetu.
//         Haczyk 2: Jeśli lewy wskaźnik trafia na śmiecia (np. cyfrę lub spację), funkcja ma wywołać samą siebie, przesuwając tylko lewy wskaźnik o jeden krok. To samo dla prawego.
//         Haczyk 3: Jeśli oba wskaźniki patrzą na poprawne litery, funkcja sprawdza, czy są takie same 
//         (ignorując wielkość liter: 'A' to 'a'). Jeśli są, wywołuje samą siebie, "zwężając" oba wskaźniki do środka. Jeśli nie są – zrzuca rekurencję zwracając false.
//     Zastanów się bardzo dobrze nad warunkiem stopu (kiedy funkcja ma przestać wchodzić w głąb i zwrócić ostateczne true). Pamiętaj, że wskaźniki idą z dwóch stron na spotkanie.
      
    //const char tablica [] = "kajak";
    const char tablica [] = "m o 3# r o m a";
    const char* lewy = tablica;
    int rozmiar = sizeof(tablica)/sizeof(char);
    const char * prawy = &tablica[rozmiar-1];
    bool wynik = czyUkrytyPalindrom(lewy,prawy);
    std::cout<<"Czy słowo jest palindromem: "<<wynik<<"\n1 - tak\n0 - nie\n\n\n\n";


    return 0;
}
#endif
