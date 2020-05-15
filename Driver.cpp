//
// Created by Oz on 5/15/2020.
//

#include<iostream>
#include "Text.h"

using namespace std;

int main() {

    Text a{"abc"};
    a.assign("hil");
    Text b{"no"};
    b.assign(a);
    b.assign("123");
    cout << b.pStore << endl;
//    b.assign(a);

    return 0;

}