//
// Created by mf on 8/8/26.
//

#ifndef POWTORKA_PROBKAAUDIO_H
#define POWTORKA_PROBKAAUDIO_H


class ProbkaAudio {
    double m_probka;

public:
    ProbkaAudio(double probka):m_probka(probka){}
    double getWatoscProbki()const{return m_probka;}
    void aplikujKompresje() {m_probka /=2.5; }
    void aplikujFilter() {m_probka *=2.5; }
    void odwrocFaze(){m_probka *= (-1.0); }

};


#endif //POWTORKA_PROBKAAUDIO_H
