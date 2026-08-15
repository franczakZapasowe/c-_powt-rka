#include <iostream>
#include <array>
using namespace std;

template <typename T, int SIZE>
T mostFrequent(std::array<T,SIZE>& data, int & highestFreq)
{
	// SKORO JEST PRZEZ REFRERENCJE TO NIE MOZE BYC NULLPTR WIEC SPRAWZAM TYLKO ROZRMIAR
	if (SIZE > 0)
	{
		highestFreq = 1;
		T mostFreq = data[0], freq = 0;
		for (int element = 0; element < SIZE; element++)
		{
			freq = 0;
			for (int another = 0; another < SIZE; another++)
				if (data[element] == data[another])
					freq++;
			if (freq > highestFreq)
			{
				highestFreq = freq;
				mostFreq = data[element];
			}
		}
		return mostFreq;
	}
	else throw(std::domain_error("No data!"));
}

//template<typename T>
void add(double** adreses, int size, double* adres)
{
	if (adreses != nullptr && size > 0)
	{
		double** firstEmpty = nullptr;
		for (double **adr = adreses; adr < adreses+size; adr++)
		{
			if (*adr == adres) 
				throw std::domain_error("Adress already exist!");
			else if (*adr == nullptr && firstEmpty == nullptr)
				firstEmpty = adr;
		}
		if (firstEmpty != nullptr)
			*firstEmpty = adres;
	}
	else throw(std::domain_error("No data!"));
}


int main()
{
	// dla mostFrequent:
	// int tabInt[] = { 1,2,3,4,4,5,6,8,8,8,1,4,1,2,5,8,5,5,1};
	// int wynik = 0;
	// //cout << mostFrequent(tabInt, sizeof(tabInt) / sizeof(int),wynik);
	// cout << " (" << wynik << ")" << endl;
	
	// dla add:
	double zm1= 1.0, zm2 = 2.0, zm3 = 3.0;
	cout << "Adresy zmiennych:\nzm1: " << &zm1
		<< " zm2: " << &zm2 << " zm3: " << &zm3 << endl;
	double* tabAdr[10] = {&zm1, &zm2};
	cout << "Adresy w tab:\n";
	for (int i = 0; i < 10; i++)
		cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;

	try { add(tabAdr, 10, &zm3); }
	 catch (std::exception e) { cout << "zm3(1): " << e.what() << endl; }
	try { add(tabAdr, 10, &zm1); }
	catch (std::exception e) { cout << "zm1(1): " << e.what() << endl; }
	try { add(tabAdr, 10, &zm3); }
	catch (std::exception e) { cout << "zm3(2): " << e.what() << endl; }

	for (int i = 0; i < 10; i++)
		cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;
}