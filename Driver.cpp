//
// Created by Osman Momoh on 5/14/2020.
//

#include<iostream>
#include "Text.h"
#include "Menu.h"

using namespace std;

void demoText();

int main2() {  //TODO: change to main

    demoText();
    return 0;
}

void demoText() {

    Text t1;
    Text t2("quick brown fox");
    Text t3{ t2 };
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    t1.append("The ");
    cout << "t1: " << t1 << endl;
    t1.append(t2);
    cout << "t1: " << t1 << endl;

    t2 = Text(" jumps over ");
    cout << "t2: " << t2 << endl;

    t3.assign("a lazy dog");
    cout << "t3: " << t3 << endl;

    t1.append(t2);
    cout << "t1: " << t1 << endl;
    t1.append(t3);
    cout << "t1: " << t1 << endl;

    return;
}