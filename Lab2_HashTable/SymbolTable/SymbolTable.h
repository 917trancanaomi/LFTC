//
// Created by Naomi on 10/26/2023.
//

#ifndef LAB2_HASHTABLE_SYMBOLTABLE_H
#define LAB2_HASHTABLE_SYMBOLTABLE_H

using namespace std;

#include <string>
#include <vector>
#include <fstream>
#include "../HashTable/HashTable.h"

class SymbolTable {
private:
    HashTable<string> hashTable;

public:

    SymbolTable();

    int findPosition(string token);

    int deleteToken(string token);

    int addToken(string token);

    string toString();
};

#endif //LAB2_HASHTABLE_SYMBOLTABLE_H
