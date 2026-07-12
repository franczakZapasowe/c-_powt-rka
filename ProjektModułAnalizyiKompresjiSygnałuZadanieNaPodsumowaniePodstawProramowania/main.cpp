#include <iostream>
#include <random>
#include <cassert>
#include <algorithm>
#include <limits.h>

const double epsilon = 1e-5;

struct SygnalAudio {
    int sampleRate = 44100;
    double trwania = 0.0;
    int glebiaBitowa = 24;
    double *probki = nullptr;
};

void wypelnienieStruktury(SygnalAudio &audio, int czestotliowsc, double czas) {
    assert(audio.probki != nullptr);
    if (audio.sampleRate <= 0) throw std::invalid_argument("");
    long iloscProbek = czestotliowsc * czas;
    if (iloscProbek> LONG_MAX) throw std::length_error("");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-5.0, 5.0);
    for (int i = 0; i < iloscProbek; i++) {
        audio.probki[i] = sin(dis(gen));
    }
}

double ocenaKompresji(double probki[], long rozmiar, double prog) {
    assert(probki != nullptr);
    assert(rozmiar > 0);
    double kara = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (fabs(probki[i]) <= prog) {
            kara+=prog;
        }else
            kara+=100;
    }
    return kara;
}

void testDetektora() {
    double tab [5] = {0.0, 1.0, 2.0, 1.0, 0.0};
}

void czysc () noexcept {
    std::cerr<<"Wyczyszczono\n ";
}
int main() {
    SygnalAudio audio;
    audio.sampleRate = 44100;
    audio.trwania = 1.0;
    audio.glebiaBitowa = 24;
    long rozmar = audio.sampleRate * audio.trwania;
    audio.probki = new double[rozmar];
    double *pochodna = new double[rozmar];
    try {
        wypelnienieStruktury(audio, audio.sampleRate, audio.trwania);
        std::cerr<<"Wypelniono pomyslnie\n";
    } catch (std::invalid_argument) {
        std::cerr<<"sample rate must be greater than zero\n";
        return 1;
    } catch (std::length_error) {
        std::cerr<<"iloscProbek must be smaller than LONG_MAX\n";
        return 1;
    }

//#define DETEKTOR
#ifdef DETEKTOR
    double dt = 1.0/ audio.sampleRate;
    const double mnozik = 1.0 / (2.0 * dt);
    for (int i = 1; i < rozmar-4; i+=4) {
        pochodna[i] = (audio.probki[i+1] - audio.probki[i-1]) *mnozik;
        pochodna[i+1] = (audio.probki[i+2] - audio.probki[i]) *mnozik;
        pochodna[i+2] = (audio.probki[i+3] - audio.probki[i+1]) *mnozik;
        pochodna[i+3] = (audio.probki[i+4] - audio.probki[i+2]) *mnozik;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.1, 1.0);
    int stagnacja = 0, maxStagnacja = 1000, iter = 0;
    double ocena_poczatkowa = 1000000.0 , prog = 0.0, prog_finlany = 0.0;

    for (iter = 0; iter < rozmar && stagnacja<maxStagnacja; iter++) {
        prog = dis(gen);
        double ocena = ocenaKompresji(audio.probki, rozmar, prog);
        if (ocena<ocena_poczatkowa) {
            ocena_poczatkowa = ocena;
            prog_finlany = prog;
            stagnacja=0;
        }else
            stagnacja++;
    }
    std::cerr<<"Minimalny prog to: "<<prog_finlany<<"\n";

//     1. **Tryb Testowy (`#ifdef TEST`):**
// * Cały detektor różniczkowy i struktury mają być oflagowane dyrektywami preprocesora.
// * Przed napisaniem pętli z różniczką, zdefiniuj twarde testy jednostkowe z użyciem tolerancji błędu `eps`.
//  Sprawdź m.in. czy detektor poprawnie wyliczy pochodną ze sztucznie wygenerowanej,
//  idealnie trójkątnej fali (gdzie prędkość zmiany jest stała).
#endif

    czysc();
    delete [] audio.probki;
    audio.probki = nullptr;
    delete [] pochodna;
    pochodna = nullptr;

    return 0;
}