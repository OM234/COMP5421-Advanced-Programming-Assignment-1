//
// Created by Oz on 5/14/2020.
//

#include "Text.h"
#include <cstring> //for strcpy

Text::~Text() {
    delete pStore; //TODO: should it be []?
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
    //this->pStore = new char[strlen(pCstr)];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const Text &txt) {
    //this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}

Text &Text::operator=(const Text &txt) {

    if (this == &txt)    // if txt is this, return this
        return *this;

    //this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);

    return *this;
}

void Text::append(const char *pCstr) {
    strcat(this->pStore, pCstr);
}

void Text::append(const Text &txt) {
    strcat(this->pStore, txt.pStore);
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



