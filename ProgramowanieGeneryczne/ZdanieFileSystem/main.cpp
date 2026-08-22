#include <filesystem>
#include <iostream>
#include <string>
#include <functional>
#include <cstdio>

void generuj(std::filesystem::path path) {
    FILE * plik = nullptr;
    std::filesystem::path path0 = path/"preset1.txt";
    std::filesystem::path path1 = path/"preset2.txt";
    std::filesystem::path path2 = path/"cache.tmp";
    std::string p1Str = path0.string();
    std::string p2Str = path1.string();
    std::string p3Str = path2.string();

    plik = fopen(p1Str.c_str(), "w");
    if (plik != nullptr) {
        fprintf(plik, "Gain: %lfdB\n",4.5 );
        fclose(plik);
    }
    plik = fopen(p2Str.c_str(), "w");
    if (plik != nullptr) {
        fprintf(plik, "Gain: %lfdB\n",4.5 );
        fclose(plik);
    }
    plik = fopen(p3Str.c_str(), "w");
    if (plik != nullptr) {
        fprintf(plik, "Gain: %lfdB\n",4.5 );
        fclose(plik);
    }

}

int main() {
    std::filesystem::path curent = std::filesystem::current_path();
    std::filesystem::path curentAudio = curent / "AudioProjects";
    std::filesystem::path eqPath = curentAudio/"EQ";
    std::filesystem::path compressorPath = curentAudio/"Compressor";
    std::filesystem::path reverbPath = curentAudio/"Reverb";

    std::filesystem::create_directories(eqPath);
    std::filesystem::create_directories(compressorPath);
    std::filesystem::create_directories(reverbPath);

    generuj(eqPath);
    generuj(compressorPath);
    generuj(reverbPath);

    std::cout<<"Serhing directory:\n";
    for (auto &entry : std::filesystem::recursive_directory_iterator{curentAudio}) {
        if (entry.path().extension() == ".tmp") {
            std::filesystem::remove(entry.path());
        }
    }

    std::filesystem::path newPath = curent/"AudioBackup";
    std::filesystem::create_directories(newPath);

    


}