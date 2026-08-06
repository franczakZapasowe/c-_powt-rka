#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <filesystem>
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
void edytujRekod(uint64_t& r,FILE*p);
bool  weryfiukujRekord(uint64_t rekord);

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2000000);
    std::uniform_int_distribution<> distrib2(0, 6000);
    std::uniform_int_distribution<> distrib3(0, 65535);
    uint64_t *wszystkieDane = new uint64_t[50];

    FILE * plik = fopen("wszystkiedane.bin","w+b");

    // za
    for (int i=0;i<50;i++) {
        wszystkieDane[i] = dodajRekord(distrib(rd),distrib2(rd),distrib3(gen),0b01011110);
        fwrite(&wszystkieDane[i],sizeof(wszystkieDane[i]),1,plik);
    }
    delete []wszystkieDane;

    FILE * plikTymczasowy = fopen("poprawneDane.bin","w+b");
    FILE * plikFinalny = fopen("final.txt","w");
    int rozmiarBzowy = 5;
    uint64_t *rejestrWadliwych = new uint64_t[rozmiarBzowy];

    int licznikWczytanych = 0;
    uint64_t rekordPojedynczy = 0;
    rewind(plik);
    while (true) {

        // odczytuje element z pliku 1 i zapisuje je do tablicy

        fread(&rekordPojedynczy,sizeof(uint64_t),1,plik);
        if (feof(plik)) break;
        if (weryfiukujRekord(rekordPojedynczy)) {
            // jezeli pomyslnie przejdzie weryfikacje to mzienamy go w orginalnym pliku jak nie to zapisuemy to do tablicy wadliwych
            fseek(plik,-sizeof(rejestrWadliwych[0]),SEEK_CUR);
            edytujRekod(rekordPojedynczy,plik);
        }else {
            rejestrWadliwych[licznikWczytanych] = rekordPojedynczy;
            licznikWczytanych++;
        }

        // mechanizm odpowiedzalny za zwiekszanie rozmiaru tablicy
        if (rozmiarBzowy - licznikWczytanych == 1) {
            int rozmiarTymczasowy = rozmiarBzowy * 2;
            uint64_t * rejestTymczasowy = new uint64_t [rozmiarTymczasowy];

            memcpy(rejestTymczasowy,rejestrWadliwych,rozmiarBzowy*sizeof(uint64_t));

            delete[] rejestrWadliwych;
            rejestrWadliwych = rejestTymczasowy;
            rejestTymczasowy = nullptr;
            rozmiarBzowy = rozmiarTymczasowy;
        }
    }

    //zapis do nowego pliku
    for (int i=0;i<licznikWczytanych;i++) {
        //do dokonczenias
        uint64_t nr, odchylenie,temperatura,bledy;
        uint64_t maskaNr = 1048575;
        uint64_t maskaOdchyleni = 4095;
        uint64_t maskaTemperatura = 65535;
        uint64_t maskaStatus = 255;

        nr = rejestrWadliwych[i];
        odchylenie = rejestrWadliwych[i]>>20;
        temperatura = rejestrWadliwych[i]>>32;
        bledy = rejestrWadliwych[i]>>48;

        nr &= maskaNr;
        odchylenie &= maskaOdchyleni;
        temperatura &= maskaTemperatura;
        bledy &= maskaStatus;

        fprintf(plikFinalny,"Nr.%llu;Odchylenie:%llu;temperatura%llu;bledy%llu;\n", nr,odchylenie,temperatura,bledy);
    }

    fclose(plik);
    fclose(plikFinalny);
    fclose(plikTymczasowy);

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
bool weryfiukujRekord(uint64_t rekord) {
     //ODCHYLENIEWYMIAROWESTALE
    uint64_t rekordStatusow = rekord;
    uint64_t rekordBledow = rekord;
    uint64_t rekordOdchylenie = rekord;
    uint64_t rekodFlagiInspekcji = rekord;

    uint64_t maskaSzczelonosciIObwodow = 0b00000011;
    uint64_t maskaOdchylenie = 4095;
    uint64_t maskaBledow = 0b01111000;
    uint64_t maskaInspekcji = 1;

    rekordStatusow = rekordStatusow >> 48;
    rekordOdchylenie = rekordOdchylenie >> 20;
    rekordBledow = rekordBledow>>48;
    rekodFlagiInspekcji = rekodFlagiInspekcji>>50;



    uint64_t testJedn = rekordStatusow & maskaSzczelonosciIObwodow;
    uint64_t test2 = rekordBledow &= maskaBledow;
    uint64_t test3 = maskaInspekcji&rekodFlagiInspekcji;


    if ((testJedn == 3 ) &&  ((rekordOdchylenie&maskaOdchylenie) < ODCHYLENIEWYMIAROWESTALE || test3 == 0) && (test2==0))  {
        return true;
    }

    return false;
}
void edytujRekod(uint64_t& r,FILE*p) {
    uint64_t maska = 1ULL<<55;
    r|=maska;
    fwrite(&r,sizeof(r),1,p);
}