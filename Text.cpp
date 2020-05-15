//
// Created by Oz on 5/14/2020.
//

#include "Text.h"
#include <cstring> //for strcpy

Text::~Text() {
    delete pStore; //TODO: should it be []?
}

Text::Text() {
    this->pStore = new char[0];
}

Text::Text(const Text& txt) {
    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}

Text::Text(const char* pCstr) {
    this->pStore = new char[strlen(pCstr)];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const char* pCstr) {
    this->pStore = new char[strlen(pCstr)];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const Text& txt) {
    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}


