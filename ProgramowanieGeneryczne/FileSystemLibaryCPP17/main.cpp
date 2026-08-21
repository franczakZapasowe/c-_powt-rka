#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>


struct Peopel {
    int year;
    int total;
};

void wypelnij (std::vector<Peopel> &pop) {
    int startYear = 2000;
    int start_total = 100;
    std::generate(pop.begin(),pop.end(),[&]() {
        Peopel p;
        p.year = startYear++;
        p.total += start_total*2;
        return p;
    });
}

int main() {
    std::vector<Peopel> pop (10);
    wypelnij(pop);
    FILE *plik = fopen("dane.txt", "w");
    if (plik == NULL) {
        std::cout << "Errore!" << std::endl;
        return 1;
    }
    int i =0;
    for (int i = 0; i < pop.size(); ++i)
        fprintf(plik, "Rok: %d, ludzi: %d\n", pop[i].year, pop[i].total);
    fclose(plik);

    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path sourceFile = currentPath / "dane.txt";

    std::filesystem::path newDir = "/home/mf/FolderNaKopieDanych";
    std::filesystem::create_directory(newDir);
    assert(!std::filesystem::create_directory(newDir));

    std::filesystem::path newFile = newDir / "dane.txt";
    std::filesystem::copy_file(sourceFile,newFile, std::filesystem::copy_options::overwrite_existing);

    std::filesystem::path daneDoUsuniecia = newDir / "daneDoUsuniecia.txt";
    std::filesystem::copy_file(sourceFile,daneDoUsuniecia,std::filesystem::copy_options::overwrite_existing);

    std::filesystem::remove(daneDoUsuniecia);



    return 0;
}