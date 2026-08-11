#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <ostream>

enum class Studia { stacjonarne = 0, niestacjonarne=1 };
enum class Stopien { inzynierski =0, magisterski =1};
enum class StopienNaukowy {mgr, dr, dr_hab, prof};

class Katedra
{
protected:
	char m_nazwa[100] = "";
public:
	Katedra(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }

	friend std::ostream& operator<<(std::ostream& os, const Katedra& k);
};
std::ostream& operator<<(std::ostream& os, const Katedra& k) {
	os<<"Katedra: "<<k.m_nazwa<<"\n";
	return os;
}

class Kierunek
{
protected:
	char m_nazwa[100] = "";
public:
	Kierunek(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }

	friend std::ostream& operator<<(std::ostream&os, const Kierunek& k);

	bool operator==(const Kierunek& k) const{
		if (strcmp(this->m_nazwa, k.m_nazwa) == 0)
		return true;
		else
			return false;
	}

	bool operator!=(const Kierunek& k)const {
		return !(*this == k);
	}

};
std::ostream& operator<<(std::ostream&os, const Kierunek& k) {
	os<<"Kierunek: "<<k.m_nazwa<<"\n";
	return os;
}

class Osoba
{
protected:
	char m_imie[30] = "";
	char m_nazwisko[40] = "";
	int m_wiek = 18;
public:
	Osoba(const char *imie, const char* nazwisko, int wiek)
	{
		setImie(imie);
		setNazwisko(nazwisko);
		setWiek(wiek);
	}
	virtual ~Osoba(){}
	void setImie(const char *imie) { strncpy(m_imie, imie, 30); }
	void setNazwisko(const char *nazwisko) { strncpy(m_nazwisko, nazwisko, 40); }
	void setWiek(int wiek) { m_wiek = (wiek > 0) ? wiek : 0; }

	const char* getImie() const { return m_imie; }
	const char* getNazwisko() const { return m_nazwisko; }
	int getWiek() const { return m_wiek; }

	friend std::ostream& operator<<(std::ostream&os, const Osoba&osoba);
};

std::ostream& operator<<(std::ostream&os, const Osoba& osoba) {
	os<<"Imie: "<<osoba.m_imie<<" nazwisko: "<<osoba.m_nazwisko<<" wiek: "<<osoba.m_wiek<<"\n";
	return os;
}

class Pracownik;
class Student :public Osoba
{
protected:
	Kierunek *m_kierunek = nullptr;
	int m_semestr = 1;
	Studia m_rodzajStudiow = Studia::stacjonarne;
	Stopien m_stopien = Stopien::inzynierski;
public:
	Student(Osoba& kandydat, Kierunek* kierunek, int semestr, Studia rodzaj, Stopien stopien)
		: Osoba(kandydat), m_kierunek(kierunek), m_rodzajStudiow(rodzaj), m_stopien(stopien)
	{
		setSemestr(semestr);
	}
	void setKierunek(Kierunek * kierunek) { m_kierunek = kierunek; }
	void setSemestr(int semestr) { m_semestr = (semestr > 0 && semestr < 8) ? semestr : 1; }
	void setRodzajStudiow(Studia rodzaj) { m_rodzajStudiow = rodzaj; }
	void setStopien(Stopien stopien) { m_stopien = stopien; }

	Kierunek* getKierunek() const { return m_kierunek; }
	int getSemestr() const { return m_semestr; }
	Studia getRodzajStudiow() const { return m_rodzajStudiow; }
	Stopien getStopien() const { return m_stopien; }
	void jakieToStudia(int n)const;
	//konwersje nieformalne
	static Student studentFromPracownik(Pracownik &pracownik,Kierunek *kierunek);\

	friend std::ostream& operator<<(std::ostream&os, const Student&student);
};

void Student::jakieToStudia(int n)const  {
	switch (n) {
		case 0:
			std::cout<<"Stacjonarne";
			break;
		case 1:
			std::cout<<"Niestacjonarne";
			break;
	}
}


std::ostream& operator<<(std::ostream&os, const Student& student) {
	os<< static_cast<const Osoba&>(student);
	os<< "Kierunek: "<<student.m_kierunek<<" semestr: "<<student.m_semestr
	<<" Rodzaj studiow: ";
	student.jakieToStudia(static_cast<int>(student.getRodzajStudiow()));
	os << " Stopien: " << (static_cast<int>(student.getStopien()) == 0 ? "Inzynierskie" : "Magisterskie");
	return os;
}

class Pracownik : public Osoba
{
protected:
	int m_stazPracy = 0;
	Katedra * m_katedra = nullptr;
	StopienNaukowy m_stopien = StopienNaukowy::mgr;
public:
	Pracownik(Osoba &osoba, Katedra * katedra, StopienNaukowy stopien)
		:Osoba(osoba), m_katedra(katedra), m_stopien(stopien)
	{}

	void zwiekszStaz() { m_stazPracy++; }
	void setKatedra(Katedra* katedra) { m_katedra = katedra; }
	void setStopienNaukowy(StopienNaukowy stopien)
	{ m_stopien = stopien; }

	int getStaz() const { return m_stazPracy; }
	Katedra* getKatedra() const { return m_katedra; }
	StopienNaukowy getStopienNaukowy() const { return m_stopien; }

	Pracownik pracownikFromStudent(Student &s,Katedra *k);
	friend std::ostream& operator<<(std::ostream&os, const Pracownik&pracownik);
};

std::ostream& operator<<(std::ostream&os, const Pracownik&pracownik) {
	os<< static_cast<const Osoba&>(pracownik);
	os<<"Staz pracy: "<<pracownik.m_stazPracy;
	if (pracownik.m_katedra!=nullptr)
	os<< "Katedra: "<<*pracownik.m_katedra;
	else
		os<<"Brak katedry";
	os<<" Stopien: ";
	switch (pracownik.m_stopien) {
		case StopienNaukowy::mgr:
			os<<"magister";
			break;
		case StopienNaukowy::dr:
			os<<"Doktor";
			break;
		case StopienNaukowy::dr_hab:
			os<<"Doktor habilitowany";
			break;
		case StopienNaukowy::prof:
			os<<"Profesor";
			break;
	}
	return os;

}

class PracownikNaukowy : public Pracownik
{
protected:
	int m_liczbaPublikacji = 0;
public:
	PracownikNaukowy(Pracownik &pracownik)
		:Pracownik(pracownik)
	{}
	void zwiekszLiczbePublikacji() { m_liczbaPublikacji++; }
	int getLiczbaPublikacji() const { return m_liczbaPublikacji; }
	friend std::ostream& operator<<(std::ostream&os, const PracownikNaukowy&pracownik);

};

std::ostream& operator<<(std::ostream&os, const PracownikNaukowy&pracownik) {
	os<<static_cast<const Pracownik&>(pracownik);
	os<<"Liczba publikacji: "<<pracownik.m_liczbaPublikacji;
	return os;
}
class PracownikDydaktyczny : public Pracownik
{
protected:
	int m_liczbaPrzedmiotow = 0;
public:
	PracownikDydaktyczny(Pracownik &pracownik, int lp) 
	: Pracownik(pracownik)
	{ 
		setLiczbaPrzedmiotow(lp); 
	}
	void setLiczbaPrzedmiotow(int lp) { m_liczbaPrzedmiotow = (lp>0) ? lp : 0; }
	int getLiczbePrzedmiotow() const { return m_liczbaPrzedmiotow; }

	friend std::ostream& operator<<(std::ostream&os, PracownikDydaktyczny&pracownikDydaktyczny);
};

std::ostream& operator<<(std::ostream&os, const PracownikDydaktyczny&pracownik) {
	os<<static_cast<const Pracownik&>(pracownik);
	os<<"Liczba przedmitow: "<<pracownik.getLiczbePrzedmiotow();
	return os;
}
Pracownik Pracownik::pracownikFromStudent(Student &s, Katedra *k) {
	return Pracownik{s,k, StopienNaukowy::mgr} ;
}

Student Student::studentFromPracownik(Pracownik &pracownik,Kierunek *kierunek) {
	return Student{pracownik,kierunek,1,Studia::niestacjonarne,Stopien::inzynierski};
}

void raportInstancji(Osoba **tablica, int rozmiar) {
	int tylkoOsoba = 0;
	int pracownik = 0;
	int student = 0;
	int pracownikDydaktyczny = 0;
	int pracownikNaukowy = 0;
	for (int i = 0; i < rozmiar; i++) {
		if (dynamic_cast<PracownikNaukowy *>(tablica[i])) pracownikNaukowy++;
		else if (dynamic_cast<PracownikDydaktyczny *>(tablica[i])) pracownikDydaktyczny++;
		else if (dynamic_cast<Pracownik *>(tablica[i])) pracownik++;
		else if (dynamic_cast<Student *>(tablica[i])) student++;
		else tylkoOsoba++;
	}
	std::cout<<"Osob - ale tylko Osob jest: "<<tylkoOsoba<<"\n"
	<<"Zwyklych Pracownikow jest: "<<pracownik<<"\n"
	<<"Studentjest: "<<student<<"\n"
	<<"Pracownikow dydaktycznych jest: "<<pracownikDydaktyczny<<"\n"
	<<"Pracownikow naukowych jest: "<<pracownikNaukowy<<"\n";
}


int main(){

	Katedra katedraInformatyki("Infromatyki");
	Katedra katedraFizyki("Fizyka");
	Kierunek kierunekInformatyki("Infromatyka");
	Kierunek kierunekFizyki("Fizyka");
	Osoba osoba1("Kamil","Nowaczkiewicz",25);
	Osoba osoba2("Artur","Adaluzki",25);
	Osoba osoba3("Adam","Przyt",35);
	Student student1 (osoba1,&kierunekInformatyki,1,Studia::niestacjonarne,Stopien::inzynierski);
	Student student2 (osoba2,&kierunekFizyki,1,Studia::niestacjonarne,Stopien::inzynierski);
	Pracownik pracownik1(osoba3,&katedraFizyki,StopienNaukowy::dr);
	Pracownik pracownik2(osoba2,&katedraInformatyki,StopienNaukowy::mgr);
	PracownikNaukowy pracownik_naukowy(pracownik1);
	PracownikDydaktyczny pracownik_dydaktyczny (pracownik2,1);

	Osoba * tablica[9] = {
		&osoba1,&osoba2,&osoba3,&student1,&student2,&pracownik1,&pracownik2,&pracownik_naukowy,&pracownik_dydaktyczny
	};
	raportInstancji(tablica,9);

	{
		std::cout<<"Test operatorow == !=\n";
		Kierunek kierunek("informatyka");
		Kierunek kierunek2("informatyka");
		Kierunek kierunek3("informatyk");

		if (kierunek == kierunek2) std::cout<<"Kierunek ok\n";
		if (kierunek!= kierunek3) std::cout<<"Kierunek ok\n";




	}


}