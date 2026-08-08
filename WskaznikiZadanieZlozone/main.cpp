#include <iostream>

void hardClip(double* probka) {
    if(*probka > 0.8) *probka = 0.8;
    std::cout << "HardClip nalozony. Wartosc: " << *probka << "\n";
}

class ProcesorDSP {
public:
    void odwrocFaze(double& probka) {
        probka *= -1.0;
        std::cout << "Faza odwrocona. Wartosc: " << probka << "\n";
    }
};

// --- MIEJSCE 1 DO UZUPEŁNIENIA ---
// 3. Glowna funkcja sterujaca matrycą
void odpalMatryce(
    double**& aktywnyWskaznik,                  // Referencja do wskaźnika na wskaźnik
    void (*efektZewn)(double*),                 // Wskaźnik na zwykłą funkcję
    ProcesorDSP* procesor,                      // Surowy wskaźnik na instancję klasy
    void (ProcesorDSP::*efektWewn)(double&)     // Wskaźnik na metodę klasy
) {
    // TODO 1: Wywołaj funkcję ukrytą pod wskaźnikiem 'efektZewn' na aktualnej próbce
    // (próbka jest ukryta pod 'aktywnyWskaznik').
        (*efektZewn)(*aktywnyWskaznik);
    // TODO 2: Wywołaj metodę ukrytą pod wskaźnikiem 'efektWewn' na tej samej próbce,
    // korzystając z przekazanego wskaźnika 'procesor'. Pamiętaj o dereferencjach!
        (procesor->*efektWewn)(**aktywnyWskaznik);
    // TODO 3: Przestaw 'aktywnyWskaznik' tak, aby wskazywał na kolejny
    // element w tablicy wskaźników w main (przesuń go o 1 pozycję w pamięci).
    aktywnyWskaznik++;
}

// --- MIEJSCE 2 DO UZUPEŁNIENIA ---
int main() {
    // TODO 4: Stwórz surową tablicę: double pasma[3] = {1.2, -0.5, 0.9};
    double pasma[3] = {1.2, -0.5, 0.9};
    // TODO 5: Stwórz tablicę wskaźników: double* krosownica[3].
    // Każdy jej element ma wskazywać na odpowiadający mu element tablicy 'pasma'.
        double * krosownica[3] = {&pasma[0], &pasma[1], &pasma[2]};
    // TODO 6: Stwórz wskaźnik na wskaźnik o nazwie 'selektor'.
    // Na starcie ma on wskazywać na pierwszy element tablicy 'krosownica'.
        double **selektor = &krosownica[0];
    // TODO 7: Utwórz wskaźnik na funkcję 'hardClip' i przypisz mu odpowiedni adres.
        void (*wskHardClip)(double*) = hardClip;
    // TODO 8: Utwórz dynamicznie (lub statycznie i pobierz adres) instancję klasy 'ProcesorDSP'.
        ProcesorDSP *procesor = new ProcesorDSP();
    // TODO 9: Utwórz wskaźnik na metodę 'odwrocFaze' z klasy 'ProcesorDSP'.
        void (ProcesorDSP::*wskaznik)(double& probka) = &ProcesorDSP::odwrocFaze;
    // TODO 10: Wywołaj funkcję 'odpalMatryce', przekazując jej selektor,
    // wskaźnik na funkcję, wskaźnik na obiekt i wskaźnik na metodę.
        odpalMatryce(selektor,wskHardClip,procesor,wskaznik);
    // Opcjonalnie: wywołaj 'odpalMatryce' drugi raz, żeby udowodnić,
    // że w TODO 3 poprawnie przesunąłeś 'selektor' na drugą próbkę (-0.5).
        delete procesor;
    return 0;
}