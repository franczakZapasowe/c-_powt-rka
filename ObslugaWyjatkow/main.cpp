#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cmath>
#define ZADANIE 3

#if ZADANIE == 1
void analizujTemperatury(const double *odczyt, int rozmiar) {
    assert(odczyt != nullptr);
    if (rozmiar < 1) throw std::length_error("");
    for (int i =0; i < rozmiar; i++) {
            if (odczyt[i] < -300.0) throw std::out_of_range("");
    }
}

int main() {

//     Kontekst: Piszesz moduł analizy danych telemetrycznych z silnika rakietowego.
//     Moduł przyjmuje tablicę odczytów temperatury. Musisz twardo oddzielić błędy programisty (złe użycie funkcji)
//     od błędów środowiska (awaria czujnika), wykorzystując wiedzę ze slajdów 18-24.
// Wymagania:
    // Napisz funkcję analizujTemperatury(const double* odczyty, int rozmiar).
    // Ochrona niezmiennika: Funkcja nie ma prawa działać, jeśli ktoś prześle jej pusty wskaźnik.
    // Użyj makra assert, aby sprawdzić ten niezmiennik (odczyty != nullptr) na samym początku funkcji.
    // Błędy użytkowe (Wyjątki): * Jeśli rozmiar < 1, funkcja ma rzucić wyjątek std::length_error.
    //     Algorytm ma iterować po tablicy. Jeśli natrafi na temperaturę poniżej zera absolutnego (np. -300.0),
    //     oznacza to awarię czujnika. Funkcja ma natychmiast przerwać działanie i rzucić wyjątek std::out_of_range.
    // W main zbuduj blok try-catch, który:
    //     Posiada osobny catch dla std::length_error.
    //     Posiada osobny catch dla std::out_of_range.
    //     Posiada uniwersalny catch (...), aby złapać wszystko inne.
    // Przetestuj działanie, celowo wywołując po kolei wszystkie trzy stany awaryjne (w tym wywołanie z nullptr,
    // co powinno brutalnie ubić program asercją).

    constexpr int ROZMIAR = 10;
    double *odczyt2 = nullptr;
    double odczyt[ROZMIAR] = {12.4, -215.8, 340.1, -12.0, 199.9, -349.5, 88.2, -150.3, 275.6, 5.5};
    try {
        //analizujTemperatury(odczyt,ROZMIAR);
        //analizujTemperatury(odczyt,0);
        analizujTemperatury(odczyt2,ROZMIAR);
    } catch (std::out_of_range ) {
        std::cerr<<"Liczba jest mniesza niz -300.0\n";
    }catch (std::length_error) {
        std::cerr<<"Rozmiar tablicy jest mniejszy niz 1\n";
    } catch (...) {
        std::cerr<<"Fail\n";
    }
    return 0;
}
#endif

#if ZADANIE == 2
//#define TEST

double dystans (double x1, double y1, double x2,double y2) {
    return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}

#ifdef TEST

void test_dystans_standardowy () {
    double eps = 1e-3;
    double wynik_oczekiwany = 5.0;
    double wynik = dystans(0.0, 0.0, 3.0, 4.0);
    if (wynik_oczekiwany-eps <= wynik && wynik<= wynik_oczekiwany+eps)
        std::cerr<<"Test f. dystans(): x1=0.0, y1=0.0, x2=3.0, y2=4.0: Ok\n";
    else std::cerr<<"FAIL! wartosc oczekiwana: "<<wynik_oczekiwany<<" wynik uzyskany: "<<wynik<<"\n";
}

void test_dystans_brzegowy () {
    double eps = 1e-3;
    double wynik_oczekiwany = 0;
    double wynik = dystans(0.0, 0.0, 0.0, 0.0);
    if (wynik_oczekiwany-eps <= wynik && wynik<= wynik_oczekiwany+eps)
        std::cerr<<"Test f. dystans(): x1=0.0, y1=0.0, x2=0.0, y2=0.0: Ok\n";
    else std::cerr<<"FAIL! wartosc oczekiwana: "<<wynik_oczekiwany<<" wynik uzyskany: "<<wynik<<"\n";
}

void test_dystans_ujemny() {
    double eps = 1e-3;
    double wynik_oczekiwany = 5.0;
    double wynik = dystans(-1.5, -2.5, 2.5, 0.5);
    if (wynik_oczekiwany-eps <= wynik && wynik<= wynik_oczekiwany+eps)
        std::cerr<<"Test f. dystans(): x1=-1.5, y1=-2.5, x2=2.5, y2=0.5: Ok\n";
    else std::cerr<<"FAIL! wartosc oczekiwana: "<<wynik_oczekiwany<<" wynik uzyskany: "<<wynik<<"\n";
}
int main() {
    test_dystans_standardowy();
    test_dystans_brzegowy();
    test_dystans_ujemny();
}

#else

int main() {
    // Kontekst: Wdrażasz system pozycjonowania GPS. Zgodnie z metodyką TDD, najpierw definiujesz scenariusze testowe,
    // a dopiero potem piszesz docelową logikę, korzystając z kompilacji warunkowej.\
    // Wymagania:
    // Zdefiniuj dyrektywy preprocesora #define TEST na samej górze pliku, aby sterować trybami kompilacji
    // (tryb testowy uruchamia testy w main, a brak definicji kompiluje normalny program).Przygotuj "pustą" funkcję
    // double dystans(double x1, double y1, double x2, double y2), która zwraca 0.0.Zbuduj funkcję test_dystans().
    // Pamiętaj, że testujesz liczby rzeczywiste typu double, więc zwykłe == nie zadziała.
    // Musisz wdrożyć test z tolerancją eps (np. $1e-4$). Wyniki testów muszą wyświetlać zwięzłe komunikaty OK/FAIL.
    // Zdefiniuj trzy rygorystyczne przypadki testowe wewnątrz test_dystans():
    // Przypadek standardowy (odległość z $(0, 0)$ do $(3, 4)$ powinna wynosić $5.0$).
    // Przypadek brzegowy (odległość z $(0, 0)$ do $(0, 0)$).
    // Przypadek z ujemnymi koordynatami (z $(-1.5, -2.5)$ do $(2.5, 0.5)$).
    // Dopiero gdy testy zgłoszą FAIL!, dopisz wewnątrz funkcji dystans właściwą matematykę:
    // $\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$, aż wszystkie testy zaświecą się na OK.
    // Wypisz na terminal i wartość oczekiwaną, i rzeczywistą, jeśli test nie przejdzie.

    return 0;
}
#endif
#endif

#if ZADANIE == 3

void zapiszNaDysk(int sektor) {
    if (sektor < 1) throw 404;
}
void zapiszDoBazy() {
    try {
        zapiszNaDysk(0);
    }catch (int n) {
        std::cerr<<"Wewnetrza obsluga logow\n";
        throw n;
    }
}
void czyscBufor() noexcept {
    std::cerr<<"Czyszczenie po bledach"<<std::endl;
}

int main() {
//     Kontekst: Systemy serwerowe często posiadają wielowarstwową architekturę.
//     Błąd wykryty w sterowniku dysku (najniższa warstwa) musi być zasygnalizowany do bazy danych (warstwa średnia),
//     a potem do interfejsu klienta (najwyższa warstwa).
// Wymagania:
//     Utwórz trzy warstwy (trzy funkcje): main(), która wywołuje zapiszDoBazy(), która z kolei wywołuje zapiszNaDysk().
//     W funkcji zapiszNaDysk(int sektor) zasymuluj błąd: jeśli sektor < 0,
//     wyrzuć instrukcją throw liczbę całkowitą reprezentującą kod błędu (np. 404).
//     W funkcji zapiszDoBazy() zamknij wywołanie zapiszNaDysk w bloku try-catch.
//     W bloku catch musisz wypisać w konsoli błąd (tzw. "wewnętrzna obsługa logów"),
//     a następnie przekazać wyjątek wyżej, używając odpowiedniej instrukcji, aby wyjątek poleciał dalej w stronę main.
//     Odbierz ten odrzucony wyjątek w ostatecznym bloku try-catch w main i tam wypisz komunikat dla użytkownika.
//     Wyzwanie noexcept: Stwórz dodatkową funkcję czyscBufory() i dodaj do niej specyfikator noexcept,
//     gwarantujący kompilatorowi, że ta funkcja absolutnie nigdy nie rzuci wyjątku.
//     Wywołaj ją w main po całym procesie (nawet jeśli wystąpił błąd, jako formę "sprzątania").

    try {
        zapiszDoBazy();
    }catch (int n) {
        std::cerr<<"blad podczas wewnetrzej obslugi logow\n";
    }
    czyscBufor();
}
#endif