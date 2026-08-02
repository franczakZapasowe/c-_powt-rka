#include <iostream>
#include <string.h>
using namespace std;
//#define ZADANIE1
//#define ZADANIE2
#define ZADANIE3
#ifdef ZADANIE1
int main() {

    const double*  *const  *wsk = new const double*  *const{new const double*{new const double{5}}};
    cout<<***wsk;

    delete **wsk;
    delete *wsk;
    delete  wsk;
    //const double  *const * const * wsk3 = new const double  * const ** ;


}
#endif

#ifdef ZADANIE2
void resize(int **&tab, int row, int col, int newRow,int newCol);

int main () {
    int row = 5, col = 5;

    int **bufor = new int*[row];
    bufor[0] = new int [row*col]{};

    for (int i =1; i< row; i++)
        bufor[i] = &bufor[0][i*col];

    int newWiersze = 1000;
    int newKolumny = 1000;
    cout<<"Podaj rozmiar nowej wiekszej tablicy: aktualny rozmiar to wiersze: "<<row<<" kolumny: "<<col<<endl;
    do {
        cout<<"Nowa liczba wierszy: "; cin>>newWiersze;
        cout<<"Nowa liczba kolumn: "; cin>>newKolumny;

        if (newWiersze <= row || newKolumny <=col)
            cout<<"Blad ! Nowe wymiary nie moge byc mniejsze niz aktualne\n";

    }while (newWiersze <= row || newKolumny <= col);

    resize(bufor, row, col,newWiersze,newKolumny);

    delete[] bufor[0];
    delete[] bufor;
}

void resize(int **&tab, int row, int col, int newRow,int newCol0){
    int **temp = new int*[newRow];
    temp[0] = new int[newCol0*newRow]{};
    for (int i =1; i< newRow; i++)
        temp[i] = &temp[0][i*newCol0];

    for (int i =0; i< row; i++) {
        for (int j =0; j< col; j++) {
            temp[i][j] = tab[i][j];
        }
    }

    delete[] tab[0];
    delete[] tab;

    tab = temp;
    temp = nullptr;
}

#endif


#ifdef ZADANIE3

int* genTab(int n) {

    int *tab = new (nothrow) int[n]{};
    if (tab!=nullptr) {
        for (int i =0; i< n; i++) tab[i] = i*5;
    }
    return tab;

}

void zwolnijZasoby(int **tab) {

    delete[] *tab;
    *tab = nullptr;
}

int main() {

    int n;
    cout<<"Podaj rozmiar tablicy: "; cin>>n;
    int *tab = genTab(n);
    cout<<endl;
    for (int i =0; i< n; i++) cout<< tab[i]<<" ";
    zwolnijZasoby(&tab);
    return 0;
}
#endif
