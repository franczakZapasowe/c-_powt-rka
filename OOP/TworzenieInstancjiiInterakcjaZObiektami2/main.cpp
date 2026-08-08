#include<iostream>
#include "ProbkaAudio.h"
#include "SilnikDSP.h"

using TypWskaznika = void(ProbkaAudio::*)();

int main(){

	ProbkaAudio p(5);
	std::cout<<"Przed:\n";
	std::cout<<p.getWatoscProbki();

	TypWskaznika tablica[] = {&ProbkaAudio::aplikujFilter,&ProbkaAudio::aplikujFilter,&ProbkaAudio::odwrocFaze};

	SilnikDSP::przetworzLancuch(p,tablica,3);
	std::cout<<"\nPo:\n";
	std::cout<<p.getWatoscProbki();


	return 0;
}
