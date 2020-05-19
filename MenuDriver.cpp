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

int main() {

    //demoText();
    //demoMenu();
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