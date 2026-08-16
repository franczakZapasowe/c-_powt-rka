#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>


template<typename T, size_t ROZMIAR>
class Urna
{
private:
	static bool s_genZainicjowany;
	T m_elementy[ROZMIAR];
	int m_wylosowane = 0;
	int m_liczEl = 0;
public:
	Urna(T* tab = nullptr, int size = 0)
	{
		if (!s_genZainicjowany)
		{
			srand(time(0));
			s_genZainicjowany = true;
		}
		setElementy(tab, size);
	}

	//Konstuktor urna o innym rozmiarze
	template <typename U, size_t INNY_ROZ> friend class Urna;

	template<size_t NOWYROZMIAR>
	Urna (const Urna<T,NOWYROZMIAR>& urna);

	void wypiszZawartosc()
	{
		for (size_t el = 0; el < m_liczEl; el++)
			std::cout << m_elementy[el] << ' ';
	}

	void setElementy(T* tab,int size)
	{
		if (tab != nullptr && 0 < size)
		{
			m_liczEl = (ROZMIAR < size) ? ROZMIAR : size;
			memcpy(m_elementy, tab, m_liczEl * sizeof(T));
		}
	}
	
	T losujBezZwracania()
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

	template<typename U, size_t R >
	friend bool operator==(const Urna<U,R>& lhs, const Urna<U, R>& rhs);

	friend bool testKonwersjaDoble();
	friend bool testZgdoneParametryFalse();
	friend bool testZgodneParametryTrue();
};

template<typename T, size_t ROZMIAR>
bool Urna<T, ROZMIAR>::s_genZainicjowany = false;

template <typename T, size_t ROZMIAR>
template <size_t STARYROZMIAR>
Urna<T, ROZMIAR>::Urna(const Urna<T, STARYROZMIAR>& urna) {
	if (!s_genZainicjowany){
			srand(time(0));
			s_genZainicjowany = true;
	}
	m_liczEl = std::min<int>( urna.m_liczEl,ROZMIAR ); // NIE POTRZBUJE WARUNKU BO JAK STARY ROZMIAR JEST WOELSZY TO MIN TO NASZ ROZMIAR A JAK MNIEJSZY TO MIN TO STARY ROZMIAR
	m_wylosowane = std::min(urna.m_wylosowane,m_liczEl);

	memcpy(m_elementy, urna.m_elementy, m_liczEl*sizeof(T));
}

template <typename T>
bool czyRowne(T *tab, T *tab2, size_t size) {
	for (size_t el = 0; el < size; el++) {
		if (! (tab2[el] == tab[el])) return false;
	}
	return true;
}

bool testKonwersjaDoble() {

	double tab[30] = { 14.23, 88.41, 42.15,  9.67, 63.88,
	31.52, 75.19, 54.04, 22.91, 93.62,
	5.11,  47.83, 69.34, 11.76, 82.50,
	36.44, 98.19, 57.28, 18.03, 71.65,
	2.87,  85.49, 44.12, 61.37, 29.08,
	77.94, 51.63, 13.48, 90.22, 40.06};
	Urna<double, 30> urna1 (tab,30);
	urna1.losujBezZwracania();
	urna1.losujBezZwracania();
	urna1.losujBezZwracania();
	urna1.losujBezZwracania();
	urna1.losujBezZwracania();
	Urna<double,15> urna2(urna1);
	if (urna2.m_wylosowane == 5 && czyRowne(urna1.m_elementy, urna2.m_elementy, urna2.m_liczEl))
	return true;
	else return false;
}
template<typename U, size_t R >
bool operator==(const Urna<U,R>& lewy, const Urna<U,R>& prawy)
{
	// Zasada porównania:
	// Każdy element w "mniejszym" musi wystapić przynajmniej raz w "wiekszym" (decyduje liczba
	// aktualnie wykrzystywanych elementów).

	// Porównanie tożsamościowe powinno być wykonywane, gdy parametry realizacji szablonu mogą być identyczne:
	if (&lewy == &prawy)
		return true;
	else
	{
		auto mniejszy = (lewy.m_liczEl < prawy.m_liczEl) ? lewy : prawy;
		auto wiekszy = (lewy.m_liczEl < prawy.m_liczEl) ? prawy : lewy;

		bool zawieraSie = true, jest = true;
		// Pętla wykonuje się dla każdego elementu z "mniejszego"
		// ale tylko jeśli te juz sparwdzone wystapiły w "wiekszym".
		// Pierwszy element, ktory nie zostanie znaleziony ustawia
		// obie flagi ("jest" i "zawieraSie" na "false") co przekłada
		// się na przerwanie zewnętrznej petli. Tylko jesli wszytkie
		// elementy "mniejszgo" odnajdą sie w "wiekszym" faga
		// "zawieraSie" zostanie utrzymana w stanie "true".
		for (int l = 0; l < mniejszy.m_liczEl && zawieraSie; l++)
		{
			jest = false;
			for (int p = 0; p < wiekszy.m_liczEl; p++)
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

bool testZgdoneParametryFalse() {
	double tab[5] = { 1.0,2.0,3.0,4.0,5.0};
	double tab2[10] = { 5,21,32,44,51,64,8,9,0};

	Urna<double, 100> u1(tab,5);
	Urna<double, 100> u2(tab2,5);
	if (!(u1 == u2)) return true; else return false;
}

bool testZgdoneParametryTrue() {
	double tab[5] = { 1.0,2.0,3.0,4.0,5.0};
	Urna<double, 100> u1(tab,5);
	Urna<double, 100> u2(tab,5);
	if (u1 == u2) return true; else return false;
}

using namespace std;

int main()
{
	// //Tworzenie instancji:
	// int tab1[] = { 1,2,3,5 }; int n1 = sizeof(tab1) / sizeof(int);
	// int tab2[] = { 1,2,3,5,6,7 }; int n2 = sizeof(tab2) / sizeof(int);
	// int tab3[] = { 1,3,5,8,9,0,0 }; int n3 = sizeof(tab3) / sizeof(int);
	// Urna ur1(tab1, n1), ur2(tab2, n2), ur3(tab3, n3);
	//
	// //Porownywanie przed losowaniem:
	// cout << boolalpha << "Przed losowaniem:\n";
	// cout << "Ur1 == Ur2: " << (ur1 == ur2) << endl;
	// cout << "Ur1 == Ur3: " << (ur1 == ur3) << endl;
	// cout << "Ur2 == Ur3: " << (ur2 == ur3) << endl;
	//
	// //Sparwdzenie losowania:
	// cout << "Losowanie:\n";
	// try
	// {
	// 	for (int i = 0; i < ROZMIAR; i++)
	// 	{
	// 		cout << " Ur1: " << ur1.losujBezZwracania() << endl;
	// 		cout << " Ur2: " << ur2.losujBezZwracania() << endl;
	// 		cout << " Ur3: " << ur3.losujBezZwracania() << endl;
	// 	}
	// }
	// catch (std::exception& e)
	// {
	// 	cout << e.what() << " - Pozostalo: " << endl;
	// 	cout << "Ur1: " << ur1.pozostaloDoWylosowania() << endl;
	// 	cout << "Ur2: " << ur2.pozostaloDoWylosowania() << endl;
	// 	cout << "Ur3: " << ur3.pozostaloDoWylosowania() << endl;
	// }
	//
	// //Porownywanie po losowaniu:
	// cout << "Po losowaniu:\n";
	// cout << "Ur1 == Ur2: " << (ur1 == ur2) << endl;
	// cout << "Ur1 == Ur3: " << (ur1 == ur3) << endl;
	// cout << "Ur2 == Ur3: " << (ur2 == ur3) << endl;


	if (testKonwersjaDoble()) {
		if (testZgdoneParametryFalse() && testZgdoneParametryTrue()){
			std::cout<<"Wszystkie testy zalioczne pomyslnie";
		}
	}

	return 0;
}