#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <random>
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


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2000000);
    int rozmiarBzowy = 50;
    uint64_t *rejestrWadliwych = new uint64_t[rozmiarBzowy];
    for (int i=0;i<rozmiarBzowy;i++) {
        //do skonczoneia
        rejestrWadliwych[i] = dodajRekord(distrib(rd),i+1,i+2,i+3);
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

            memcpy(rejestTymczasowy,rejestrWadliwych,rozmiarBzowy*sizeof(int));

            delete[] rejestrWadliwych;
            rejestrWadliwych = rejestTymczasowy;
            rejestrWadliwych = nullptr;
            rozmiarBzowy = rozmiarTymczasowy;
        }

        fread(&rejestrWadliwych[i],sizeof(uint64_t),1,plik);
        fwrite(&rejestrWadliwych[i],sizeof(uint64_t),1,plik2);
        if (i) {
            fseek(plik,-sizeof(rejestrWadliwych[0]),SEEK_CUR);
        }
        i++;
    }
    fclose(plik);
    delete[] rejestrWadliwych;
}

uint64_t dodajRekord(uint64_t nr,uint64_t odchylenie,uint64_t temperatura,uint64_t status  ) {
    uint64_t rekod;
    uint64_t maskaNr = 1048575;
    uint64_t maskaOdchyleni = 4095;
    uint64_t maskaTemperatura = 65535;
    uint64_t maskaStatus = 255;

    odchylenie = (odchylenie>>20);
    temperatura = (temperatura>>32);
    status = (status>>48);

    nr&= maskaNr;
    odchylenie &=maskaOdchyleni;
    temperatura &= maskaTemperatura;
    status &= maskaStatus;

    odchylenie = (odchylenie<<20);
    temperatura = (temperatura<<32);
    status = (status<<48);

    rekod = nr | odchylenie | temperatura | status ;
    return rekod ;
}