#include  <iostream>

namespace stany {
    enum  {
        // 0 0 0 0 0 0 0 0
        //   1
        wetylacja =(1<<0 | 1<<1| 1<<2),
        oswietlenie = (1<<3),
        alarm = (1<<4 | 1<<5),
        kodBledu = (1<<6 | 1<<7)
    };
}

__uint8_t kompresujStany();
void przelaczSwiatlo(__uint8_t &rej);
void dekompresuj(__uint8_t &rej);


int main () {

     __uint8_t rejstr = 0;
    return 0;
}
void przelaczSwiatlo(__uint8_t &rej) {
    rej ^= (1<<3);
    //rej 0 0 0 0 0 0 0 0
    //msk 0 0 0 0 1 0 0 0
    //wyn 0 0 0 0 0 0 0 0

}