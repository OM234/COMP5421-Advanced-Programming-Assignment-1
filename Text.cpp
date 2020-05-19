/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       5/14/2020, Summer 2020
*/

#include "Text.h"
#include <cstring> //for strcpy

using namespace std;

char* strConcat(const char* str1, const char* str2); // Helper method for concatenation (strcat was causing errors);

Text::~Text() {
    delete[] pStore;
}

Text::Text() {
    this->pStore = new char[1]{0};  //default constructor creates char array with only /0 character
}

Text::Text(const Text &txt) {
    this->pStore = new char[strlen(txt.pStore)+1];  //creates a char array of appropriate size (+1 for /0 character)
    strcpy(this->pStore, txt.pStore);   //copies the char* of txt into this
}

Text::Text(const char *pCstr) {
    this->pStore = new char[strlen(pCstr)+1];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const char *pCstr) {
    this->pStore = new char[strlen(pCstr)+1];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const Text &txt) {
    this->pStore = new char[strlen(txt.pStore)+1];
    strcpy(this->pStore, txt.pStore);
}

Text &Text::operator=(const Text &txt) { //operator = override

    if (this == &txt)    // if txt is this, return this
        return *this;

    this->pStore = new char[strlen(txt.pStore)+1];
    strcpy(this->pStore, txt.pStore);

    return *this;
}

void Text::append(const char *pCstr) {
    this->pStore = strConcat(this->pStore, pCstr); //uses helper method instead of cstring library
}

void Text::append(const Text &txt) {
    this->pStore = strConcat(this->pStore, txt.pStore); //uses helper method instead of cstring library
}

void Text::clear() {
    this->pStore = new char[1]{0};
}

int Text::length() const {
    return strlen(this->pStore);
}

bool Text::isEmpty() const {
    if(strlen(this->pStore) == 0)
        return true;
    else
        return false;
}

const char* Text::getCstring() const {
    return this->pStore;
}

std::ostream& operator<<(std::ostream& sout, const Text& txt) { //operator << override
    sout << txt.getCstring();
    return sout;
}

char* strConcat(const char* str1, const char* str2) { //helper method for concatenation

    char* str3 = new char[strlen(str1) + strlen(str2)+1]; // return string (+1 length for \0 character)

    for (int i = 0; i < strlen(str1); i++) { //copies first string
        str3[i] = str1[i];
    }

    for (int i = strlen(str1); i < strlen(str1) + strlen(str2); i++) { //copies second string
        str3[i] = str2[i - strlen(str1)];
    }

    str3[strlen(str1) + strlen(str2)] = 0;

    return str3;
}

