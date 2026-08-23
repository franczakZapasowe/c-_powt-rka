#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <random>

bool oddaj(int v) {
    return v == 0;
}



int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>dis (1,20);
    std::list<int> lista;

    while (true) {
        auto liczba = dis(gen);
        lista.push_front(liczba);

        if ( std::count(lista.begin(), lista.end(), liczba)>1)
            break;
    }

    lista.sort();
    lista.unique();
    std::vector<int>wektor;
    wektor.resize(lista.size());
    lista.reverse();
    std::copy(lista.begin(),lista.end(),wektor.begin());

    std::cout<<"\nwektor\n";
    for (const auto &l:wektor) std::cout<<l<<" ";


    std::replace_if(wektor.begin(),wektor.end(),[](int v) {return v%2!=0;},0);

    std::cout<<"\nwektor\n";
    for (const auto &l:wektor) std::cout<<l<<" ";

    auto nowyKOniec = std::remove_if(wektor.begin(),wektor.end(),[](int v){
        return v==0;
    });
    wektor.erase(nowyKOniec,wektor.end());

    std::cout<<"\nwektor\n";
    for (const auto &l:wektor) std::cout<<l<<" ";
    return 0;
}




