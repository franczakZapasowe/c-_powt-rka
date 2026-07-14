#include <iostream>
#include  <random>
#include  <utility>
#include <ctime>

constexpr int ROZMIAR = 20;

void sortowanieBabelkowe(int *tab, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n-1; j >= 1; j--) {
            if (tab[j] > tab[j-1]) {
                std::swap(tab[j], tab[j-1]);
            }
        }
    }
}

void sortowanieBabelkowe2(int *tab, int n) {
    bool nextIter = true;
    int k = 0;
    do {
        nextIter = false;
        for (int i = 0; i < n - k-1; i++) {
            if (tab[i] > tab[i+1]) {
                std::swap(tab[i], tab[i+1]);
                nextIter = true;
            }
        }
        k++;
    }while (nextIter);
}

void wypelnij(int *tab, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 500);
    for (int i = 0; i < n; i++) {
        tab[i] = dis(gen);
    }
}

void wypisz (int *tab, int n) {
    for (int i = 0; i < n; i++)
        std::cout << tab[i]<<"\t";
}

void sortowaniePrzezWstawienie(int *tab, int n) {
    for (int i = n - 2; i >= 0; i--) {
        int v = tab[i];
        int j = i+1;
        while (j<n && v > tab[j]) {
            tab[j-1] = tab[j];
            j++;
        }
        tab[j-1] = v;
    }
}

void scal(int *tab, int start, int srodek, int koniec) {
    int *temp = new int [koniec -start + 1];
    int i = start;
    int j = srodek+1;
    int k = 0;

    while (i <=srodek  && j <=koniec) {
        if (tab[i]<= tab[j]) {
            temp[k++] = tab[i++];
        }else {
            temp[k++] = tab[j++];
        }
    }
    while (i <=srodek) {
        temp[k++] = tab[i++];
    }
    while (j <=koniec) {
        temp[k++] = tab[j++];
    }

    for (int i = 0; i < koniec - start + 1; i++) {
        tab[i+start] = temp[i];
    }

    delete [] temp;
    temp = nullptr;
}
void mergSort(int *tab, int start, int koniec) {
    if (start == koniec) return;
    int srodek = (start + koniec) /2;
    mergSort(tab, start, srodek);
    mergSort(tab, srodek+1, koniec);
    scal(tab, start, srodek, koniec);
}
int split(int *tab, int start, int koniec) {
    int pivot = tab[koniec];
    int j = start -1;
    for (int i = start; i <= koniec-1; i++) {
        if (tab[i] < pivot) {
            j++;
            std::swap(tab[i],tab[j]);
        }
    }
    j++;
    std::swap (tab[j], tab[koniec]);
    return j;

}
void sortuj (int *tab, int start, int koniec) {
    if (start>=koniec) return;
    int pivot = split(tab,start,koniec);
    sortuj (tab, start, pivot-1 );
    sortuj (tab,pivot+1,koniec);
}


int main() {
    int tab [ROZMIAR];
    wypelnij(tab, ROZMIAR);
    std::cout <<"____________________SOROTOWANIE BABELKOWE___________________"<<std::endl;
    std::cout<<"Przed sorotwaniem babelkowym:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"Sortowanie babelkowe trwa...\n";
    std::clock_t start = std::clock();
    sortowanieBabelkowe2(tab, ROZMIAR);
    std::clock_t end = std::clock();
    double czas = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout<<"Po sortowaniu babelkowym:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"\nCzas sortowania babelkowego: "<<czas<<std::endl;

    std::cout <<"\n\n____________________SOROTOWANIE PRZEZ WSTAWIANIE___________________"<<std::endl;
    wypelnij(tab, ROZMIAR);
    std::cout<<"Przed sorotwaniem przez wstawianie:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"Sortowanie prez wstawienie trwa...\n";
    std::clock_t start2 = std::clock();
    sortowaniePrzezWstawienie(tab, ROZMIAR);
    std::clock_t end2 = std::clock();
    double czas2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    std::cout<<"Po prez wstawienie:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"\nCzas sortowania prez wstawienie: "<<czas2<<std::endl;

    std::cout <<"\n\n____________________SOROTOWANIE PRZEZ SCALANIE______________________"<<std::endl;
    wypelnij(tab, ROZMIAR);
    std::cout<<"Przed sorotwaniem przez scalanie:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"Sortowanie prez scalanie trwa...\n";
    std::clock_t start3 = std::clock();
    mergSort(tab, 0, ROZMIAR-1);
    std::clock_t end3 = std::clock();
    double czas3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    std::cout<<"Po prez scalanie:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"\nCzas sortowania prez scalanie: "<<czas3<<std::endl;


    std::cout <<"\n\n____________________QUCIK SORT_____________________"<<std::endl;
    wypelnij(tab, ROZMIAR);
    std::cout<<"Przed sorotwaniem przez scalanie:\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"Sortowanie qucik sort trwa...\n";
    std::clock_t start4 = std::clock();
    sortuj (tab, 0, ROZMIAR-1);
    std::clock_t end4 = std::clock();
    double czas4 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    std::cout<<"Po qucik :\n";
    wypisz(tab, ROZMIAR);
    std::cout<<"\nCzas sortowania qucik sort: "<<czas4<<std::endl;

    return 0;
}