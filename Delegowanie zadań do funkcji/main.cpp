#include <iostream>
#include <cstdlib>
#include <ctime>
#define ZADANIE 1

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
int main(){

    return 0;
}
#endif

#if(ZADANIE == 3)
int main(){

    return 0;
}
#endif