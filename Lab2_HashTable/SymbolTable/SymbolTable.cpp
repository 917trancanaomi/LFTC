//
// Created by Naomi on 10/26/2023.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    hashTable = *new HashTable<string>();
}

int SymbolTable::findPosition(string token) {
    return hashTable.findPosition(token);
}

int SymbolTable::deleteToken(string token) {
    return hashTable.deleteValue(token);
}

int SymbolTable::addToken(string token) {
    return hashTable.addValue(token);
}