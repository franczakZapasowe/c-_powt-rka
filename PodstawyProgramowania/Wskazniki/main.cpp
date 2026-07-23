#include <iostream>
#include <algorithm>
#define ZADANIE 3

#if (ZADANIE == 1)
int main(){

// Koncepcja: Zrozumienie, że wsk2 - wsk1 zwraca odległość (liczbę elementów), 
// a *wsk daje dostęp do wartości. (Slajdy 14-16 i 21-23).
// Polecenie: 
// Stwórz jednowymiarową tablicę float z kilkunastoma losowymi odczytami (niektóre wartości niech rosną, inne maleją). 
// Twoim zadaniem jest znalezienie najdłuższego rosnącego ciągu w tej tablicy.
// Zasady gry: 1. Od momentu zadeklarowania tablicy, masz całkowity zakaz używania nawiasów kwadratowych [] 
// oraz zwykłych liczników całkowitych (typu int i = 0) do nawigacji.
// 2. Musisz utworzyć wskaźniki (np. poczatek_ciagu, koniec_ciagu, najdluzszy_poczatek).
// 3. Pętlę opierasz wyłącznie na przesuwaniu wskaźnika (wsk++).
// 4. Długość ciągu musisz wyliczać na bieżąco, odejmując od siebie adresy (np. koniec - poczatek).
// 5. Na koniec wypisz długość najdłuższego ciągu i użyj zapamiętanego wskaźnika, aby wydrukować wszystkie jego elementy.

    float tab[15]={};
    srand(time(0));
    for (int i=0;i<15; i++){
        tab[i]= (rand()%20);
    }
    int ROZMIAR = sizeof(tab)/sizeof(float);
    // poniewaz losouje tablice chce ją najperw wypisac dla testu |
    std::cout<<"Wypisanie losowej tablicy\n";
    for (int i=0;i<15; i++){
        std::cout<<tab[i]<<"\t";
    }

    float *poczatekCiagu = tab, *koniecCiagu = tab+1, *nadjdlzuzszyPoczatek = tab, *najdluzszyKoniec = tab;
    int dlguosc = 0;
        // 1 2 5 3 4  74 5 6 7 8
    while (koniecCiagu < tab + ROZMIAR)
    {
        if (*koniecCiagu < *(koniecCiagu-1)){
            int najdluzszy = koniecCiagu - poczatekCiagu;
            if(dlguosc<najdluzszy){
                dlguosc = najdluzszy;   
                nadjdlzuzszyPoczatek = poczatekCiagu;
                najdluzszyKoniec = koniecCiagu-1;
            }
            poczatekCiagu = koniecCiagu;
        }
        koniecCiagu+=1;
    }
    int najdluzszy = koniecCiagu - poczatekCiagu;
        if (*koniecCiagu < *(koniecCiagu-1)){
            if(dlguosc<najdluzszy){
                dlguosc = najdluzszy;
                nadjdlzuzszyPoczatek = poczatekCiagu;
                najdluzszyKoniec = koniecCiagu-1;
            }
        }

    //wypisanie
    std::cout<<"\nWypisanie wyniku\n";
    while(nadjdlzuzszyPoczatek <= najdluzszyKoniec){
        std::cout<<*nadjdlzuzszyPoczatek<<"\t"; nadjdlzuzszyPoczatek++;
    }
    std::cout<<"\nIlosc liczb w ciagu:"<<dlguosc<<"\n";
    


    return 0;
}
#endif

#if (ZADANIE == 2)
int main(){
    // Koncepcja: Przestawianie ciężkich bloków danych w pamięci RAM marnuje cykle procesora. 
    // Zamiast tego przestawia się same "zakładki" (wskaźniki) do tych danych. (Slajdy 24-28).
    // Polecenie:
    // Masz dwuwymiarową tablicę double pomiary[5][4]. Każdy wiersz to pakiet danych, gdzie pierwsza kolumna 
    // to unikalny znacznik czasu (timestamp), a reszta to odczyty z czujników. 
    // Wypełnij ją w pełni losowo.
    // Zamiast sortować całą tę wielką macierz (zamieniając miejscami całe wiersze), 
    // utwórz jednowymiarową tablicę wskaźników: double* widok[5];.
    // Ustaw każdy element widok tak, aby wskazywał na początek odpowiedniego wiersza
    // w oryginalnej tablicy pomiary.Napisz algorytm sortujący (np. bąbelkowy), 
    // który posortuje wiersze rosnąco według znacznika czasu (pierwszej kolumny każdego wiersza). 
    // Haczyk: Algorytm nie może tknąć oryginalnej tablicy pomiary. Ma zamieniać miejscami WYŁĄCZNIE adresy w tablicy widok.
    // Wydrukuj oryginalną tablicę (będzie wciąż chaotyczna) oraz posortowane dane, używając wyłącznie podwójnej dereferencji 
    // Twojej tablicy wskaźników.

    double pomiary [5][4]={};
    srand(time(0));
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            pomiary[i][j]=(rand()%200);
        }
    }
    //wypisanie tablicy 
    std::cout<<"Przed podmiana\n";
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            std::cout<<pomiary[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    double *widok[5] = { &pomiary[0][0],
                         &pomiary[1][0],
                         &pomiary[2][0],
                         &pomiary[3][0],
                         &pomiary[4][0] };

    for (int i=0; i<5; i++){
        for(int j=1;j<5;j++){
            if(*(widok[j]) < *(widok[j-1]))
            std::swap(widok[j], widok[j-1]);
        }
    }  

    //test działania
    std::cout<<"\nPo sortowaniu\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            std::cout<<widok[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}
#endif

#if (ZADANIE == 3)
int main(){
// Koncepcja: Zabezpieczenie pamięci i zarządzanie dwoma wskaźnikami "goniącymi się" w 
// zapętlonym obszarze pamięci. (Slajdy 34-37).
// Polecenie: 
// Zbuduj bufor cykliczny w oparciu o statyczną tablicę np. 8 elementów. Utwórz dwa wskaźniki: 
// wskaźnik zapisu (wz) i wskaźnik odczytu (wo). Utwórz flagi pusty i pelny.
// Symuluj asynchroniczną pracę systemu w pętli (np. 30 iteracji):
// W każdej iteracji rzuć wirtualną monetą (np. z użyciem rand()).
// Masz 60% szans, że system próbuje zapisać nową paczkę danych (wpisuje wartość tam, 
// gdzie pokazuje wz, i przesuwa wz o jedno miejsce).
// Masz 40% szans, że system próbuje odczytać i przetworzyć dane (pobiera z wo i przesuwa wo o jedno miejsce).
// Wymogi inżynierskie: Musisz zaimplementować tzw. zawijanie wskaźników 
// (jeśli wskaźnik wyjdzie poza tablicę, wraca na jej indeks 0, adres bazowy).
// System nie może pozwolić na nadpisanie danych (zapis jest blokowany, 
// jeśli bufor jest pełny) i nie może pozwolić na odczyt śmieci (odczyt jest blokowany, jeśli bufor jest pusty). 
// Musisz precyzyjnie zarządzać flagami uderzając w logikę ze slajdu 37.

    constexpr int ROZMIAR = 8;
    double tab[ROZMIAR] = {}, *wo = tab, *wz = tab;
    bool pusty = true, pelny = false;
    srand(time(0));

    for(int i = 0; i<30; i++){
        int rzut = rand()%100;

        if(rzut<60){
            pusty = false; 
            if(!pelny){
                std::cout<<"Z: "<<(*wz++ = rzut)<<"\n";
            }else
                std::cout<<"Pelny\n";

                if(wz >= tab + ROZMIAR) wz = tab;
                if(wz == wo) pelny = true;
           
        }else{
            pelny=false;
            if(!pusty){
                std::cout<<"O: "<<(*wo++)<<"\n";
            }else
                std::cout<<"Pusty\n";

                if(wo>=tab+ROZMIAR) wo = tab;
                if(wz==wo) pusty=true;
        }
    }

    
}
#endif

