#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <random>
constexpr int ODCHYLENIEWYMIAROWESTALE = 100;
namespace rekord {
    enum {
        numerCzesci,
        odchylenieWymiarowe = (1<<20),
        temperaturaPracy = (1ULL<<32),
        rejestrStatusow = (1ULL<<48),
        zarezerwowaneSystem = (1ULL<<56)
    };
}

uint64_t dodajRekord(uint64_t,uint64_t,uint64_t,uint64_t);
void edytujRekod(uint64_t&,int);
bool  weryfiukujRekord(uint64_t&rekord);

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2000000);
    std::uniform_int_distribution<> distrib2(0, 6000);
    std::uniform_int_distribution<> distrib3(0, 65535);
    int rozmiarBzowy = 50;
    uint64_t *rejestrWadliwych = new uint64_t[rozmiarBzowy];
    for (int i=0;i<rozmiarBzowy;i++) {
        //do skonczoneia
        rejestrWadliwych[i] = dodajRekord(distrib(rd),distrib2(rd),distrib3(gen),0b01011110);
    }
    FILE * plik = fopen("wszystkiedane.txt","w+b");
    FILE * plik2 = fopen("poprawneDane.txt","w+b");
    int i = 0;
    while (!feof(plik)) {
        // Zarządzanie Pamięcią Operacyjną (RAM)
    int rozmiarSprawdzany = sizeof(rejestrWadliwych)/sizeof(rejestrWadliwych[0]);
        if (rozmiarBzowy - rozmiarSprawdzany == 1) {
            int rozmiarTymczasowy = rozmiarBzowy * 2;
            uint64_t * rejestTymczasowy = new uint64_t [rozmiarTymczasowy];

            memcpy(rejestTymczasowy,rejestrWadliwych,rozmiarBzowy*sizeof(uint64_t));

            delete[] rejestrWadliwych;
            rejestrWadliwych = rejestTymczasowy;
            rejestrWadliwych = nullptr;
            rozmiarBzowy = rozmiarTymczasowy;
        }

        fread(&rejestrWadliwych[i],sizeof(uint64_t),1,plik);
        fwrite(&rejestrWadliwych[i],sizeof(uint64_t),1,plik2);
        if (weryfiukujRekord(rejestrWadliwych[i])) {
            fseek(plik,-sizeof(rejestrWadliwych[0]),SEEK_CUR);
        }
        i++;
    }

    //zapis do nowego pliku
    for (int i=0;i<rozmiarBzowy;i++) {
        fprintf(plik2,"%d;\n",rejestrWadliwych[i]);
    }

    fclose(plik);
    fclose(plik2);
    delete[] rejestrWadliwych;
}

uint64_t dodajRekord(uint64_t nr,uint64_t odchylenie,uint64_t temperatura,uint64_t status  ) {
    uint64_t rekod;
    uint64_t maskaNr = 1048575;
    uint64_t maskaOdchyleni = 4095;
    uint64_t maskaTemperatura = 65535;
    uint64_t maskaStatus = 255;

    nr &= maskaNr;
    odchylenie &= maskaOdchyleni;
    temperatura &= maskaTemperatura;
    status &= maskaStatus;

    odchylenie = (odchylenie<<20);
    temperatura = (temperatura<<32);
    status = (status<<48);

    rekod = nr | odchylenie | temperatura | status ;
    return rekod ;
}
bool weryfiukujRekord(uint64_t& rekord) {
    uint64_t tempDlaOdchylenia = rekord;
    rekord = (rekord>>48);
    uint64_t maska = 0b01111111;

    uint64_t maskaOdchyleni = 4095;
    tempDlaOdchylenia  = (tempDlaOdchylenia>>20);
    tempDlaOdchylenia &=maskaOdchyleni;

    if ((maska&rekord) && (tempDlaOdchylenia > ODCHYLENIEWYMIAROWESTALE)) {
        //zmiana bitu flagi nie jest juz podejrzany
        // zmiana flagi przetworzenia
        uint64_t maskaFlagi = 0b10000100;
        rekord ^= maskaFlagi;
        rekord = (rekord<<48);
        return true;
    }
    return false;
}
