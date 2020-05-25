/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       5/14/2020, Summer 2020
*/

#include<iostream>
#include "Text.h"
#include "Menu.h"

using namespace std;

void demoText();
void demoMenu();
void extraDemoText(); // implements unimplemented functions of Text.h
void extraDemoMenu(); // implements unimplemented functions Menu.h

int main() {

    //demoText();
    //demoMenu();
    //extraDemoText(); // implements unimplemented functions of Text.h
    //extraDemoMenu(); // implements unimplemented functions Menu.h

    return 0;
}

void demoText() {

    Text t1;
    Text t2("quick brown fox");
    Text t3{t2};
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

void demoMenu() {

    Menu menu;

    menu.read_option_number();  //int choice and screen output are dealt with in this method

    menu.push_back("Pepsi");
    menu.read_option_number();

    menu.push_back("Apple juice");
    menu.push_back("Root beer");
    menu.read_option_number();

    menu.set_top_message("Choose your thirst quencher");
    menu.set_bottom_message("Enter a drink number");
    menu.read_option_number();

    menu.pop_back();
    menu.insert(2, "Iced tea with lemon");
    menu.read_option_number();

    menu.pop_back();
    menu.remove(1);
    menu.read_option_number();

    menu.pop_back();
    menu.read_option_number();

    menu.clear_bottom_message();
    menu.set_top_message("Who Says You Can't Buy Happiness?\n"
                         "Just Consider Our Seriously Delicious Ice Cream Flavors");
    menu.set_bottom_message("Enter the number of your Happiness! ");
    menu.push_back("Bacon ice cream");
    menu.push_back("Strawberry ice cream");
    menu.push_back("Vanilla ice cream");
    menu.push_back("Chocolate chip cookie dough ice cream");
    menu.read_option_number();
}

void extraDemoText() {

    Text t1 = ("This is t1");
    Text t2 = ("This is t2");

    cout << "Value of Text t1 before assign: " << t1 << endl;

    t1.assign(t2); // implementation of void assign(const Text&)
    cout << "Value of Text t1 after assign: " << t1 << endl;
    cout << "Is t1 empty? " << t1.isEmpty() << endl; // implementation of bool isEmpty() const

    cout << "Length of t1: " << t1.length() << endl; // implementation of int length() const

    t1.clear(); // implementation of void clear()
    cout << "Value of Text t1 after clear: " << t1 << endl;
    cout << "Is t1 empty? " << t1.isEmpty() << endl;
}

void extraDemoMenu() {

    Menu m1;
    cout << "\nm1 capacity: " << m1.getCapacity() << endl; // implementation of int getCapacity() const
    cout << "m1 count: " << m1.getCount() << endl; // implementation of int getCount() const
    cout << "Is m1 empty? " << m1.isEmpty() << endl; // implementation of bool isEmpty() const;

    m1.push_back(Text("first")); // implementation of void push_back(const Text&)
    m1.push_back(Text("second"));
    cout << "\nm1 after push_back: " << m1 << endl;

    cout << "\nm1 capacity: " << m1.getCapacity() << endl;
    cout << "m1 count: " << m1.getCount() << endl;
    cout << "Is m1 empty? " << m1.isEmpty() << endl; // implementation of bool isEmpty() const;
    cout << "\n1. value: " << m1.getText(1) << endl; // implementation of const Text getText(int) const

    m1.set_top_message("This is the top message");
    cout << "\nm1 with top message\n" << m1 << endl;
    m1.clear_top_message(); //implements void clear_top_message()
    cout << "\nm1 without top message\n" << m1 << endl;
}