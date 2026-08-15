#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Wprowadznie szablonu powinno wyeliminować poniższą linię:
constexpr size_t ROZMIAR = 100;

class Urna
{
private:
	static bool s_genZainicjowany;
	int m_elementy[ROZMIAR];
	int m_wylosowane = 0;
	int m_liczEl = 0;
public:
	Urna(int* tab = nullptr, int size = 0)
	{
		if (!s_genZainicjowany)
		{
			srand(time(0));
			s_genZainicjowany = true;
		}
		setElementy(tab, size);
	}

	void wypiszZawartosc()
	{
		for (size_t el = 0; el < m_liczEl; el++)
			std::cout << m_elementy[el] << ' ';
	}

	void setElementy(int* tab,int size)
	{
		if (tab != nullptr && 0 < size)
		{
			m_liczEl = (ROZMIAR < size) ? ROZMIAR : size;
			memcpy(m_elementy, tab, m_liczEl * sizeof(int));
		}
	}
	
	int losujBezZwracania()
	{
		int zakresLosowania = m_liczEl - m_wylosowane;
		if (0 < zakresLosowania)
		{
			int indeks = rand() % zakresLosowania;
			std::swap(m_elementy[indeks], m_elementy[zakresLosowania - 1]);
			m_wylosowane++;
			return m_elementy[--zakresLosowania];
		}
		else throw std::domain_error("Brak elementow");
	}

	void reset()
	{
		m_wylosowane = 0;
	}

	int pozostaloDoWylosowania()
	{
		return m_liczEl - m_wylosowane;
	}
	friend bool operator==(const Urna& lhs, const Urna& rhs);
};

bool Urna::s_genZainicjowany = false;

bool operator==(const Urna& lewy, const Urna& prawy)
{
	// Zasada porównania:
	// Każdy element w "mniejszym" musi wystapić przynajmniej raz w "wiekszym" (decyduje liczba
	// aktualnie wykrzystywanych elementów).
	
	// Porównanie tożsamościowe powinno być wykonywane, gdy parametry realizacji szablonu mogą być identyczne:
	if (&lewy == &prawy) 
		return true;
	else
	{
		Urna mniejszy = (lewy.m_liczEl < prawy.m_liczEl) ? lewy : prawy;
		Urna wiekszy = (lewy.m_liczEl < prawy.m_liczEl) ? prawy : lewy;
		
		bool zawieraSie = true, jest = true;
		// Pętla wykonuje się dla każdego elementu z "mniejszego"
		// ale tylko jeśli te juz sparwdzone wystapiły w "wiekszym".
		// Pierwszy element, ktory nie zostanie znaleziony ustawia
		// obie flagi ("jest" i "zawieraSie" na "false") co przekłada
		// się na przerwanie zewnętrznej petli. Tylko jesli wszytkie
		// elementy "mniejszgo" odnajdą sie w "wiekszym" faga
		// "zawieraSie" zostanie utrzymana w stanie "true".
		for (int l = 0; l <= mniejszy.m_liczEl && zawieraSie; l++)
		{
			jest = false;
			for (int p = 0; p <= wiekszy.m_liczEl; p++)
				if (lewy.m_elementy[l] == prawy.m_elementy[p])
				{
					jest = true;
					break;
				}
			zawieraSie = jest;
		}
		return zawieraSie;
	}
}

using namespace std;

int main()
{
	//Tworzenie instancji:
	int tab1[] = { 1,2,3,5 }; int n1 = sizeof(tab1) / sizeof(int);
	int tab2[] = { 1,2,3,5,6,7 }; int n2 = sizeof(tab2) / sizeof(int);
	int tab3[] = { 1,3,5,8,9,0,0 }; int n3 = sizeof(tab3) / sizeof(int);
	Urna ur1(tab1, n1), ur2(tab2, n2), ur3(tab3, n3);

	//Porownywanie przed losowaniem:
	cout << boolalpha << "Przed losowaniem:\n";
	cout << "Ur1 == Ur2: " << (ur1 == ur2) << endl;
	cout << "Ur1 == Ur3: " << (ur1 == ur3) << endl;
	cout << "Ur2 == Ur3: " << (ur2 == ur3) << endl;

	//Sparwdzenie losowania:
	cout << "Losowanie:\n";
	try
	{
		for (int i = 0; i < ROZMIAR; i++)
		{
			cout << " Ur1: " << ur1.losujBezZwracania() << endl;
			cout << " Ur2: " << ur2.losujBezZwracania() << endl;
			cout << " Ur3: " << ur3.losujBezZwracania() << endl;
		}
	}
	catch (std::exception& e)
	{
		cout << e.what() << " - Pozostalo: " << endl;
		cout << "Ur1: " << ur1.pozostaloDoWylosowania() << endl;
		cout << "Ur2: " << ur2.pozostaloDoWylosowania() << endl;
		cout << "Ur3: " << ur3.pozostaloDoWylosowania() << endl;
	}

	//Porownywanie po losowaniu:
	cout << "Po losowaniu:\n";
	cout << "Ur1 == Ur2: " << (ur1 == ur2) << endl;
	cout << "Ur1 == Ur3: " << (ur1 == ur3) << endl;
	cout << "Ur2 == Ur3: " << (ur2 == ur3) << endl;


}