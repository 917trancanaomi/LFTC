//
// Created by Naomi on 10/27/2023.
//

#include "Scanner.h"

void Scanner::scanning() {
    string fileName;
    printf("Enter a file to scan: ");
    scanf("%s", &fileName);
    printf("File name %s", &fileName);

    ifstream file (fileName);
    while(!file.eof())
    {
        
    }
}