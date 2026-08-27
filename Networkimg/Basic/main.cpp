#include <cstring>
#include <iostream>
#include <sys/socket.h> // Główne funkcje socketów (np. socket(), bind())
#include <netinet/in.h> // Struktury adresów internetowych (np. sockaddr_in)
#include <unistd.h>     // Funkcje systemowe (np. close())

int main() {

    int serwer_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (serwer_fd == -1) {
        std::cerr<<"Nie mozna stowrzyc socketu\n";
        return 1;
    }
    std::cout << "Socket utworzony. Twój deskryptor to: " << serwer_fd << "\n";

    constexpr int PORT = 5000;
    sockaddr_in address{};

    address.sin_family = AF_INET; // potwierdamy ze to ipv4
    address.sin_addr.s_addr = INADDR_ANY; // nasluchuje na kazdym interfesie ciesiowym
    address.sin_port = htons(PORT); //port

    auto *bind_addr = reinterpret_cast<sockaddr*>(&address);
    if (bind(serwer_fd, bind_addr, sizeof(address)) == -1) {
        std::cerr << "Błąd bindowania! Port " << PORT << " może być już zajęty.\n";
        return 1;
    }
    std::cout << "Socket pomyślnie przypisany do portu " << PORT << ".\n";

    if (listen(serwer_fd, 10) == -1) {
        std::cerr << "Błąd podczas próby nasłuchiwania!\n";
        return 1;
    }
    std::cout << "Serwer czeka na połączenia na porcie " << PORT << "...\n";

    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);  //ile pamieci przygtowac

    std::cout << "Czekam na klienta (program w tym miejscu się zatrzymuje)...\n";

    int klient_fd = accept(serwer_fd,reinterpret_cast<sockaddr*>(&client_addr),&client_len);
    if (klient_fd == -1) {
        std::cerr << "Błąd przy akceptowaniu połączenia!\n";
        return 1;
    }
    std::cout << "Mamy klienta! Utworzono NOWY socket do rozmowy: " << klient_fd << "\n";

    const char*wiadomosc = "czesc tu serwer c++\n";
    send(klient_fd, wiadomosc, strlen(wiadomosc), 0);
    std::cout << "Wysłano wiadomość powitalną.\n";

    char bufor[1024] = {0};
    std::cout << "Czekam na odpowiedź od klienta...\n";
    int bajty_odebrane = recv(klient_fd, bufor, 1024, 0);

    if (bajty_odebrane > 0) {
        std::cout << "Klient napisał: " << bufor << "\n";
    }

    close(klient_fd);
    close(serwer_fd);
    return 0;
}