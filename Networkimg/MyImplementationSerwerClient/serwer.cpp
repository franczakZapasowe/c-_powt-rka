#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
int main() {

    //zaczynamy od stworzenia gniazda glownego
    int mainSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mainSocket == -1) {
        std::cerr<<"Nie mozna stworzyc gniazda\n";
        return 1;
    }

    constexpr int PORT = 5000;
    sockaddr_in server{};
    server.sin_family = AF_INET; //IPV4
    server.sin_addr.s_addr = INADDR_ANY; // POZWALAMY NA WSZYSTKie ADRESY
    server.sin_port = htons(PORT);

    //musimy teraz zbidnowac to
    auto *bindAdres = reinterpret_cast<sockaddr*>(&server);
    if (bind(mainSocket, bindAdres, sizeof(server))==-1) {
        std::cerr<<"Nie udalo sie zbindowac\n";
        return 1;
    }

    // teraz nasluchujemy
    if (listen(mainSocket,10)==-1) {
        std::cerr<<"Nie przyhodza zadni klienci\n";
        return 1;
    }

    // musimy stowrzyc "pusta strukture na klienta - system wpisze do niej adres ip klienta"
    sockaddr_in client{};
    socklen_t clientLen = sizeof(client);
    auto *clientAdres = reinterpret_cast<sockaddr*>(&client);

    auto deskryptorKlient = accept(mainSocket,clientAdres,&clientLen);
    if (deskryptorKlient == -1) {
        std::cerr<<"Nie udalo sie polaczyc\n";
        return 1;
    }

    const char*text = "Polaczyles sie z serwerem czekam na wiadomosc od cb\n";
    send(deskryptorKlient,text, strlen(text),0);

    char buffer[1024]={};
    auto rec = recv(deskryptorKlient,buffer,sizeof(buffer),0);
    if (rec>0) std::cout<<buffer<<std::endl;

    close(deskryptorKlient);
    close(mainSocket);
}