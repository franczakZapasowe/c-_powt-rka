#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <tuple>
#include <random>

template<typename T>
std::ostream & operator << (std::ostream &str, const std::vector<T>&vector){
    for(auto&e:vector) str<<e<<", ";
    return str;
}


template<typename T, typename C>
void funckcjaLambdaPrzekazanie(const std::vector<T> &v, C operacja){
    for (auto val: v){
        std::cout<<operacja(val);
    }
}

std::tuple<std::string,int >CreatePerson(){
    return {"mf",23};
}

int main (){


    std::cout<<"Sortowanie malejaco:\n";
    std::vector<double> freqs = {1000.5, 250.0,5000.0, 60.0, 12000.0 };
    std::cout<<freqs;
    std::sort(freqs.begin(),freqs.end(), [](double a, double b){
        return a>b;
    });
    std::cout<<std::endl;
    std::cout<<freqs;

    std::cout<<"\n________________________\nFunkcja find if\n";

    std::vector<float> buffer = {0.1f, -0.4f, 0.95f, -0.2f, 1.1f, 0.0f};
    auto it = std::find_if(buffer.begin(),buffer.end(), [] (auto val){
        return val>1.0f;
    });
    if(it!=buffer.end())
    std::cout<<"Clipping: "<<*it<<"\n";

    std::cout<<"________________________\nFunkcja transform\n";
    std::vector<float> signal = {0.2f, -0.1f, 0.5f, 0.8f};
    std::cout<<signal;
    std::transform(signal.begin(),signal.end(),signal.begin(), [] (auto val){
        return val*1.5f;
    });
    std::cout<<"\n";
    std::cout<<signal;

    std::cout<<"\n________________________\nFunkcja accumulate\n";
    std::vector<float> samples = {-0.5f, 0.5f, -0.2f, 0.8f};
    auto lamba = std::accumulate(samples.begin(), samples.end(), 0.0f,
     [] (auto wynik, const auto &val){
        return wynik + std::abs(val);
    });
    std::cout<<lamba<<"\n";

    std::vector<std::string> words = {"Nowoczesny", "C++", "jest", "bardzo", "wydajny"};
    auto zdanie = std::accumulate(words.begin(),words.end(), std::string(""),
    [](std::string wynik,const std::string &slowo){
        if(wynik.empty()){
            return slowo;
        }else{
            return wynik+" "+ slowo;
        }
    });
    std::cout<<zdanie;




    std::cout<<"\n________________________\nClamp\n";
    std::vector<float> audio = {1.2f, -1.5f, 0.5f, 0.9f, -0.1f};
    std::transform(audio.begin(),audio.end(),audio.begin(),
    [](auto val){
        return std::clamp(val, 1.0f, 2.0f);
    });


    std::cout<<"\n________________________\nFunckja Wskaznik\n";
    std::vector<float> audio2 = {1.2f, -1.5f, 0.5f, 0.9f, -0.1f};
    float gain = 3.4f;
    funckcjaLambdaPrzekazanie(audio2, [gain](float x){
        return x*gain;
    });
    std::cout<<audio2;

    std::cout<<"\n________________________\nStructure Binding\n";

    // stara wersja - SŁABA!!!!!!!!!!!1
    auto person = CreatePerson();
    auto name = std::get<0>(person);


    auto [namee,angee]= CreatePerson();
    std::cout<<"Name: "<<namee;
    std::cout<<"\nAge: "<<angee;


    std::cout<<"\n________________________\nRANDOM + GENERATE\n";
    std::vector<int> inty = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>dist(1,100);
    std::cout<<"przed: "<<inty<<"\n";
    std::generate(inty.begin(),inty.end(),
    [&](){
        return dist(gen);
    });
    std::cout<<"po: "<<inty<<"\n";

    std::cout<<"\n________________________\nRANDOM + count if\n";

    std::vector<double>doublevec(100);
    std::uniform_real_distribution<double>distDobule(-1.0,1.0);
    std::generate(doublevec.begin(),doublevec.end(),[&](){
        return distDobule(gen);
    });
    int ile = std::count_if(doublevec.begin(),doublevec.end(),[](auto v){
        return v>0.5;
    });
    std::cout<<"Wartosci wiekszych niz 0.5: "<<ile<<"\n";

    std::cout<<"\n________________________\nRANDOM + erase if\n";
    std::normal_distribution<double>distNormal(100.0,15.0);
    std::vector<double> wektorek(20);
    std::generate(wektorek.begin(),wektorek.end(),[&](){
        return distNormal(gen);
    });

    std::erase_if(wektorek,[](auto val){
        return val<80.0;
    });

    std::vector<bool>vecBol(15);
    std::bernoulli_distribution dis(0.3);
    std::generate(vecBol.begin(),vecBol.end(),[&](){
        return dis(gen);
    });
    std::partition(vecBol.begin(),vecBol.end(),[](auto val){
        return val;
    });

    std::cout<<"\n\n";
    std::cout<<std::boolalpha;
    for(auto a: vecBol){
        std::cout<<a<<" ";
    }


    std::cout<<"\n\n--------------------\nPomiar czasu\n";
    std::chrono::high_resolution_clock::now();

}