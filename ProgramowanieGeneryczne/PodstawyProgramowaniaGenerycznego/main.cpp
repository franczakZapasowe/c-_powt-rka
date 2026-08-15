// #include<iostream>
// #include <array>
// #include "Wektor.h"
// #include <string>
// template<typename T, size_t SIZE>
// bool czyZawiera(const std::array<T, SIZE> &arr, const T &val) {
//     for (auto i : arr) {
//         if (i == val) return true;
//     }
//     return false;
// }
//
// int main() {
//
//     std::array<int, 10> arr ={0,1,4,2,4,2,1,2,4,2};
//     if (czyZawiera(arr,0)) {
//         std::cout << "Zawiera" << std::endl;
//     }else {
//         std::cout << "Nie Zawiera" << std::endl;
//     }
//
//     {
//         Wektor<double>wektor1(2.4,23.2);
//         Wektor<int>wektor2(3,4);
//          Wektor<std::string>wektor3("Punkt x","Punkt y");
//          std::cout<<"Wetkor double:\n";
//          wektor1.wypisz();
//          std::cout<<"Wetkor int:\n";
//          wektor2.wypisz();
//          std::cout<<"Wetkor string:\n";
//          wektor3.wypisz();
//
//     }
//
//     return 0;
// }
