// #include <cmath>
// #include <cstring>
// #include <iostream>
// #include <exception>
// using namespace std;
// class Koder
// {
// 	char *m_klucz = nullptr;
// 	size_t m_liczZnak = 0;
// public:
// 	Koder(const char* i_klucz) {
// 		if (i_klucz != nullptr) {
// 			m_liczZnak = strlen (i_klucz);
// 			if (m_liczZnak > 0) {
// 				m_klucz = new char[m_liczZnak+1];
// 				strcpy(m_klucz, i_klucz);
// 			}
// 		}
// 	}
// 	~Koder() {
// 		delete [] m_klucz;
// 		m_klucz = nullptr;
// 	}
// 	Koder() = delete;
//
// 	bool jestOK()const {
// 		if (m_klucz==nullptr)
// 			throw std::invalid_argument("KLUCZ NIE MOZE BYC PUSTY!!!!!\n");
// 		return true;
// 	}
// 	// void setKlucz(const char* i_klucz)
// 	// {
// 	// 	if (i_klucz != nullptr)
// 	// 		strncpy(m_klucz, i_klucz, m_liczZnak);
// 	// }
//
// 	void szyfruj(char* i_info, size_t i_liczZnak) const
// 	{
// 		this -> jestOK();
// 		if (i_info != nullptr && i_liczZnak > 0)
// 			for (size_t i = 0; i < i_liczZnak; i++)
// 				i_info[i] ^= m_klucz[i%m_liczZnak];
// 	}
//
// 	void deszyfruj(char* i_info, size_t i_liczZnak) const
// 	{
// 		//tu nie daje jest ok bo wywoluje funkcje szyfruj a tam jest czyli zasada DRY
// 		szyfruj(i_info, i_liczZnak);
// 	}
//
// 	Koder (const Koder &k) {
// 		//std::cout<<"Konstruktor kopiujace\n";
// 		if (k.m_klucz != nullptr) {
// 			if (k.m_liczZnak > 0) {
// 				m_klucz = new char[k.m_liczZnak+1];
// 				m_liczZnak = k.m_liczZnak;
// 				strcpy(m_klucz, k.m_klucz);
// 			}
// 		}
// 	}
//
// 	Koder& operator=(const Koder &k) {
// 		//std::cout<<"Kopiujacy operator przypisania\n";
// 		if (this!=&k) {
// 			delete [] m_klucz;
// 			m_klucz = nullptr;
// 			m_liczZnak = k.m_liczZnak;
// 			if (k.m_klucz != nullptr) {
// 				m_klucz = new char[k.m_liczZnak+1];
// 				strcpy(m_klucz, k.m_klucz);
// 			}
// 		}
// 		return *this;
// 	}
//
// 	Koder(Koder&& k) {
// 		//std::cout<<"Konstruktor przenoszacy\n";
// 		if (k.m_klucz != nullptr) {
// 			m_liczZnak = k.m_liczZnak;
// 			m_klucz = k.m_klucz;
// 			k.m_klucz = nullptr;
// 			k.m_liczZnak = 0;
// 		}
// 	}
//
// 	Koder& operator=(Koder&& k) {
// 		//std::cout<<"Przenoszay operator przypiania\n";
// 		if (this!=&k) {
// 			delete [] m_klucz;
// 			m_klucz = nullptr;
// 			m_liczZnak = k.m_liczZnak;
// 			if (k.m_klucz != nullptr) {
// 				m_klucz = k.m_klucz;
// 				k.m_klucz = nullptr;
// 				k.m_liczZnak = 0;
// 			}
// 		}
// 		return *this;
// 	}
//
// 	void wypisz () {
// 		//this -> jestOK();
// 		for (int i = 0; i <m_liczZnak; i++) {
// 			std::cout<<m_klucz[i]<<" ";
// 		}
// 		std::cout<<std::endl;
// 	}
//
// 	void alokuj(int rozmiar) {
// 		if (rozmiar > 0) {
// 			m_klucz = new char[rozmiar];
// 			m_liczZnak = rozmiar;
// 		}
// 	}
// 	friend bool czyPusty(Koder &k);
//
// 	friend bool testujaca();
// 	bool operator ==(const Koder &k) {
// 		if (this->m_klucz == nullptr && k.m_klucz == nullptr) return true;
// 		if (this->m_klucz == nullptr || k.m_klucz == nullptr) return false;
//
// 		return std::strcmp(this->m_klucz, k.m_klucz) == 0;
// 	};
// };
//
//  bool czyPusty(Koder &k) {
// 	if (k.m_klucz == nullptr) return true;
// 	else return false;
// }
// bool testujaca() {
//
// 	int licznik = 0;
// 	Koder k1("123");
// 	Koder k2 (k1);
// 	std::cout << "Test konstruktora Kopiujacego: ";
// 	if (k1 == k2) {
// 		std::cout << "OK\n";
// 		licznik++;
// 	}else std::cout<<"FAIL\n";
//
//  	std::cout<<"Test kopiujacego operatora przypisania:";
// 	Koder k3 ("asdasd");
// 	k3 = k1;
// 	if (k1==k3) {
// 		std::cout << "OK\n";
// 		licznik++;
// 	}else std::cout<<"FAIL\n";
// 	// na tym tepaie wiedzialem ze dziala mi kopiowaniowanie wiec moglem porwanc wynik z k2
//  	std::cout << "Test konstruktora przenoszacego: ";
// 	Koder k4 (std::move(k1));
// 	if ((k2==k4)&&(czyPusty(k1))) {
// 		std::cout << "OK\n";
// 		licznik++;
// 	}else std::cout<<"FAIL\n";
// 	Koder k5 ("losowe");
//  	k5 = std::move(k2);
//  	std::cout<<"Test przenoszacego operatora przypisania: ";
//  	if (k5==k3&&(czyPusty(k2))) {
//  		std::cout << "OK\n";
// 		licznik++;
//  	}else std::cout<<"FAIL\n";
//
//
// 	if (licznik==4)return true;
//  	else return false;
// }
//
// int main(void)
// {
// 		if (testujaca()) std::cout<<"Wszystkie Testy przszly pomyslnie\n";
//
// }