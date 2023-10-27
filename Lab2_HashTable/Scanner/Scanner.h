//
// Created by Naomi on 10/27/2023.
//

#ifndef LAB2_HASHTABLE_SCANNER_H
#define LAB2_HASHTABLE_SCANNER_H

#include "../SymbolTable/SymbolTable.h"
#include <vector>
#include <string>
using namespace std;


class Scanner {
private:
    SymbolTable st_identifiers;
    SymbolTable st_constants;

public:

    void scanning();
};


#endif //LAB2_HASHTABLE_SCANNER_H
