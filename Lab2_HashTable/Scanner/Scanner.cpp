//
// Created by Naomi on 10/27/2023.
//

#include <regex>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include "Scanner.h"

Scanner::Scanner() {
    tokensPopulate();
}

void Scanner::tokensPopulate() {
    ifstream fileForToken("C://Users//Naomi//Desktop//University Year 3//lftc//LFTC//Lab2_HashTable//Files//token.in");
    string token;

    while (fileForToken >> token) {
        token.erase(remove_if(token.begin(),
                              token.end(),
                              bind(isspace<char>,
                                   placeholders::_1,
                                   locale::classic())),
                    token.end());
        keywords.push_back(token);
    }

    fileForToken.close();
}

void Scanner::scanning(const string& filepath) {

    ifstream ipFile(filepath);

    char operators[] = "!%/*=<>+";
    char separators[] = "{}[](); ";
    char lines[100];
    int onLine = 1;
    bool ok = true;

    while(ipFile.getline(lines, 100)){
        string token;
        int lineLength = strlen(lines);

        for (int i = 0; i < lineLength; i++) {
            char thisChar = lines[i];

            if(strchr("\n\t ", thisChar) != nullptr) {
                if (!genPIF(token, onLine)){
                    ok = false;
                }
                token.clear();
            } else if(strchr(operators, thisChar) != nullptr) {
                if (!genPIF(token, onLine)){
                    ok = false;
                }
                token.clear();

                string operatorToken;
                operatorToken.push_back(thisChar);

                if(strchr("+-/*", thisChar) != nullptr && i+1 < lineLength && isdigit(lines[i+1]) != 0) {
                    token.push_back(thisChar);
                } else {
                    if(i+1 < lineLength && lines[i+1] == '=') {
                        operatorToken.push_back('=');
                        i++;
                    }
                    if (!genPIF(token, onLine)){
                        ok = false;
                    }
                }
            } else if(strchr(separators, thisChar) != nullptr) {
                if (!genPIF(token, onLine)){
                    ok = false;
                }
                token.clear();

            } else {
                    token.push_back(thisChar);
                }

        }

        if (!genPIF(token, onLine)){
            ok = false;
        }
        token.clear();
        onLine++;
    }

    if (ok == true ) {
        cout << "Lexically correct";
    }
    ipFile.close();
    writeOutput();
}

bool Scanner::genPIF(const string& token, int line) {
    if (!token.empty()) {
        if (find(keywords.begin(), keywords.end(), token) != keywords.end()) {
            PIF.emplace_back(make_pair(token, 0));
        } else {
            if (identifierFA.verifySequence(token)) {
                int index = st_identifiers.findPosition(token);
                PIF.emplace_back(make_pair("id", index));
            } else if (integerFA.verifySequence(token)) {
                int index = st_constants.findPosition(token);
                PIF.emplace_back(make_pair("const", index));
            } else {
                cout << "Lexical error! Unidentified token " << token << " on line " << line << endl;
                return false;

            }
        }
    }
    return true;

}

void Scanner::writeOutput() {
    ofstream STOutput;
    ofstream PIFOutput;

    STOutput.open("C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\Files\\ST.out");
    PIFOutput.open("C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\Files\\PIF.out");

    string STConst = st_constants.toString();
    string STId = st_identifiers.toString();

    STOutput << "Hashtable that uses coalesced chaining to handle collisions " <<"\n";
    STOutput << "Constants Symbol Table \n";
    STOutput << STConst << "\n";
    STOutput << "Identifiers Symbol table \n";
    STOutput << STId << "\n";

    PIFOutput << "token" << " | " <<  "position\n";

    for(auto &i: PIF) {
        PIFOutput << i.first << " | " << i.second << "\n";
    }

    STOutput.close();
    PIFOutput.close();
}
