#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  // NOWOŚĆ: funkcja inet_pton
#include <unistd.h>
#include <cstring>      // dla strlen()

int main() {

    int klient_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (klient_fd == -1) {
        std::cerr << "Błąd: Nie można stworzyć socketu!\n";
        return 1;
    }

    //forumalrz adresowy dla serwera
    constexpr int PORT = 5000;
    sockaddr_in serv_addr{};


}