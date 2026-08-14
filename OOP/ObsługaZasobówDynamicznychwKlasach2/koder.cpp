#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
class Koder
{
	char m_klucz[100] = {};
	size_t m_liczZnak = 0;
public:
	Koder(const char* i_klucz) {
		m_liczZnak= strlen (i_klucz);
		if (m_liczZnak>100) m_liczZnak = 100;
		std::fill(m_klucz, m_klucz + 100, '#');
		setKlucz(i_klucz);
	}
	void setKlucz(const char* i_klucz)
	{
		if (i_klucz != nullptr)
			strncpy(m_klucz, i_klucz, m_liczZnak);
	}
	void szyfruj(char* i_info, size_t i_liczZnak) const
	{
		if (i_info != nullptr && i_liczZnak > 0)
			for (size_t i = 0; i < i_liczZnak; i++)
				i_info[i] ^= m_klucz[i%m_liczZnak];
	}
	void deszyfruj(char* i_info, size_t i_liczZnak) const
	{
		szyfruj(i_info, i_liczZnak);
	}
	Koder (const Koder&k) {
		std::cout<<"Konstruktor kopiujacy\n";
		std::fill(m_klucz, m_klucz + 100, '#');
		m_liczZnak = k.m_liczZnak;
		for (size_t i = 0; i < m_liczZnak; i++)
			m_klucz[i] = k.m_klucz[i];
	}

	Koder& operator= (const Koder& k) {
		std::cout<<"Kopiujacy operator przypisania\n";
		std::fill(m_klucz, m_klucz + 100, '#');
		m_liczZnak = k.m_liczZnak;
		for (size_t i = 0; i < m_liczZnak; i++)
			m_klucz[i] = k.m_klucz[i];
		return *this;
	}

	Koder(Koder &&k) {
		std::cout<<"Konstruktor przenoszacy\n";
		*this = k;
	}

	Koder& operator= (Koder&& k) {
		std::cout<<"Przenoszacy operator przypisania\n";
		return *this = k;
	}

	void wypisz () {
		for (int i = 0; i < 100; i++) {
			std::cout<<m_klucz[i]<<" ";
		}
		std::cout<<std::endl;
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
		std::cout<<"Test dzialania\n";
		Koder k1 ("asd");
		std::cout<<"K1: "; k1.wypisz();
		Koder k2 (k1);
		std::cout<<"K2: "; k2.wypisz();
		Koder k3 ("as");
		std::cout<<"K3 przed: "; k3.wypisz();
		k3 = k1;
		std::cout<<"K3 po: "; k3.wypisz();
		Koder k4 (std::move(k3));
		k4 = std::move(k2);
		std::cout<<"K4 po: "; k4.wypisz();
	}
}