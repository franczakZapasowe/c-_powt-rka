# 🚀 C++ Masterclass: Kompendium Wiedzy i Powtórka

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![C++20](https://img.shields.io/badge/Standard-C%2B%2B20-blue?style=for-the-badge)

## 📖 O projekcie

To repozytorium stanowi kompleksową powtórkę oraz uporządkowane kompendium wiedzy z języka C++. Zakres materiału pokrywa pełne spektrum języka – od absolutnych podstaw i diagnostyki kodu, aż po zaawansowane mechanizmy wprowadzone w standardzie **C++20**, algorytmy i struktury danych, programowanie wielowątkowe oraz sieciowe. 

## 📂 Struktura repozytorium i zadania

Repozytorium zostało zaprojektowane z myślą o przejrzystości i łatwej nawigacji:

* **Każdy folder odpowiada za jedno, osobne zagadnienie** z języka C++ (np. wskaźniki, operacje tablicowe, złożone typy danych).
* W środku każdego z tych folderów znajduje się **kod źródłowy** (`.cpp`, `.hpp`) obrazujący dany temat.
* W plikach (lub folderach) zawarte są również **polecenia zadań**, na podstawie których powstały implementacje. 


## 💻 Środowisko i Kompilacja

Projekt jest rozwijany i testowany w środowisku **Linux**. 

Ze względu na wykorzystanie nowoczesnych funkcjonalności (C++20) oraz wielowątkowości, do kompilacji z poziomu terminala zalecane jest użycie flagi standardu oraz biblioteki `pthread` (dla wątków).

Przykładowe polecenie kompilacji przy użyciu GCC (`g++`):

```bash
g++ -std=c++20 -Wall -Wextra -pthread main.cpp -o program
./program
```
Autor:
Mirosław Franczak
