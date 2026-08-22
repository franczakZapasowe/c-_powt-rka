#include <algorithm>
#include <assert.h>
#include <iostream>
#include <array>
#include <cmath>
#include <ranges>
#include <span>
#include <tuple>
#include <vector>


bool predykat0(std::span<const int> t,int dolna,int gorna) {
    //zmiany w tym predykacie rowniez
        for (int i =0; i<t.size(); i++) {
            if (t[i]<dolna||t[i]>gorna) return false;
        }
    return true;
}

class Predykat1 {
    int m_x =1;
    int m_dolna = 1;
    int m_gorna = 9;
    public:
    Predykat1()= default;
    Predykat1(int x,int d, int g):m_x(x),m_dolna(d),m_gorna(g) {};
    bool operator()(std::span<const int> t) {
        assert(predykat0(t,m_dolna,m_gorna));
        assert(m_x>=1 && m_x<=5);
        return t[1]==m_x;
    }
};

/*
bool predykat1(const std::array<int,3>&t) {
    assert(predykat0(t));
    return t[1]==4;
} */

class Predykat2 {
    int m_liczbaZliczen;
    int m_x;
    int m_dolna = 0;
    int m_gorna = 9;
public:
    Predykat2()= default;
    Predykat2(int x,int liczbaZliczen,int dolna,int gorna)
    :m_x(x),m_liczbaZliczen(liczbaZliczen),m_dolna(dolna),m_gorna(gorna) {
        assert(m_x>=1 && m_x<=5);
    };
    bool operator()(std::span<const int> t) {
        assert(predykat0(t,m_dolna,m_gorna));
        int ile = std::count(t.begin(),t.end(),m_x);
        return ile == m_liczbaZliczen;
    }
};

/*
bool predykat2(const std::array<int,3>&t) {
    assert(predykat0(t));
        auto ile = std::count(t.begin(), t.end(), 3);
    return ile==0;
}

bool predykat3(const std::array<int,3>&t) {
    assert(predykat0(t));
    return t[0]<t[1];
}

bool predykat4(const std::array<int,3>&t) {
    assert(predykat0(t));
        return t[0]>t[2] && t[1]>t[2];
}*/


int main() {

//#define WERSJA1
#ifdef WERSJA1
    //jako stale na poczatku
    constexpr int ROZMIAR = 3;
    constexpr int min_zakres =1;
    constexpr int max_zakres =9;
    static_assert(ROZMIAR>=3 && min_zakres>=1 && max_zakres <=9);

    std::array<int,ROZMIAR> t;
    Predykat1 predykat1(4,min_zakres,max_zakres);
    Predykat2 predykat2(3,0,min_zakres,max_zakres);
    int n = 0, m = 1;
    auto predykat3 = [n,m,max_zakres,min_zakres](std::span<const int> t) {
        assert(predykat0(t,min_zakres,max_zakres));
        return t[n]< t[m];
    };
    int idx_najmniejszej = 2;
    auto predykat4 = [idx_najmniejszej,min_zakres,max_zakres](std::span<const int> t) {
        assert(predykat0(t,min_zakres,max_zakres));
        for (int i=0;i<3;i++) {
            if (i!=idx_najmniejszej&& t[idx_najmniejszej]>t[i]) return false;
        }
        return true;
    };

    for (int i=min_zakres;i<max_zakres;i++) {
        for (int j=min_zakres;j<max_zakres;j++) {
            for (int k=min_zakres;k<max_zakres;k++) {
                t ={i,j,k};
                if (predykat1(t) && predykat2(t) && predykat3(t)&&predykat4(t)) {
                    printf("Prawdziwe dla liczb: %d, %d, %d\n",i,j,k);
                }
            }
        }
    }
    return 0;
#else
    int dlugoscKodu = 0;
    do {
        std::cout<<"Podaj dlugosc kodu (min 2 cyfry): ";
        std::cin>>dlugoscKodu;
    }while (dlugoscKodu <2);
    std::vector<int> tablica(dlugoscKodu);
    int dolna = 0;
    int gorna = 0;
    do {
        std::cout<<"Podaj gorna granice zakresu (minmalny 0 max 9)\n";
        std::cout<<"Dolna: "; std::cin>>dolna;
        std::cout<<"Gorna: "; std::cin>>gorna;
    }while (dolna < 0 || gorna > 9 );
    Predykat1 predykat1(4,dolna,gorna);
    Predykat2 predykat2(3,0,dolna,gorna);
    std::cout<<"Element 1 jest mneijszy od elemtnu drugiego podaj oba elemnty: (aktualnie elemntow): "<<dlugoscKodu<<std::endl;
    int n,m;
    do {
        std::cout<<"element 1: "; std::cin>>n;
        std::cout<<"\nelement 2: "; std::cin>>m;
    }while (n<0 || m<0 || n>dlugoscKodu || m>dlugoscKodu);
    auto predykat3 = [n,m,dolna,gorna](std::span<const int> t) {
        assert(predykat0(t,dolna,gorna));
        return t[n]< t[m];
    };
    std::cout<<"Podaj ktora ma byc mniejsza od pozostlych(aktualnie elemntow): "<<dlugoscKodu<<std::endl;
    int index;
    do {
        std::cout<<"Index: "; std::cin>>index;
    }while (index<0 || index>dlugoscKodu);
    auto predykat4 = [index,dolna,gorna](std::span<const int> t) {
        assert(predykat0(t,dolna,gorna));
        for (int i=0;i<3;i++) {
            if (i!=index&& t[index]>t[i]) return false;
        }
        return true;
    };

    // Koncept (wymaga dopracowania pod konkretne zmienne):
    int liczba_kombinacji = std::pow(gorna - dolna + 1, dlugoscKodu);
    auto wariacje = std::views::iota(0, liczba_kombinacji) | std::views::transform([=](int index) {
        std::vector<int> kod(dlugoscKodu);
        // Tutaj matematycznie przeliczamy 'index' na cyfry w systemie o podstawie (gorna - dolna + 1)
        // przy użyciu std::generate lub rekurencji
        return kod;
    });

#endif

}