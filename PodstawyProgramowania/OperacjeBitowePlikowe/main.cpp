#include <iostream>
#include <unistd.h>
#include <bitset>
using namespace std;

namespace stany{
    enum {
        Wentylacja =(1<<0 | 1<<1 | 1<<2),
        Oswietlenie = (1<<3),
        Alarm = (1<<4 | 1<<5),
        Bledy = (1<<6 | 1<<7),
    };
}

__uint8_t kompresujStany(int,int,int,int);
void przelaczSwiatlo(__uint8_t&rej);
void dekompresuj(__uint8_t);


int main() {

    __uint8_t rejest= 0b00101011;
    // Wentylacja wlaczana na 3 oswietlenie wlaczona, alarm - dom bledy - 0
    cout<<"Stan: "<<bitset<8>(rejest)<<endl;
    cout<<"Czy swiatlo wlaczone: "<<(bool)(rejest&stany::Oswietlenie)<<endl;
    przelaczSwiatlo(rejest);
    cout<<"Zmiana swiatla\n";
    cout<<"Czy swiatlo wlaczone: "<<(bool)(rejest&stany::Oswietlenie)<<endl;
    cout<<"Stan: "<<bitset<8>(rejest)<<endl;
    dekompresuj(rejest);

    rejest = kompresujStany(5,1,3,0);
    cout<<"Stan: "<<bitset<8>(rejest)<<endl;

}

__uint8_t kompresujStany(int wentylacja,int swiatlo,int alarm,int bledy) {
    __uint8_t maskaWentylacja = 0b111;  //0 0 0 0 0 1 1 1
    __uint8_t maskaSwitalo = 0b1; //0 0 0 0 1 0 0 0
    __uint8_t maskaAlarm = 0b11; //0 0 1 1 0 0 0 0;
    __uint8_t maskaBledy = 0b11;//1 1 0 0 0 0 0 0;

    // gdybym chcial uzyc maski z enum to powinieem najpierw przesunac potem maska
    wentylacja &= maskaWentylacja;
    swiatlo &= maskaSwitalo;
    alarm &= maskaAlarm;
    bledy &= maskaBledy;

    swiatlo = (swiatlo<<3);
    alarm = (alarm<<4);
    bledy = (bledy<<6);

    __uint8_t kombinat;

    kombinat = (wentylacja | swiatlo | alarm | bledy);
    return kombinat;
}

void przelaczSwiatlo(__uint8_t&rej) {
    __uint8_t maska = 0b1000;
    __uint8_t temp = rej;
    rej^=maska;
}

void dekompresuj(__uint8_t t) {
    __uint8_t maskaDom = 0b1;
    __uint8_t maskaNoc = 0b10;
    __uint8_t maskaUzbrojony = 0b11;
    // 0 0 1 1 0 0 1 1
    // 0 0 0 0 0 0 1 0
    t = (t>>4)&0b11;

    if ((t & maskaUzbrojony) ==3) cout<<"Dom uzbrojony\n";
    else if ((t &maskaNoc) == 2) cout<<"Alarm noc\n";
    else if ((t & maskaDom) == 1) cout<<"Alarm dom\n";
    else cout<<"Dom rozbrojony\n";
}
void wetylacja() {

}

void wypisz(__uint8_t rej) {

}