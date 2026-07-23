#include <iostream>
#include <random>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cmath>
#define ZADANIE 3

#if ZADANIE == 1

int main() {

    // Kontekst: Tworzysz rdzeń wtyczki audio (VST). Przez Twój algorytm przepływają gigantyczne bufory próbek dźwiękowych.
    // Karta dźwiękowa wymaga przetworzenia danych w czasie krótszym niż kilka milisekund, inaczej usłyszysz "trzaski".
    // Musisz wycisnąć z pętli absolutne maksimum wydajności.
    // Wymagania:
    //     Utwórz w main ogromną tablicę (lub zaalokuj dynamicznie, jeśli braknie stosu) double bufor[10000000];
    //     (10 milionów elementów) i wypełnij ją losowymi wartościami z przedziału [-1.0, 1.0].
    //     Zdefiniuj stałą wielkość wzmocnienia sygnału: const double GAIN = 0.8;.
    //     Podejście klasyczne: Napisz zwykłą pętlę for, która przemnoży każdy element bufora przez GAIN.
    //     Zmierz czas jej wykonania za pomocą funkcji z biblioteki <ctime> (jak na slajdzie 25).
    //     Podejście niskopoziomowe (Wyzwanie): Zaimplementuj przetworzenie tego samego bufora
    //     (przywróconego do oryginalnych wartości) za pomocą Maszyny Duffa (slajd 31) lub ręcznego wyprostowania pętli
    //     z krokiem co 8 elementów (bufor[i] *= GAIN; bufor[i+1] *= GAIN; ...).
    //     Wypisz w konsoli czasy obu operacji. Udowodnij architekturą,
    //     że złamanie zasady DRY (Don't Repeat Yourself)
    //     na rzecz prostowania pętli drastycznie zmniejsza liczbę instrukcji skoku w procesorze i przyspiesza system.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-1.0, 1.0);

    double *bufo = new double [10000000];
    double *bufo2 = new double[10000000];
    const double GAIN = 0.8;
    for (int i=0; i<10000000; i++) {
        double random_nium = dis(gen);
        bufo[i]=random_nium;
        bufo2[i] = bufo[i];
    }

    std::clock_t start = std::clock();
    for (int i=0; i<10000000; i++) {
        bufo[i]*=GAIN;
    }
    std::clock_t koniec = std::clock();
    std::clock_t cycle = koniec - start;
    double czas1 =(double) cycle/CLOCKS_PER_SEC;


    std::clock_t start2 = std::clock();
    //PROSTOWANIE PĘTLI
    for (int i=0; i<10000000; i+=8) {
        // ŁAMIEMY ZASADE DRY
        bufo2[i]*=GAIN;
        bufo2[i+1]*=GAIN;
        bufo2[i+2]*=GAIN;
        bufo2[i+3]*=GAIN;
        bufo2[i+4]*=GAIN;
        bufo2[i+5]*=GAIN;
        bufo2[i+6]*=GAIN;
        bufo2[i+7]*=GAIN;
    }
    std::clock_t koniec2 = std::clock();
    std::clock_t cycle2 =  koniec2-start2;
    double czas2 = (double) cycle2/CLOCKS_PER_SEC;

    std::cout<<std::fixed<<std::setprecision(6);
    std::cout<<"Czas przy zwyklej pretli: "<<czas1<<std::endl;
    std::cout<<"Czas przy prostowaniu pętli: "<<czas2<<std::endl;

    delete[] bufo;
    delete[] bufo2;
    return 0;
}

#endif

#if ZADANIE == 2
constexpr double cena(double t) {
    return sin(t * 2.0) + cos(t);
}
constexpr double GRANICA_DOLNA=0.0,  GRANICA_GORNA=100000;
int main() {
//     Kontekst: Twój bot giełdowy musi błyskawicznie analizować trajektorię ceny, aby wyprzedzić rynek.
//     Obliczasz numeryczną pochodną funkcji symulującej ruch ceny (prędkość zmiany), aby wykryć momenty silnego wybicia.
// Wymagania:
//     Stwórz funkcję symulującą model ceny: double cena(double t), która zwraca sin(t * 2.0) + cos(t).
//     Wymuś na kompilatorze, by ta funkcja była liczona w czasie kompilacji tam, gdzie to możliwe,
//     używając specyfikatora constexpr (slajd 37).
//     Napisz algorytm, który w pętli od t = 0.0 do t = 100000.0 (z krokiem dt = 0.0001)
//     oblicza różniczkę centralną (slajd 20) z funkcji ceny w każdym punkcie.
//     Optymalizacja matematyczna (Wyzwanie): Wzór na różniczkę centralną wymaga dzielenia przez 2 * dt.
//     Dzielenie zmiennoprzecinkowe to najwolniejsza operacja w procesorze (trwa dziesiątki cykli zegara).
//     Zastosuj technikę wyłączenia operacji poza pętlę (slajd 32). Oblicz odwrotność (1.0 / (2.0 * dt)) przed pętlą jako stałą
//     i wewnątrz pętli zamień powolne dzielenie na błyskawiczne mnożenie.
//     Zmierz i porównaj czas działania algorytmu z dzieleniem wewnątrz pętli oraz wersji zoptymalizowanej
//     z wyciągniętym mnożnikiem na zewnątrz.

    std::cout<<std::fixed<<std::setprecision(3);
    double dt = 0.0001;
    const double dzielnik = (1.0 / (2*dt));
    double rozniczka = 0;
    double rozniczka2 = 0;
    std::clock_t start = std::clock();
    for (double t = GRANICA_DOLNA;  t<GRANICA_GORNA; t+=dt) {
        rozniczka = ((cena(t +dt)) - (cena(t-dt)))/(2*dt);
    }
    std::clock_t koniec = std::clock();
    std::clock_t cycle = koniec - start;
    double wynik = (double) cycle/CLOCKS_PER_SEC;

    std::clock_t start2 = std::clock();
    for (double t = GRANICA_DOLNA;  t<GRANICA_GORNA; t+=dt) {
        rozniczka2 = ((cena(t+dt)) - (cena(t-dt))) *dzielnik;
    }
    std::clock_t koniec2 = clock();
    std::clock_t cycle2 = koniec2 - start2;
    double wynik2 = (double) cycle2/CLOCKS_PER_SEC;

    std::cerr<<"Czas bez opytmalizacji: "<<wynik<<std::endl;
    std::cerr<<"Czas z optymalizacja: "<<wynik2<<std::endl;
    return 0;
}
#endif

#if ZADANIE == 3
double opor(double h) {
    return 0.1 * h * h + h + 10.0 + sin(2 * h);
}
constexpr double DOLNA_GRANICA = -10.0;
constexpr double GORNA_GRANICA = 10.0;
constexpr double tolerancja = 1e-3;

int main() {
//     Kontekst: Moduł sterujący oprogramowania lotu (np. we Flytronic) szuka optymalnej wysokości (h),
//     na której zawirowania aerodynamiczne są najmniejsze. Profil oporu powietrza ma jednak wiele minimów lokalnych,
//     co wyklucza proste schodzenie w dół.
// Wymagania:
//     Zdefiniuj funkcję oporu powietrza: double opor(double h), np. 0.1 * h * h + h + 10.0 + sin(2 * h).
//     (Przedział poszukiwań: h od -10.0 do 10.0).
//     Zaimplementuj poszukiwanie minimum w sposób losowy (Monte Carlo).
//     W każdej iteracji losujesz nową wysokość h z przedziału i sprawdzasz,
//     czy stawia ona mniejszy opór niż dotychczasowy rekord.
//     Złożone kryterium stopu (Wyzwanie): Pętla nie może działać w nieskończoność.
//     Zaimplementuj zintegrowany mechanizm wychodzenia z pętli oparty na dwóch warunkach jednocześnie:
//         Stagnacja (slajd 12): Przerwij, jeśli przez 500 kolejnych losowych prób algorytm
//         nie znalazł lepszego wyniku (pamiętaj o resetowaniu licznika stagnacji, gdy padnie nowy rekord!).
//         Absolutny limit bezpieczeństwa: Awaryjne przerwanie po 10000 iteracji całkowitych,
//         by zabezpieczyć procesor przed zawieszeniem.
//     Wypisz znaleziony pułap (xMin), minimalny opór (yMin) oraz statystyki
//     testu (w której iteracji algorytm faktycznie się zatrzymał dzięki mechanizmowi stagnacji).

        std::cout<<std::fixed<<std::setprecision(4);
        int stagnacja = 0, limitStagnacji = 500, limitCalkowity = 10000;
        double xmin = 10.0, minimlanyOpor = 1000.0;
        double oporH ,wysokosc;
        int i = 0;
        for (i = 0; i<limitCalkowity && stagnacja<limitStagnacji; i++) {
            wysokosc = DOLNA_GRANICA + (1.0*rand()) / (RAND_MAX) * (GORNA_GRANICA - DOLNA_GRANICA);
            oporH = opor(wysokosc);

            if (oporH < minimlanyOpor) {
                minimlanyOpor = oporH;
                xmin = wysokosc;
                stagnacja = 0;
            }else
                stagnacja++;
        }

    std::cout<<"x(min): "<<xmin<<"\ty(min): "<<minimlanyOpor<<" Algorytm zatrzymal sie w: "<<i<<" iteracji"<<std::endl;

}
#endif