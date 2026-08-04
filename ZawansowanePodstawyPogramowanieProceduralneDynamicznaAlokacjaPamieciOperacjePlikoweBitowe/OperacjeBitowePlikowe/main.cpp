#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;

//#define ZADANIE1
//#define ZADANIE2
#define ZADANIE3
#ifdef ZADANIE1
namespace stany {
    enum  {
        wentylacja = (1<<0 | 1<<1 | 1<<2),
        oswietlenie = (1<<3),
        alarm = (1<<4 | 1<<5),
        bledy = (1<<6 | 1<<7)
    };
}
void pokaz(__uint8_t r);
void swiatlo(__uint8_t r);
void wypisz(__uint8_t r);
void wentylacja(__uint8_t r);
void bledy(__uint8_t r);
void alarmy(__uint8_t);

__uint8_t kompresujStany(int,int,int,int);
void przelaczSwiatlo(__uint8_t&r);
void dekompresujStany(__uint8_t r);

int main() {
    __uint8_t rejestr = 0b00110110;
    pokaz(rejestr);
    rejestr = kompresujStany(15,1,3,0);
    pokaz(rejestr);
    przelaczSwiatlo(rejestr);
    pokaz(rejestr);
    przelaczSwiatlo(rejestr);
    pokaz(rejestr);
    dekompresujStany(rejestr);

    cout<<endl;
    wypisz(rejestr);
    rejestr = kompresujStany(19,0,2,11);
    cout<<endl;
    wypisz(rejestr);
    return 0;
}

void pokaz(__uint8_t r) {
    cout<<"Stan: "<<bitset<8>(r)<<endl;
}
void swiatlo(__uint8_t r) {
    __uint8_t maska = 1;
    r = (r>>3)&maska;
    if (r) cout<<"Swiatlo wlaczone\n";
    else cout<<"Swiatlo wyloczone\n";
}

__uint8_t kompresujStany(int wentylacja, int swiatlo, int alarm, int blad) {
    __uint8_t wynik;
    __uint8_t maskaWentylacja = 0b111;
    __uint8_t maskaSwiatlo = 0b1;
    __uint8_t maskaAlarm = 0b11;
    __uint8_t maskaBlad = 0b11;

    wentylacja &= maskaWentylacja;
    swiatlo &= maskaSwiatlo;
    alarm &= maskaAlarm;
    blad &= maskaBlad;

    swiatlo = (swiatlo<<3);
    alarm = (alarm<<4);
    blad = (blad<<6);

    wynik = wentylacja | swiatlo | alarm | blad;
    return wynik;
}
void przelaczSwiatlo(__uint8_t&r) {
    __uint8_t maska = 0b00001000;
    r^= maska;
}
void dekompresujStany(__uint8_t r) {
    r = (r>>4) & 0b00000011;
    cout<<"Tryb alarmu:\n";
    if (r == 3) cout << "Tryb czuwania alarmu: Uzbrojony\n";
    else if (r == 2) cout << "Tryb czuwania alarmu: NOC\n";
    else if (r == 1) cout << "Tryb czuwania alarmu: DOM\n";
    else cout << "Dom rozbrojony\n";
}

void wentylacja(__uint8_t r) {
    r = r & 0b111;
    if (r<=7) {
        if (r == 0) cout<<"Wentylacja wylaczona\n";
        else
            cout<<"Wentylacja ustawiona na: "<<r<<endl;;
    }
}

void bledy(__uint8_t r) {
    __uint8_t maska = 0b11;
    r = (r>>6)&maska;
    if (r!=0) cout<<"Awaria\n";
    else cout<<"Brak awari";
}
void alarmy(__uint8_t r) {
    r = (r>>4)&0b11;
    if (r == 3)cout<<"Dom uzbrojony\n";
    else if (r == 2)cout<<"Noc tryb czuwania\n";
    else if (r == 1)cout<<"Dom tryb czuwania \n";
    else cout<<"Dom rozbrojony\n";
}

void wypisz(__uint8_t r) {
    pokaz(r);
    wentylacja(r);
    swiatlo(r);
    alarmy(r);
    bledy(r);
}

#endif

#ifdef ZADANIE2
struct Czujnik {
    int id_strefy;
    double temperatura;
    double wilgotnosc;
};

ostream& operator<<(ostream& os, Czujnik& cz) {
    os<<"Id strefy: "<<cz.id_strefy<<endl;
    os<<"Temperatura: "<<cz.temperatura<<endl;
    os<<"Wilgotnosc: "<<cz.wilgotnosc<<endl;
    return os;
}

void zapisz(Czujnik*, FILE*plik, int rozmiar = 3 );
void odczytaj(Czujnik*, FILE*plik);
void wypelnij (Czujnik&, int,double,double);


int main() {


    Czujnik tablicaCzujnikow[3];
    wypelnij(tablicaCzujnikow[0], 3, 0.5, 20.5);
    wypelnij(tablicaCzujnikow[1], 6, 1.5, 420.5);
    wypelnij(tablicaCzujnikow[2], 41, 6.5, 11.5);
    Czujnik tablicaCzujnikow2[3]={};


    FILE *plik = fopen("dane.txt", "w+");
    zapisz(tablicaCzujnikow, plik);
    rewind(plik);
    odczytaj(tablicaCzujnikow2,plik);
    for (int i = 0; i < 3; i++) {
        cout<<"Czujnik: "<<i<<endl;
        cout<<tablicaCzujnikow2[i];
    }
    fclose(plik);
    return 0;
}

void zapisz(Czujnik *czujniki, FILE*plik,int rozmiar) {
    for (int i=0; i<rozmiar; i++) {
        fprintf(plik,"%d;%lf;%lf;\n", czujniki[i].id_strefy,czujniki[i].temperatura,czujniki[i].wilgotnosc);
    }
}

void wypelnij (Czujnik& czujnik, int s,double t,double w) {
    czujnik.id_strefy = s;
    czujnik.temperatura = t;
    czujnik.wilgotnosc = w;
}


void odczytaj(Czujnik  *czujniki, FILE*plik) {
    int strefa = 0; double temperatura = 0.0, wilgotnosc = 0.0;
    for (int i=0; i<3; i++) {
        fscanf(plik,"%d;",&strefa);
        fscanf(plik,"%lf;",&temperatura);
        fscanf(plik,"%lf;",&wilgotnosc);
        wypelnij(czujniki[i],strefa,temperatura,wilgotnosc);
    }
}

#endif

#ifdef ZADANIE3
struct LogZasilania {
    int timestamp;
    double zuzycie_kWh;
};

int main() {
    LogZasilania logi[5]={};
    double zuzycie = 0.0;
    for (int i = 0; i < 5; i++, zuzycie+=0.1 ) {
        logi[i].timestamp = i;
        logi[i].zuzycie_kWh = zuzycie;
    }
    FILE *plik = fopen("pomiar.txt","w+b");
    fwrite(logi, sizeof(LogZasilania),5,plik);
    rewind(plik);

    LogZasilania temp;
    while (true) {
        fread(&temp,sizeof(LogZasilania),1,plik);
        if (feof(plik)) break;
        if (temp.timestamp == 3) {
            fseek(plik,-(long)sizeof(LogZasilania),SEEK_CUR);
            break;
        }
    }
    temp.zuzycie_kWh = 922.3;
    fwrite(&temp,sizeof(LogZasilania),1,plik);
    fclose(plik);
}

#endif
