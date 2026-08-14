#include <cmath>
#include <cstring>
#include <iostream>
#include <exception>
using namespace std;
class Koder
{
	char *m_klucz = nullptr;
	size_t m_liczZnak = 0;
	static int licznikInstancji;
public:
	Koder(const char* i_klucz) {
		licznikInstancji++;
		setKlucz(i_klucz);
	}
	~Koder() {
		delete [] m_klucz;
		m_klucz = nullptr;
		licznikInstancji--;
	}
	Koder() = delete;

	bool jestOK()const {
		if (m_klucz==nullptr)
			throw std::invalid_argument("KLUCZ NIE MOZE BYC PUSTY!!!!!\n");
		return true;
	}
	void setKlucz(const char* i_klucz)
	{
		if (i_klucz == nullptr || strlen(i_klucz) == 0) {
			i_klucz = "AWARIA";
		}
			if (strlen(i_klucz) != m_liczZnak) {
				m_liczZnak = strlen(i_klucz);
				delete [] m_klucz;
				m_klucz = nullptr;
				m_klucz = new char [m_liczZnak+1];
				strcpy(m_klucz,i_klucz);
			}else {
				strcpy(m_klucz,i_klucz);
			}
	}

	void szyfruj(char* i_info, size_t i_liczZnak) const
	{
		this -> jestOK();
		if (i_info != nullptr && i_liczZnak > 0)
			for (size_t i = 0; i < i_liczZnak; i++)
				i_info[i] ^= m_klucz[i%m_liczZnak];
	}

	void deszyfruj(char* i_info, size_t i_liczZnak) const
	{
		//tu nie daje jest ok bo wywoluje funkcje szyfruj a tam jest czyli zasada DRY
		szyfruj(i_info, i_liczZnak);
	}

	Koder (const Koder &k) {
		//std::cout<<"Konstruktor kopiujace\n";
		licznikInstancji++;
		if (k.m_klucz != nullptr) {
			if (k.m_liczZnak > 0) {
				m_klucz = new char[k.m_liczZnak+1];
				m_liczZnak = k.m_liczZnak;
				strcpy(m_klucz, k.m_klucz);
			}
		}
	}

	Koder& operator=(const Koder &k) {
		//std::cout<<"Kopiujacy operator przypisania\n";
		if (this!=&k) {
			delete [] m_klucz;
			m_klucz = nullptr;
			m_liczZnak = k.m_liczZnak;
			if (k.m_klucz != nullptr) {
				m_klucz = new char[k.m_liczZnak+1];
				strcpy(m_klucz, k.m_klucz);
			}
		}
		return *this;
	}

	Koder(Koder&& k) {
		//std::cout<<"Konstruktor przenoszacy\n";
		licznikInstancji++;
		if (k.m_klucz != nullptr) {
			m_liczZnak = k.m_liczZnak;
			m_klucz = k.m_klucz;
			k.m_klucz = nullptr;
			k.m_liczZnak = 0;
		}
	}

	Koder& operator=(Koder&& k) {
		//std::cout<<"Przenoszay operator przypiania\n";
		if (this!=&k) {
			delete [] m_klucz;
			m_klucz = nullptr;
			m_liczZnak = k.m_liczZnak;
			if (k.m_klucz != nullptr) {
				m_klucz = k.m_klucz;
				k.m_klucz = nullptr;
				k.m_liczZnak = 0;
			}
		}
		return *this;
	}

	void wypisz () {
		//this -> jestOK();
		for (int i = 0; i <m_liczZnak; i++) {
			std::cout<<m_klucz[i]<<" ";
		}
		std::cout<<std::endl;
	}

	int getIleInstancji()const {return licznikInstancji;}
	friend bool czyPusty(Koder &k);

	friend bool testujaca();
	friend bool testZmianyKluczaWJednejInstancji();

	bool operator ==(const Koder &k) {
		if (this->m_klucz == nullptr && k.m_klucz == nullptr) return true;
		if (this->m_klucz == nullptr || k.m_klucz == nullptr) return false;

		return std::strcmp(this->m_klucz, k.m_klucz) == 0;
	};
	friend bool testZmianyKluczaKopiujacego();

	bool operator !=(const Koder&k) {
		return std::strcmp(this->m_klucz,k.m_klucz)!=0;
	}

	friend bool kopiowaieINstancjiLicznik();
	friend bool przenoszenieInstancjiLicznik();
	friend bool usuwanieInstancjiLicznik();
};

int Koder::licznikInstancji = 0;

 bool czyPusty(Koder &k) {
	if (k.m_klucz == nullptr) return true;
	else return false;
}
bool testujaca() {

	int licznik = 0;
	Koder k1("123");
	Koder k2 (k1);
	std::cout << "Test konstruktora Kopiujacego: ";
	if (k1 == k2) {
		std::cout << "OK\n";
		licznik++;
	}else std::cout<<"FAIL\n";

 	std::cout<<"Test kopiujacego operatora przypisania:";
	Koder k3 ("asdasd");
	k3 = k1;
	if (k1==k3) {
		std::cout << "OK\n";
		licznik++;
	}else std::cout<<"FAIL\n";
	// na tym tepaie wiedzialem ze dziala mi kopiowaniowanie wiec moglem porwanc wynik z k2
 	std::cout << "Test konstruktora przenoszacego: ";
	Koder k4 (std::move(k1));
	if ((k2==k4)&&(czyPusty(k1))) {
		std::cout << "OK\n";
		licznik++;
	}else std::cout<<"FAIL\n";
	Koder k5 ("losowe");
 	k5 = std::move(k2);
 	std::cout<<"Test przenoszacego operatora przypisania: ";
 	if (k5==k3&&(czyPusty(k2))) {
 		std::cout << "OK\n";
		licznik++;
 	}else std::cout<<"FAIL\n";


	if (licznik==4)return true;
 	else return false;
}

bool testZmianyKluczaWJednejInstancji() {
 	int licznik = 0;
	Koder koder1("klucz");
 	Koder k2 (koder1);
 	koder1.setKlucz("cos");
 	std::cout<<"Test zmiany klucza w jendej instacji: ";
 	if (koder1 == k2) {std::cout<<"FAIL\n";}
 	else {std::cout<<"OK\n"; licznik++;}

	if (licznik ==1) return true;
 	else return false;
}

bool testZmianyKluczaKopiujacego(){
 	int licznik = 0;
 	Koder koder1("klucz");
 	Koder k2 (koder1);
 	if (k2 != koder1) {
		std::cout<<"Blad konstuktora kopijujacego\n";
 		return false;
 	}
 	k2.setKlucz("cos");
 	std::cout<<"Test zmiany klucza Kopiujacego: ";
 	if (koder1 == k2) {std::cout<<"FAIL\n";}
 	else {std::cout<<"OK\n"; licznik++;}

 	if (licznik == 1) return true;
 	else return false;
}


bool kopiowaieINstancjiLicznik() {
 	int temp = Koder::licznikInstancji;
	Koder K1("Klucz");
 	Koder K2 (K1);
 	std::cout<<"Test licznika przy kopiowaniu instancji: ";
 	if (temp + 2 == Koder::licznikInstancji) {
 		std::cout<<"OK\n";
 		return true;
 	}
 	else{std::cout<<"FAIL\n"; return false;}
}

bool przenoszenieInstancjiLicznik() {
	int temp = Koder::licznikInstancji;
 	Koder K1("Klucz");
 	Koder K2 (std::move(K1));
 	std::cout<<"Test licznika przy prznoszeniu instancji: ";
 	if (temp + 2 == Koder::licznikInstancji) {
 		std::cout<<"OK\n";
 		return true;
 	}
 	else{std::cout<<"FAIL\n"; return false;}
 }

bool usuwanieInstancjiLicznik() {
 	int temp = Koder::licznikInstancji;
 	Koder *K1 = new Koder("KLUCZ");
 	Koder *k2 = new Koder ("asdf");
 	delete K1; delete k2;

 	std::cout<<"Test licznika przy usuwaniu instancji: ";
 	if (temp == Koder::licznikInstancji) {
 		std::cout<<"OK\n";
 		return true;
 	}
 	else{std::cout<<"FAIL\n"; return false;}
}


int main()
{
		if (testujaca()) {
			std::cout<<"Wszystkie Testy Konstruktorw przeszly pomyslnie\n";
			std::cout<<"___________________________________________________\n";
 			if (testZmianyKluczaWJednejInstancji()){std::cout<<"Test zmainy klucza w instancji przeszedl pomyslnie\n";}
 			std::cout<<"___________________________________________________\n";
 			if (testZmianyKluczaKopiujacego())std::cout<<"Test zmainy klucza w przy kopoiowaniu przeszedl pomyslnie\n";
			std::cout<<"___________________________________________________\n";
			kopiowaieINstancjiLicznik();
			std::cout<<"___________________________________________________\n";
 			przenoszenieInstancjiLicznik();
			std::cout<<"___________________________________________________\n";
			usuwanieInstancjiLicznik();
		}
}