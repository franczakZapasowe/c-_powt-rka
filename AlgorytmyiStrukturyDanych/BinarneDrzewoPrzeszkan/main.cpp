#include <iostream>

struct Wezel {
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
};

bool serch(Wezel *w, int x) {
    if (w == nullptr) return false;
    if (x == w->wartosc) return true;

    if (x < w->wartosc) return serch(w->lewy, x);
    return serch(w->prawy, x);
}

    void insert(Wezel *&w, int x) {
        if (w==nullptr) {
            w = new Wezel;
            w->wartosc = x;
            w->lewy = nullptr;
            w->prawy = nullptr;
        }else {
            if (x < w->wartosc) insert(w->lewy, x);
            else insert(w->prawy, x);
        }
    }

void usun(Wezel *&w) {
    // wprzypadku gdy nie ma dzieci
    if (w->prawy == nullptr && w ->lewy == nullptr) {}
    delete w;
    // w przypaku gdy jedno dziecko


}


int main() {}