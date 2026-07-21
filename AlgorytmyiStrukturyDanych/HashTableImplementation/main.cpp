#include <iostream>
#include <list>
#include <cstring>

using namespace std;


// HashTAble to implement 500, Arutr
class HasTable {
private:
    static const int hashGroups = 10;
    list<pair<int,string>> table[hashGroups]; // List1, Inde 0

public:
    bool isEmpty()const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string serchTAble(int key);
    void printTable();
};

bool HasTable::isEmpty() const {
    int sum{};
    for (int i{}; i<hashGroups;i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HasTable::hashFunction(int key) {
    return key % hashGroups;
}

void HasTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto&cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout<<"Key exists, value replaced "<<endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HasTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto&cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout<<"Item removed "<<endl;
            break;
        }
    }
    if (!keyExists) {
        cout<<"Item not found"<<endl;
    }
    return;
}

void HasTable::printTable() {
    for (int i {}; i<hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bIter = table[i].begin();
        for (;bIter!=table[i].end();bIter++) {
            cout<<"KEY: "<<bIter->first<<" Value: "<<bIter->second<<endl;
        }
    }
    return;
}

int main() {
    HasTable ht;

    if (ht.isEmpty()) {
        cout<<"Table is empty"<<endl;
    } else {
        cout<<"Table is not empty"<<endl;
    }

    ht.insertItem(1, "Hello");
    ht.insertItem(12, "HI");
    ht.insertItem(51, "CZESC");
    ht.insertItem(11, "JO");
    ht.insertItem(631, "HEJ");
    ht.insertItem(631, "HelloKI");
    ht.printTable();
    ht.removeItem(51);
    ht.removeItem(531);

    if (ht.isEmpty()) {
        cout<<"Table is empty"<<endl;
    } else {
        cout<<"Table is not empty"<<endl;
    }

}