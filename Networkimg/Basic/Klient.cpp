//
// Created by mf on 8/24/26.
//
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  // NOWOŚĆ: funkcja inet_pton
#include <unistd.h>
#include <cstring>      // dla strlen()

int main() {

    int klient_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (klient_fd == -1) {
        std::cout << "Could not create socket.\n";
        return 1;
    }
    constexpr int PORT = 5000;
    sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    auto*adres_wskaznik = reinterpret_cast<sockaddr*>(&serv_addr);
    std::cout << "Próba połączenia z serwerem...\n";
    if (connect(klient_fd, adres_wskaznik, sizeof(serv_addr)) == -1) {
        std::cerr << "Błąd połączenia! Czy serwer na pewno jest włączony?\n";
        return 1;
    }
    std::cout << "Połączono z serwerem!\n";

    char bufor[1024] = {0};
    int odebrane = recv(klient_fd, bufor, 1024, 0);
    if (odebrane > 0) {
        std::cout << "Serwer mówi: " << bufor << "\n";
    }

    const char* odpowiedz = "Siemano, tu klient C++!";
    send(klient_fd, odpowiedz, strlen(odpowiedz), 0);
    std::cout << "Wysłano odpowiedź do serwera.\n";

    // 6. Kończymy pracę
    close(klient_fd);
    std::cout << "Klient zakończył pracę.\n";

    return 0;
}