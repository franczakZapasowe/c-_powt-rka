# 🚀 C++ Masterclass: Kompendium Wiedzy i Powtórka

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![C++20](https://img.shields.io/badge/Standard-C%2B%2B20-blue?style=for-the-badge)

## 📖 O projekcie

To repozytorium stanowi kompleksową powtórkę oraz uporządkowane kompendium wiedzy z języka C++, ze szczególnym uwzględnieniem zagadnień przydatnych w informatyce przemysłowej. Zakres materiału pokrywa pełne spektrum języka – od absolutnych podstaw proceduralnych, poprzez zaawansowane programowanie obiektowe, aż po nowoczesne mechanizmy wprowadzone w standardach C++11/14/17/20 (w tym widoki, lambdy, systemy plików czy regex). Projekt został wzbogacony również o solidny dział dedykowany algorytmom i strukturom danych.

## 📂 Struktura repozytorium i zagadnienia

Repozytorium zostało zaprojektowane z myślą o przejrzystości i łatwej nawigacji. Każdy folder odpowiada za odrębną dziedzinę, a wewnątrz znajdują się kody źródłowe (`.cpp`, `.hpp`) obrazujące dany temat oraz polecenia zadań:

* **`PodstawyProgramowania`**
  * Struktura programu, zmienne i podstawowe operacje we/wy.
  * Instrukcje warunkowe i iteracyjne (pętle `for`, `while`, `do-while`).
  * Podstawy optymalizacji i diagnostyki kodu (strategie debugowania, TDD).

* **`ZawansowanePodstawyPogramowanieProcedur...eBitowe`**
  * Operacje tablicowe (w tym tablice 2D i c-stringi).
  * Złożone typy danych (struktury, typy wyliczeniowe `enum class`, aliasy).
  * Delegowanie zadań do funkcji (parametry domyślne, przeciążanie nazw).
  * Operacje plikowe i zaawansowane operacje bitowe.

* **`WskaznikiZadanieZlozone`**
  * Zarządzanie adresami: wskaźniki i referencje (w tym arytmetyka wskaźników i wskaźniki wyższego stopnia).
  * Dynamiczna alokacja pamięci (sterta vs stos, operatory `new`/`delete`, zapobieganie wyciekom pamięci).

* **`OOP` (Programowanie Obiektowe)**
  * Klasy, hermetyzacja i zasada enkapsulacji (akcesory, setery, getery).
  * Relacje obiektowe: asocjacja, agregacja, kompozycja i zależność.
  * Dziedziczenie (w tym wielobazowe, wirtualne i diamentowe) oraz polimorfizm obiektowy (metody wirtualne, nadpisywanie).
  * Przeciążanie operatorów i mechanizmy konwersji typów (rzutowania m.in. `static_cast`, `dynamic_cast`).
  * Zarządzanie zasobami dynamicznymi w klasach (Kopia głęboka vs płytka, semantyka przenoszenia, Reguła Pięciu/Zera).

* **`ProgramowanieGeneryczne`**
  * Szablony funkcji i klas (programowanie uogólnione).
  * Inteligentne wskaźniki (`unique_ptr`, `shared_ptr`, `weak_ptr`).
  * Kontenery biblioteki standardowej (STL): `std::vector`, `std::list`, `std::map`, `std::set`, `std::array` oraz iteratory.
  * Wyrażenia Lambda, funktory i uniwersalne przekazywanie (`std::function`).
  * Współczesne mechanizmy C++20: Programowanie zakresowe (`std::ranges`), widoki (views), `std::filesystem`, wyrażenia regularne (`std::regex`), krotki (`std::tuple`) oraz wiązanie strukturalne.

* **`AlgorytmyiStrukturyDanych`**
  * Implementacje i analiza klasycznych struktur danych.
  * Algorytmy numeryczne (poszukiwanie ekstremów, metoda Monte Carlo, różniczkowanie i całkowanie numeryczne) oraz zaawansowana optymalizacja.

## 💻 Środowisko i Kompilacja

Projekt jest rozwijany i testowany w środowisku **Linux**. 

Ze względu na wykorzystanie nowoczesnych funkcjonalności (C++20), mechanizmów takich jak `std::ranges` i `std::filesystem` oraz wielowątkowości, do kompilacji z poziomu terminala zalecane jest użycie flagi standardu oraz biblioteki `pthread` (dla wątków).

Przykładowe polecenie kompilacji przy użyciu GCC (`g++`):

```bash
g++ -std=c++20 -Wall -Wextra -pthread main.cpp -o program
./program
