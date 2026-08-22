#include<iostream>
#include <vector>
#include<array>
#include <ranges>
#include <string>
#include  <cctype>

struct Pracownik {
    std::string imie;
    int pensja;

};
int main() {
    std::cout<<"ZADANIE 1\n__________________________________\n";
    std::array<int,20>tab;
    for (int i=0;i<20;i++) {
        tab[i]=i+1;
        std::cout<<tab[i]<<" ";
    }

    auto patrzyste = [](int v ) {
        return v%2==0;
    };

    auto zad1Widok = tab
    | std::views::filter(patrzyste)
    | std::views::transform([](int v) {return v*10;});
    std::cout<<"\n";
    for (auto a: zad1Widok) std::cout<<a<<" ";

    std::cout<<"\nZADANIE 2\n__________________________________\n";

    std::string zdanie = "Lubie jesc pizze bardzo";
    std::cout<<zdanie<<"\n";

    auto zdanieFinalne = zdanie
                        | std::views::drop(5)
                        | std::views::take(6)
                        | std::views::transform([](char c) ->char {
                            return std::toupper(c);
                        });

    for (auto x : zdanieFinalne) std::cout<<x;

    std::cout<<"\nZADANIE 3\n__________________________________\n";
    auto wynik = std::views::iota(1)|
                std::views::filter([](int  v) {
                    return v%3==0;
                }) |
                    std::views::transform([](int v) {
                        return v*v;
                    })|
                        std::views::take(5);
   for (auto x: wynik)
        std::cout<<x<<" ";

    std::cout<<"\nZADANIE 4\n__________________________________\n";

    std::vector<Pracownik> pracowninicy = {{"Adam",5000},
        {"artur",5500},{"kamil",2200},
        {"alojzy",4000},{"janusz",55000}};


    auto pracownicyWynik = pracowninicy |
                            std::views::filter([ ](Pracownik p) {
                                return p.pensja>5000;
                            }) | std::views::transform([](Pracownik p) -> std::string {
                                return p.imie;
                            });

    for (auto a: pracownicyWynik)
        std::cout<<a<<" ";

}
