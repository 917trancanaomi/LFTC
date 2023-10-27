//
// Created by Naomi on 10/26/2023.
//

#ifndef LAB2_HASHTABLE_HASHTABLE_H
#define LAB2_HASHTABLE_HASHTABLE_H

using namespace std;

#include <vector>

template<class T>
struct HashEntry {
    T token;
    int next = -1;
};

template<class T>
class HashTable {
private:

    vector<HashEntry<T>> table;
    int size = 103;

    int hashFn(T element);

    int findNextPositionAvailable();

public:
    HashTable();

    HashTable(HashTable &hTable);

    int addValue(T element);

    int findPosition(T element);

    int containsValue(T element);

    int deleteValue(T element);

};


template<class T>
int HashTable<T>::hashFn(T element) {
    int sum = 0;
    for (char ch: element) {
        sum += (int) ch;
    }

    return sum % size;
}

template<class T>
HashTable<T>::HashTable() {
    table = vector<HashEntry<T>>(size);
}

template<class T>
HashTable<T>::HashTable(HashTable &hTable) {
    this->table = hTable.table;
    this->size = hTable.size;
}

template<class T>
int HashTable<T>::findNextPositionAvailable() {
    for (int pos; pos < table.size(); pos++) {
        if (table[pos].token == "")
            return pos;
    }
}

template<class T>
int HashTable<T>::addValue(T element) {
    int newPos = findNextPositionAvailable();

    table[newPos].token = element;
    table[newPos].next = -1;

    return newPos;
}

template<class T>
int HashTable<T>::findPosition(T element) {
    int value = hashFn(element);
    while (element != table[value].token && table[value].next != -1) {
        value = table[value].next;
    }

    if (element == table[value].token)
        return value;
    else {
        if (table[value].token == "") {
            table[value].token = element;
            table[value].next = -1;
            return value;
        } else {
            int newPos = addValue(element);
            table[value].next = newPos;
            return newPos;
        }
    };
}

template<class T>
int HashTable<T>::containsValue(T element) {
    int value = hashFn(element);
    while (element != table[value].token && table[value].next != -1) {
        value = table[value].next;
    }

    if (element == table[value].token)
        return value;
    return -1;
}

template<class T>
int HashTable<T>::deleteValue(T element) {
    int pos = containsValue(element);
    if (table[pos].next == -1) {
        table[pos].token = "";
        return pos;
    } else {
        int value = hashFn(element);

        while (table[value].next != pos) {
            value = table[value].next;
        }

        table[value].next = table[pos].next;
        table[pos].token = "";
        table[pos].next = -1;

        return pos;
    }
}

#endif //LAB2_HASHTABLE_HASHTABLE_H
