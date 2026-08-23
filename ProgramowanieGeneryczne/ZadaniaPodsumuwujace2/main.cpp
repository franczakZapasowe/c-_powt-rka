#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>

struct Test {
    int _poleInt;
    double _poleDouble;

    static std::mt19937& losuj() {
        static std::random_device rd;
        static std::mt19937 gen{rd()};
        return gen;
    }

    Test() {
        std::uniform_int_distribution<int> disInt(0,9);
        std::normal_distribution<double> disDouble(0,3);
        _poleInt = disInt(losuj());
        _poleDouble = disDouble(losuj());
    }

    friend std::ostream& operator<<(std::ostream& os, const Test& t);
};

std::ostream& operator<<(std::ostream& os, const Test& t) {
        os<<"Czesc int: "<<t._poleInt<<" Czesc double: "<<t._poleDouble<<"\n" ;
        return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Test>& t) {
    for (const auto& a: t)
        os<<a;

    return os;
}

class Wiekszy {
    // jezeli true to sortujemy po double jezeli false to po int
    bool _WyborSortowania = false;
    public:
    Wiekszy() = default;
    Wiekszy(bool wybor):_WyborSortowania(wybor) {}
    bool operator()(const Test &t1,const Test &t2) {
        if (_WyborSortowania) {
            return t1._poleDouble > t2._poleDouble;
        }
            return t1._poleInt > t2._poleInt;
    }
    void setWyborSortowania(bool wybor) {
        _WyborSortowania = wybor;
    }
};

int main () {

    std::vector<Test> tests(5);
    Wiekszy wiekszy(false);

    std::cout<<"Przed posorotwaniem:\n";
    std::cout<<tests;

    //std::cout<<"Sortwaonie dla int: (double lsowe) w ramach testu tylko to pisze\n";
    std::cout<<"Sorotwanie dla int:\n";
    std::sort (tests.begin(), tests.end(), wiekszy);
    std::cout<<tests;
    // for (auto & [intValue,doubleValue]: tests) {
    //     std::cout<<intValue<<" "<<doubleValue<<"\n";
    // }

    wiekszy.setWyborSortowania(true);
    std::cout<<"Sorotwanie dla double:\n";
    //std::cout<<"\nSortwaonie dla double: (int lsowe) w ramach testu tylko to pisze\n";
    std::sort (tests.begin(), tests.end(), wiekszy);
    std::cout<<tests;

    // for (auto & [intValue,doubleValue]: tests) {
    //     std::cout<<intValue<<" "<<doubleValue<<"\n";
    // }
    return 0;
}