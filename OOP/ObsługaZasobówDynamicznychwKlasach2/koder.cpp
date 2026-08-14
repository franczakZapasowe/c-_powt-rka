#include <cmath>
#include <cstring>
#include <iostream>
#include <exception>
using namespace std;
class Koder
{
	char *m_klucz = nullptr;
	size_t m_liczZnak = 0;
public:
	Koder(const char* i_klucz) {
		if (i_klucz != nullptr) {
			m_liczZnak = strlen (i_klucz);
			if (m_liczZnak > 0) {
				m_klucz = new char[m_liczZnak+1];
				strcpy(m_klucz, i_klucz);
			}
		}
	}
	~Koder() {
		delete [] m_klucz;
		m_klucz = nullptr;
	}
	Koder() = delete;

	bool jestOK()const {
		if (m_klucz==nullptr)
			throw std::invalid_argument("KLUCZ NIE MOZE BYC PUSTY!!!!!\n");
		return true;
	}
	// void setKlucz(const char* i_klucz)
	// {
	// 	if (i_klucz != nullptr)
	// 		strncpy(m_klucz, i_klucz, m_liczZnak);
	// }

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
		std::cout<<"Konstruktor kopiujace\n";
		if (k.m_klucz != nullptr) {
			if (k.m_liczZnak > 0) {
				m_klucz = new char[k.m_liczZnak+1];
				m_liczZnak = k.m_liczZnak;
				strcpy(m_klucz, k.m_klucz);
			}
		}
	}

	Koder& operator=(const Koder &k) {
		std::cout<<"Kopiujacy operator przypisania\n";
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
		std::cout<<"Konstruktor przenoszacy\n";
		if (k.m_klucz != nullptr) {
			m_liczZnak = k.m_liczZnak;
			m_klucz = k.m_klucz;
			k.m_klucz = nullptr;
			k.m_liczZnak = 0;
		}
	}

	Koder& operator=(Koder&& k) {
		std::cout<<"Przenoszay operator przypiania\n";
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

	void alokuj(int rozmiar) {
		if (rozmiar > 0) {
			m_klucz = new char[rozmiar];
			m_liczZnak = rozmiar;
		}
	}
};

int main(void)
{
	// Koder maszyna("1234567890");
	// char wiadomosc[] = "Tajny Komunikat";
	// int dlugosc = strlen(wiadomosc);
	// cout << "Wiadomosc: " << wiadomosc << endl;
	// maszyna.szyfruj(wiadomosc,dlugosc);
	// cout << "Szyfrogram: " << wiadomosc << endl;
	// maszyna.deszyfruj(wiadomosc, dlugosc);
	// cout << "Wiadomosc: " << wiadomosc << endl;

	{
		// std::cout<<"Test dzialania\n";
		// Koder k1 ("asd");
		// std::cout<<"K1: "; k1.wypisz();
		// Koder k2 (k1);
		// std::cout<<"K2: "; k2.wypisz();
		// Koder k3 ("as");
		// std::cout<<"K3 przed: "; k3.wypisz();
		// k3 = k1;
		// std::cout<<"K3 po: "; k3.wypisz();
		// Koder k4 (std::move(k3));
		// k4 = std::move(k2);
		// std::cout<<"K4 po: "; k4.wypisz();
	}

	{
		std::cout<<"Test nowych konstrutkorow\n";
		Koder k1 ("asd");
		Koder k2 (k1);
		Koder k3 ("yyy");
		k3 = k2;
		Koder k4 (std::move(k3));
		Koder k5 ("aaa");
		k5 = std::move(k4);
		std::cout<<"k1:\n";
		k1.wypisz();
		std::cout<<"k2:\n";
		k2.wypisz();
		std::cout<<"k3:\n";
		k3.wypisz();
		std::cout<<"k4:\n";
		k4.wypisz();
		std::cout<<"k5:\n";
		k5.wypisz();

	}
}