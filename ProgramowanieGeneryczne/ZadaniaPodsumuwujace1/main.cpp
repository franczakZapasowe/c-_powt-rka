#include <algorithm>
#include <assert.h>
#include <iostream>
#include <array>
#include <tuple>


bool predykat0(const std::array<int,3>&t) {
    int dolna = 1, gorna = 5;
        return ((dolna<=t[0] && t[0]<=gorna) && (dolna<=t[1] && t[1]<=gorna) && (dolna<=t[2] && t[2]<=gorna));
}

class Predykat1 {
    int m_x =1;
    public:
    Predykat1()= default;
    Predykat1(int x):m_x(x) {};
    bool operator()(const std::array<int,3>&t) {
        assert(predykat0(t));
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
public:
    Predykat2()= default;
    Predykat2(int x,int liczbaZliczen):m_x(x),m_liczbaZliczen(liczbaZliczen) {
        assert(m_x>=1 && m_x<=5);
    };
    bool operator()(const std::array<int,3>&t) {
        assert(predykat0(t));
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

    std::array<int,3> t;
    Predykat1 predykat1(4);
    Predykat2 predykat2(3,0);
    auto predykat3 = [&]() {

    };
    auto predykat4 = []() {

    };

    for (int i=1;i<6;i++) {
        for (int j=1;j<6;j++) {
            for (int k=1;k<6;k++) {
                t ={i,j,k};
                if (predykat1(t) && predykat2(t) && predykat3(t)&&predykat4(t)) {
                    printf("Prawdziwe dla liczb: %d, %d, %d\n",i,j,k);
                }
            }
        }
    }
    return 0;
}