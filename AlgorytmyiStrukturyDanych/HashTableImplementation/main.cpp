#include <iostream>
#include <list>
#include <cstring>

using namespace std;
//#define WWERSJA
#ifdef WWERSJA
// HasTable
// isEMpty, insert, hashFunction removeItem serchTAble, printTAble
// HashTAble to implement key(int), value(string)
class Hash {
private:
    static const int hashGroups = 10;
    list<pair<int,string>>table[hashGroups];
public:
    bool isEmpty();
    int hashFunction(int key);
    void insert(int key, string value);
    void removeItem(int key);
    string serchTAble(int key);
    void printTable();
};

bool Hash::isEmpty() {
    int suma = 0;
    for (int i = 0; i < hashGroups; i++) {
        suma+=table[i].size();
    }
    if (suma==0) return true;
    return false;
}

int Hash::hashFunction(int key) {
    return key%hashGroups;
}

void Hash::insert(int key, string value) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto it = begin(cell);
    bool keyExisiting = false;
    for (; it!=end(cell); ++it) {
        if (it->first == key) {
            keyExisiting = true;
            it -> second = value;
            cout<<"[INFO] key exisitng, value replaced\n";
            break;
        }
    }
    if (!keyExisiting) {
        cell.emplace_back(key, value);
        cout<<"[INFO] key is not exisitng, new value added\n";
    }
    return;
}

void Hash::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto&cell = table[hashValue];
    auto it  = begin(cell);
    bool keyExisiting = false;
    for (; it!=end(cell); ++it) {
        if (it->first == key) {
            keyExisiting = true;
            it = cell.erase(it);
            cout<<"Key is existing, Value removed\n";
            break;
        }
    }
    if (!keyExisiting) {
        cout<<"Key is not existing, none value removed\n";
    }
}

string Hash::serchTAble(int key) {
    int hashValue = hashFunction(key);
    auto&cell = table[hashValue];
    auto it  = begin(cell);
    bool keyExisiting = false;
    for (; it!=end(cell); ++it) {
        if (it ->first == key) {
            keyExisiting = true;
            return it->second;
        }
    }
    if (!keyExisiting) {
        return "";
    }
}

void Hash::printTable() {
    int suma = 0;
    for (int i =0; i<hashGroups; i++) {
        if (table[i].empty()) {
            suma+=table[i].size();
            continue;
        }
        auto it  = table[i].begin();
        while (it!=end(table[i])) {
            cout<<"KEY: "<<it->first<<" VALUE: "<<it->second<<"\n";
            it++;
        }
    }
    if (suma==0) cout<<"TABLE IS EMPTY\n";
    return;
}

int main() {

    Hash hash;
    cout<<"IsEmpty TEST:\n";

    if (hash.isEmpty()) cout<<"Hash is empty\n";
    else cout<<"Hash is not empty\n";
    cout<<"Print table TEST:\n";
    hash.printTable();

    hash.insert(10, "Pilka");
    hash.insert(12, "Rower");
    hash.insert(13, "Balon");

    hash.printTable();

    cout<<"Remove TEST:\n";
    hash.removeItem(12);
    hash.printTable();

    cout<<"Insert in same index (10) - OLD VALUE - Pilka, NEW VALUE - Samolot\n";
    hash.insert(10, "Samolot");

    cout<<"SerchTAble\n";
    cout<<"Wartosc: "<<hash.serchTAble(10);
}

#else

struct Node {
    int key;
    string value;
};


int main() {
    return 0;
}
#endif
