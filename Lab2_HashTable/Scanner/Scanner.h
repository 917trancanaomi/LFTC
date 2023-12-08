//
// Created by Naomi on 10/27/2023.
//

#ifndef LAB2_HASHTABLE_SCANNER_H
#define LAB2_HASHTABLE_SCANNER_H

#include "../SymbolTable/SymbolTable.h"
#include <vector>
#include <string>
#include "../FiniteAutomaton/FiniteAutomaton.h"
using namespace std;


class Scanner {
private:
    FiniteAutomaton identifierFA = FiniteAutomaton("C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\IdentifierFA.in");
    FiniteAutomaton integerFA = FiniteAutomaton("C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\IntegerFA.in");
    SymbolTable st_identifiers;
    SymbolTable st_constants;
    vector<string> keywords;
    vector<pair<string, int>> PIF;

    string regexIdentifiers = "[a-zA-Z]{1}[a-zA-Z0-9]*";
    string regexInt = "(0|[+-]?[1-9][0-9]*)";
    string regexChar = "\'[a-zA-Z0-9]{1}\'";
    string regexString ="\"[a-zA-Z0-9]*\"";


    bool genPIF(const string& token, int index);

    void writeOutput();

    void tokensPopulate();

public:

    Scanner();

    void scanning(const string& filepath);
};


#endif //LAB2_HASHTABLE_SCANNER_H
