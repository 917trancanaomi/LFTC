//
// Created by Naomi on 10/27/2023.
//

#include <regex>
#include <iostream>
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
    char separators[] = "{}[]();";
    char lines[100];
    int onLine = 1;

    while(ipFile.getline(lines, 100)){
        string token;
        int lineLength = strlen(lines);

        for (int i = 0; i < lineLength; i++) {
            char thisChar = lines[i];

            if(strchr("\n\t", thisChar) != nullptr) {
                genPIF(token, onLine);
                token.clear();
            } else if(strchr(operators, thisChar) != nullptr) {
                genPIF(token, onLine);
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
                    genPIF(operatorToken, onLine);
                }
            } else {
                token.push_back(thisChar);
            }
        }

        genPIF(token, onLine);
        token.clear();
        onLine++;
    }

    ipFile.close();
    cout<<"lexically correct"<<endl;
    writeOutput();
}


