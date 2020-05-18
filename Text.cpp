//
// Created by Osman Momoh on 5/14/2020.
//

#include "Text.h"
#include <cstring> //for strcpy

using namespace std;

char* strConcat(const char* str1, const char* str2); // Helper function for concatenation (strcat was causing errors);

Text::~Text() {
    //cout << "deleting: " << pStore << endl;
    delete[] pStore; //TODO: should it be []?
}

Text::Text() {
    this->pStore = new char[1]{0};
}

Text::Text(const Text &txt) {
    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}

Text::Text(const char *pCstr) {
    this->pStore = new char[strlen(pCstr)];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const char *pCstr) {
    this->pStore = new char[strlen(pCstr)];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const Text &txt) {
    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}

Text &Text::operator=(const Text &txt) {

    if (this == &txt)    // if txt is this, return this
        return *this;

    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);

    return *this;
}

void Text::append(const char *pCstr) { 
    this->pStore = strConcat(this->pStore, pCstr);
}

void Text::append(const Text &txt) {    
    this->pStore = strConcat(this->pStore, txt.pStore); 
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

std::ostream& operator<<(std::ostream& sout, const Text& txt) {
    sout << txt.getCstring();
    return sout;
}

char* strConcat(const char* str1, const char* str2) {

    char* str3 = new char[strlen(str1) + strlen(str2)];

    for (int i = 0; i < strlen(str1); i++) {
        str3[i] = str1[i];
    }

    for (int i = strlen(str1); i < strlen(str1) + strlen(str2); i++) {
        str3[i] = str2[i - strlen(str1)];
    }

    str3[strlen(str1) + strlen(str2)] = 0;

    return str3;
}

