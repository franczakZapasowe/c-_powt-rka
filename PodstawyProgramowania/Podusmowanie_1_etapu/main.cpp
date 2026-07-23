#include<iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
int main(){

    //--------------- KROK 1
    constexpr int PAKIETY = 15; 
    double telemetria [PAKIETY][3] = {};

    for (int i = 0; i < PAKIETY; i++){
        for(int j = 0; j < 3; j++){
            if(j==0){
                telemetria[i][j] = i+1;
            }else if(j == 1){
                //(max - min +1 ) +min - losowanie z przedziału (500 - (-50) +1) + (-50)
                telemetria[i][j] = rand()% 551 - 50;
            }else{
                telemetria[i][j] = rand()% 201;
            }
        }
    }

    //----------------KROK 2
    int liczba_elementow = PAKIETY * 3;
    double *wsk = &telemetria[0][0];
    for (int i = 0; i<liczba_elementow; i++, wsk++){
        if(*(wsk) < 0.0 ) *wsk = 0.0;
    }

    //---------------KROK 3    
    double*widok[PAKIETY] = {
        &telemetria[0][0],
        &telemetria[1][0],
        &telemetria[2][0],
        &telemetria[3][0],
        &telemetria[4][0],
        &telemetria[5][0],
        &telemetria[6][0],
        &telemetria[7][0],
        &telemetria[8][0],
        &telemetria[9][0],
        &telemetria[10][0],
        &telemetria[11][0],
        &telemetria[12][0],
        &telemetria[13][0],
        &telemetria[14][0]
    };
    
    //---------------KROK 4
    for (int i = 0; i < PAKIETY; i++){
        for(int j = 1; j < PAKIETY; j++){
            if((widok[j][1]) > (widok[j-1][1])){
                std::swap(widok[j],widok[j-1]);
            }
        }
    }   
    
    //---------------KROK 5
    double czarnaSkrzynka[3]={};
    double *wz = czarnaSkrzynka;

    for(int i = 0; i < 3; i++){
        (*wz++ = widok[i][0]);
        if(wz>=czarnaSkrzynka+3) wz = czarnaSkrzynka;
    }

    //----------------KROK 6
    std::cout<<"3 znaczniki czasu, w których dron znajdował się najwyżej:\n";
    for(int i =0; i<3; i++){
        std::cout<<i<<". "<<czarnaSkrzynka[i]<<" (s)\n";
    }
    return 0;
}