//
// Created by Oz on 5/15/2020.
//

#include<iostream>
#include "Text.h"

using namespace std;

int main() {

    Text a{"abc"};
    Text b{a};
    Text d{"defg"};
    Text c;
    c.assign(b);
    c.append(d);
    const char* f = a.getCstring();
    cout << f << endl;
    cout << a.getCstring() << endl;
//    b.assign(a);

    return 0;

}