// #include <iostream>
// #include <array>
// using namespace std;
//
// template <typename T, size_t SIZE>
// T mostFrequent(T (&data)[SIZE], int & highestFreq)
// {
// 	// SKORO JEST PRZEZ REFRERENCJE TO NIE MOZE BYC NULLPTR WIEC SPRAWZAM TYLKO ROZRMIAR
// 	if (SIZE > 0)
// 	{
// 		highestFreq = 1;
// 		T mostFreq = data[0], freq = 0;
// 		for (int element = 0; element < SIZE; element++)
// 		{
// 			freq = 0;
// 			for (int another = 0; another < SIZE; another++)
// 				if (data[element] == data[another])
// 					freq++;
// 			if (freq > highestFreq)
// 			{
// 				highestFreq = freq;
// 				mostFreq = data[element];
// 			}
// 		}
// 		return mostFreq;
// 	}
// 	else throw(std::domain_error("No data!"));
// }
//
// template <>
// char mostFrequent(char (&data)[6], int & highestFreq)
// {
// 	// SKORO JEST PRZEZ REFRERENCJE TO NIE MOZE BYC NULLPTR WIEC SPRAWZAM TYLKO ROZRMIAR
//
// 	{
// 		for (auto &i : data) {
// 			i = std::toupper(static_cast<unsigned char>(i));
// 		}
//
// 		highestFreq = 1;
// 		char mostFreq = data[0], freq = 0;
// 		for (int element = 0; element < 6; element++)
// 		{
//
// 			freq = 0;
// 			for (int another = 0; another < 6; another++)
// 				if (data[element] == data[another])
// 					freq++;
// 			if (freq > highestFreq)
// 			{
// 				highestFreq = freq;
// 				mostFreq = data[element];
// 			}
// 		}
// 		return mostFreq;
// 	}
// }
//
// template<typename T>
// 	void add(T** adreses, int size, T* adres)
// 	{
// 		if (adreses != nullptr && size > 0)
// 		{
// 			T** firstEmpty = nullptr;
// 			for (T **adr = adreses; adr < adreses+size; adr++)
// 			{
// 				if (*adr == adres)
// 					throw std::domain_error("Adress already exist!");
// 				else if (*adr == nullptr && firstEmpty == nullptr)
// 					firstEmpty = adr;
// 			}
// 			if (firstEmpty != nullptr)
// 				*firstEmpty = adres;
// 		}
// 		else throw(std::domain_error("No data!"));
// 	}
//
// bool testMostFrequentDouble() {
// 	int mostFrequent_;
// 	double tablica[]={1.5, 3.14, 3.14, 0.0, 10.99, 1.5, 0.001, 100.25, 1.5, 12.34};
// 	std::cout<<"Test f(mostFrequent) przypadek double: ";
// 	if (mostFrequent(tablica, mostFrequent_)==1.5 && mostFrequent_ == 3.0 ) {
// 		std::cout<<"OK\n";
// 		return true;
// 	}
// 	else
// 		std::cout<<"FAIL\n";
// 		return false;
// }
//
// bool testMostFrequentChar() {
// 	int mostFrequent_=0;
// 	char tablica[] = {'a','a','a','b','b','c'};
// 	std::cout<<"Test f(mostFrequent) przypadek char: ";
// 	if (mostFrequent(tablica,mostFrequent_)== 'A' && mostFrequent_ == 3.0 ) {
// 		std::cout<<"OK\n";
// 		return true;
// 	}
// 	else
// 		std::cout<<"FAIL\n";
// 	return false;
// }
//
// bool testAdd() {
// 	int q,w,e,u;
// 	int *tablica[5] {&q, &w, &e};
// 	std::cout<<"Test funkcji add:";
// 	try {
// 		add(tablica, 5, &u );
// 		std::cout<<"OK\n";
// 		return true;
// 	}
// 	catch (std::exception e) {std::cout<<"Fail\n"; std::cout<<e.what(); return false;}
// }
//
// int main()
// {
// 	// dla mostFrequent:
// 	// int tabInt[] = { 1,2,3,4,4,5,6,8,8,8,1,4,1,2,5,8,5,5,1};
// 	// int wynik = 0;
// 	// //cout << mostFrequent(tabInt, sizeof(tabInt) / sizeof(int),wynik);
// 	// cout << " (" << wynik << ")" << endl;
//
// 	{
// 		if (testMostFrequentChar() && testMostFrequentDouble()&&testAdd()) {
// 			std::cout<<"Testy zaliczone posmyslnie\n";
// 		}else
// 			std::cout<<"Testy nie zaliczone\n";
// 	}
//
// 	// dla add:
// 	// double zm1= 1.0, zm2 = 2.0, zm3 = 3.0;
// 	// cout << "Adresy zmiennych:\nzm1: " << &zm1
// 	// 	<< " zm2: " << &zm2 << " zm3: " << &zm3 << endl;
// 	// double* tabAdr[10] = {&zm1, &zm2};
// 	// cout << "Adresy w tab:\n";
// 	// for (int i = 0; i < 10; i++)
// 	// 	cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;
// 	//
// 	// try { add(tabAdr, 10, &zm3); }
// 	//  catch (std::exception e) { cout << "zm3(1): " << e.what() << endl; }
// 	// try { add(tabAdr, 10, &zm1); }
// 	// catch (std::exception e) { cout << "zm1(1): " << e.what() << endl; }
// 	// try { add(tabAdr, 10, &zm3); }
// 	// catch (std::exception e) { cout << "zm3(2): " << e.what() << endl; }
// 	//
// 	// for (int i = 0; i < 10; i++)
// 	// 	cout << "tabAdr[" << i << "]: " << tabAdr[i] << endl;
// }