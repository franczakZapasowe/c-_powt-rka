//
// Created by mf on 8/24/26.
//
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int mainSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mainSocket == -1) {
        std::cout << "socket creation failed" << std::endl;
        return 1;
    }

    constexpr int PORT = 5000;
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr)!=1) {
        std::cout << "inet_pton failed" << std::endl;
        return 1;
    }

    if (connect(mainSocket, reinterpret_cast<sockaddr*>(&server), sizeof(server))==-1) {
        std::cout << "connect failed" << std::endl;
        return 1;
    }
    char buffer[1024]{};
    auto rec = recv(mainSocket, buffer, 1024, 0);
    if (rec>0) std::cout << buffer << std::endl;
    const char* text = "Pierwsza waidomosc klienta\n";
    send(mainSocket, text, strlen(text), 0);
    close(mainSocket);
}