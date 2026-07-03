#include<iostream>

#define ZADANIE 3

#if(ZADANIE == 1 )
int main(){

    // Cel kodu: Skopiowanie zawartości 5-elementowej tablicy dane do tablicy kopia, 
    // ale w odwrotnej kolejności (czyli od tyłu).
    // Twój audyt: Gdzie stażysta przeszarżował i co tu ulegnie zniszczeniu?
    constexpr int ROZMIAR = 5;
    int dane[ROZMIAR] = {10, 20, 30, 40, 50};
    int kopia[ROZMIAR] = {0}; // nie potrzbne przypisanie elementu!
    int *wskDane = dane + ROZMIAR - 1; // Ustawienie na ostatni element (50)
    int *wskKopia = kopia;             // Ustawienie na początek nowej tablicy


    // Przepisanie danych
    for (int i = 0; i <= ROZMIAR; i++) {
        *wskKopia = *wskDane;
        wskKopia++;
        wskDane--;
    }
    
    std::cout << "Kopia zakonczona sukcesem.\n";


    // bład w tym zadaniu:
    // Programista ustawia wskazznik wskDane na ostatni element tablicy nastepnie ustawiwa
    // drugi wskaznik na 0 element tablicy czyli na 0 - narazie jeszce nie ma błedu
    // w pętli przypisuje wartosc 0 elementu do wartosci ostatnie elemetnu tak jak zadanie zakłada
    // ostatni element wsk dane zostatnie pobrany z indeksu -1 z poza naszej tablicy i 
    // zapisan doi ndeksu poza naza tablica
    // petla powina miec warunek < ROZMIAR
  

    return 0;
}
#endif

#if(ZADANIE == 2 )
int main(){

    // Cel kodu: Symulacja odliczania paliwa. Zaczynamy z pełnym bakiem (1.0). 
    // Co krok silnik spala dokładnie 0.1 jednostki paliwa. 
    // Pętla ma się zatrzymać, gdy w baku będzie idealne 0.0.
    // Twój audyt: Choć matematycznie 1.0 - (10 * 0.1) = 0, ten 
    // program ZAWSZE wywala błąd 
    // awaryjny (osiąga 100 kroków) i nie zatrzymuje się na 0.0. 
    double paliwo = 1.0;
    int liczbaKrokow = 0;

    std::cout << "Rozpoczynam manewr...\n";

    // Wykonuj dopóki mamy cokolwiek w baku
    while (paliwo != 0.0) { 
        paliwo = paliwo - 0.1;
        liczbaKrokow++;
        // 1 0.9 0.8 0. 0.6 0.6 0.4 0.3 0.2 0.1 0.0
        // Zabezpieczenie awaryjne, gdyby pętla trwała za długo
        if (liczbaKrokow > 100) {
            std::cout << "Przerwano awaryjnie!\n";
            break; 
        }
    }
    
    std::cout << "Silnik zgasl naturalnie. Pozostalo paliwa: " << paliwo << "\n";

    // blad wynika z tego ze 1.0 - 10 * 0.1 moze niekoneicznie byc zawsze rowne zero ze zgledu na blad numeryczny 
    // roziwazniem bylo by np while (paliwo > 0.0)
}
#endif

#if(ZADANIE == 3 )
void wyzerujBufor(double *bufor) {
    // Obliczanie ile elementów ma przekazana tablica
    int rozmiarWbajtach = sizeof(bufor);
    int iloscElementow = rozmiarWbajtach / sizeof(double);

    // Zerowanie
    for(int i = 0; i < iloscElementow; i++) {
        bufor[i] = 0.0;
    }
    std::cerr<<(int)rozmiarWbajtach<<"\n";
    std::cerr<<iloscElementow<<"\n";
    std::cout << "Wyzerowano " << iloscElementow << " elementow.\n";
}
int main(){
    // Cel kodu: Funkcja ma za zadanie wyzerować (wyczyścić) każdy przestarzały bufor z danymi
    // z czujników, który zostanie do niej przekazany.
    // Twój audyt: Pomysł wydawał się genialny – użycie sizeof, żeby funkcja sama domyśliła się,
    // jak duża jest tablica, bez konieczności przekazywania dodatkowej zmiennej z rozmiarem.
    // Niestety, funkcja nie zeruje całej tablicy. 
    // Co więcej, w zależności od architektury procesora (32-bit czy 64-bit), 
    // wyzeruje np. tylko 1 element, a resztę zostawi pełną śmieci. 
    // Gdzie leży błąd logiczny w użyciu sizeof w tej konkretnej sytuacji?
    
    double pomiary[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    
    // Przekazanie tablicy do wyzerowania
    wyzerujBufor(pomiary);
    
    return 0;

    // blad wynik z tego ze sizeof(bufor) to rozmiar adresu pierwszego elementu tablicy dobule czyli 8 
    // wiec jaky petla wykonuje sie tylko raz
    // 
    // 
    // 
    // 
}
#endif