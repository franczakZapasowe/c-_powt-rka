#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
class Koder
{
	char m_klucz[16] = {};
public:
	Koder(const char* i_klucz) { setKlucz(i_klucz); }
	void setKlucz(const char* i_klucz)
	{
		if (i_klucz != nullptr)
			strncpy(m_klucz, i_klucz, 16);
	}
	void szyfruj(char* i_info, size_t i_liczZnak) const
	{
		if (i_info != nullptr && i_liczZnak > 0)
			for (size_t i = 0; i < i_liczZnak; i++)
				i_info[i] ^= m_klucz[i%16];
	}
	void deszyfruj(char* i_info, size_t i_liczZnak) const
	{
		szyfruj(i_info, i_liczZnak);
	}

	Koder(const Koder& i_koder) {
		std::cout<<"Konstuktor kopiujacy\n";
		for (int i = 0; i < 16; i++)
			this->m_klucz[i] = i_koder.m_klucz[i];
	}
	Koder& operator=(const Koder& i_koder) {
		std::cout<<"Kopiujacy operator przypisania\n";
		for (int i = 0; i < 16; i++)
			this->m_klucz[i] = i_koder.m_klucz[i];
		return *this;
	}

	Koder(Koder&& i_koder) {
		*this = i_koder;
	}
};

int main()
{
	Koder maszyna("1234567890");
	char wiadomosc[] = "Tajny Komunikat";
	int dlugosc = strlen(wiadomosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
	maszyna.szyfruj(wiadomosc,dlugosc);
	cout << "Szyfrogram: " << wiadomosc << endl;
	maszyna.deszyfruj(wiadomosc, dlugosc);
	cout << "Wiadomosc: " << wiadomosc << endl;
	return 0;
}
