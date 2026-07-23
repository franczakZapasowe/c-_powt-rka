#include <iostream>
#include <cstdio>
#include <cstring>
#include<iomanip>
#include <iomanip> 
#include <cmath>

#define ZADANIE 3

#if (ZADANIE==1)
int main()
{
    //Kontekst: Algorytmy bezstratnej kompresji danych w systemach wbudowanych.
    // Polecenie: 
    // Utwórz jednowymiarową tablicę i ręcznie wypełnij ją kilkunastoma liczbami, 
    // które tworzą powtarzające się bloki (np. kilka trójek z rzędu, potem 
    // seria jedynek, potem kilka piątek). 
    // Napisz algorytm, który przejdzie przez tę tablicę tylko raz i zliczy, 
    // ile razy z rzędu wystąpiła dana wartość. 
    // Program ma wypisać w konsoli raport w stylu: "Wartość X występuje Y razy z rzędu".
    // Haczyk: Największą pułapką tego zadania jest "wypchnięcie" i 
    // wypisanie wyniku dla ostatniego bloku danych w momencie, 
    // gdy pętla dociera do końca tablicy.
    
    int tablica[] = {1,1,1,2,2,2,2,2,2,14,14,14,14};
    int liczba = tablica[0];
    int rozmiar = sizeof(tablica)/sizeof(int);
    int licznik = 0;

    for (int i=0; i<rozmiar; i++){
        if(liczba==tablica[i]){
            licznik++;
        }else{
            std::cout<<"Liczba "<<liczba<<" Wystapila "<<licznik<<" razy\n";
            liczba = tablica[i];
            licznik = 1;
        }
    }
    std::cout<<"Liczba "<<liczba<<" Wystapila "<<licznik<<" razy\n";

}
#endif

#if (ZADANIE ==2)
int main(){
    // Kontekst: Manipulacja macierzami pikseli w systemach wizyjnych.
    // Polecenie: 
    // Zaprojektuj dwuwymiarową tablicę kwadratową (np. o wymiarach cztery na cztery wiersze i kolumny). 
    // Wypełnij ją sekwencyjnie kolejnymi liczbami naturalnymi. 
    // Twoim zadaniem jest napisanie algorytmu, który fizycznie obróci wszystkie dane w tej 
    // macierzy o 90 stopni w prawo (zgodnie z ruchem wskazówek zegara).
    // Haczyk: Wydrukuj macierz przed i po operacji. 
    // Nie możesz tego załatwić tylko sprytnym wypisywaniem 
    // w konsoli od tyłu – musisz dokonać twardej podmiany wartości pod odpowiednimi 
    // indeksami używając pętli.

    int tab [4][4];
    int natural = 1;
    for (int i =0; i<4;i++){
        for (int j=0; j<4;j++){
            tab[i][j]=natural;
            natural++;
        }
    }

    std::cout<<"Przed podmiana:\n";
    for (int i =0; i<4;i++){
        for (int j=0; j<4;j++){
            std::cout<<tab[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    int tab2[4][4];
    for (int w = 0; w<4; w++){
        for(int k =0;k<4; k++){
            tab2[k][3-w] = tab[w][k];
        }
    }

    
    std::cout<<"Po podmiana:\n";
    for (int i =0; i<4;i++){
        for (int j=0; j<4;j++){
            std::cout<<tab2[i][j]<<"\t";
        }
        std::cout<<"\n";
    }


}
#endif


#if (ZADANIE==3)
int main(){
    // Kontekst: Wygładzanie anomalii i szumów z aparatury pomiarowej.
    // Polecenie: 
    // Stwórz tablicę źródłową z "zaszumionymi" odczytami oraz drugą, równie dużą, 
    // pustą tablicę na przefiltrowane wyniki. Napisz algorytm filtrujący (tzw. okno o szerokości 3). O
    // znacza to, że wartość zapisywana pod indeksem w nowej tablicy jest średnią arytmetyczną trzech elementów 
    // ze starej tablicy: elementu z tym samym indeksem, elementu po lewej i elementu po prawej.
    // Haczyk: Indeks zero nie ma lewego sąsiada, a ostatni indeks nie ma prawego sąsiada. 
    // Zastosowanie surowego wzoru dla tych elementów wyrzuci program poza pamięć tablicy. 
    // Musisz to inteligentnie obsłużyć, nie zatrzymując głównej pętli i nie uciekając się 
    // do tworzenia trzech osobnych pętli dla początku, środka i końca.
    constexpr int ROZMIAR = 15;
    int tablicaSzum[ROZMIAR];
    int tablicaFilter[ROZMIAR]={};

    srand(time(0));
    for (int i =0;i<ROZMIAR; i++){
        tablicaSzum[i]= (rand()%999);
    }

    std::cout<<"Tablica szumow:\n";
    for (int i = 0; i<ROZMIAR; i++){
        std::cout<<tablicaSzum[i]<<"\t";
    }


    for (int i = 0; i<ROZMIAR; i++){
        if(i==0){
            tablicaFilter[i] = (tablicaSzum[i]+tablicaSzum[i+1])/2;
        }else if (i==ROZMIAR-1){
            tablicaFilter[ROZMIAR-1]=(tablicaSzum[ROZMIAR-1]+tablicaSzum[ROZMIAR-2])/2;
        }else{
            tablicaFilter[i]= (tablicaSzum[i] + tablicaSzum[i+1]+tablicaSzum[i-1])/3;
        }
    }

    std::cout<<"\nTablica po filtrze:\n";
    for (int i =0; i<ROZMIAR; i++){
        std::cout<<tablicaFilter[i]<<"\t";
    }
    std::cout<<"\n";
}
#endif