#include "Menu.h"
#include <iostream>
#include <ostream>
#include <string> //exclusively for use of to_string to convert numbers to string

using namespace std;

Menu::Menu() {
    this->bottom_message;
    this->top_message;
    this->option_list = new Text[1];
    this->count = 0;
    this->capacity = 1;
}

Menu::Menu(const Menu &mnu) {
    this->bottom_message = mnu.bottom_message;
    this->top_message = mnu.top_message;
    this->count = mnu.count;
    this->capacity = mnu.capacity;
    this->option_list = new Text[this->capacity];

    for (int i = 0; i < count; i++) {
        this->option_list[i] = mnu.option_list[i];
    }
}

Menu::~Menu() {
    //cout << "destructor 0: " << option_list[0] << endl; //TODO: Delete
    //cout << "deleting: " << this->option_list << endl;
    delete[] option_list;
}

Menu &Menu::operator=(const Menu &mnu) {

    this->bottom_message = mnu.bottom_message;
    this->top_message = mnu.top_message;
    this->count = mnu.count;
    this->capacity = mnu.capacity;
    this->option_list = new Text[this->capacity];

    for (int i = 0; i < count; i++) {
        this->option_list[i] = mnu.option_list[i];
    }

    return *this;
}

void Menu::insert(int index, const Text &option) {

    if (this->count == this->capacity) {
        //double_capacity();
    }

    for (int i = this->count - 1; i >= index - 1; i--) {
        this->option_list[i + 1] = this->option_list[i];
    }

    this->option_list[index - 1] = option.getCstring();
    //cout << "inserting: " << option.getCstring();
    this->count++;
}

void Menu::insert(int index, const char *option) {

    //if (this->count == this->capacity) {
    //	//double_capacity();
    //}

    //for (int i = this->count - 1; i >= index - 1; i--) {
    //	this->option_list[i + 1] = this->option_list[i];
    //}

    //this->option_list[index - 1] = option;
    //this->count++;

    this->insert(index, Text(option));
}

void Menu::push_back(const Text &option) {

    //if (this->count == this->capacity) {
    //	//double_capacity();
    //}

    //this->option_list[this->count] = option;
    //this->count++;

    this->insert(count + 1, option);
}

void Menu::push_back(const char *option) {

    //if (this->count == this->capacity) {
    //	//double_capacity();
    //}

    //this->option_list[this->count] = option;
    //this->count++;

    this->insert(count + 1, option);
}

void Menu::remove(int index) {

    for (int i = index - 1; i < this->count; i++) {
        this->option_list[i] = this->option_list[i + 1];
    }

    this->count--;
}

void Menu::pop_back() {

    this->remove(this->count);
}

int Menu::getCount() const {

    return this->count;
}

int Menu::getCapacity() const {

    return this->capacity;
}

const Text Menu::getText(int option) const {

    return this->option_list[option - 1];
}

const Text Menu::toString() const {

    Text str{};
    str.append(this->top_message);

    for (int i = 0; i < count; i++) {
        str.append("\n");
        str.append("\t");
        str.append(std::to_string(i + 1).c_str());
        str.append(". ");
        str.append(this->option_list[i]);
        //str.append("\n");
    }
    str.append("\n");
    str.append(this->bottom_message);
    str.append("\n");

    return str;
}

int Menu::read_option_number() {
    int choice{};
    cin >> choice;
    return choice;
}

void Menu::set_top_message(const Text &topMsg) {
    this->top_message = topMsg;
}

void Menu::set_bottom_message (const Text& topMsg){
    this->bottom_message = topMsg;
}

void Menu::clear_top_message() {
    this->top_message = "";
}

void Menu::clear_bottom_message() {
    this->bottom_message = "";
}

bool Menu::isEmpty() const {
    return (count == 0);
}

std::ostream &operator<<(std::ostream &sout, const Menu &mnu) {
    sout << mnu.toString();
    sout << "?? ";
    return sout;
}

int main2() {

    Menu aMenu{};
    aMenu.capacity = 10;
    aMenu.bottom_message = "GOODBYE";
    aMenu.top_message = "HELLO";
    aMenu.count = 3;
    aMenu.option_list = new Text[aMenu.capacity];

    for (int i = 0; i < aMenu.count; i++) {
        aMenu.option_list[i] = "hello";
        //cout << aMenu.option_list[i] << endl;
    }

    Menu bMenu;
    bMenu = aMenu;
    //bMenu.option_list[2] = "firstNow";
    //bMenu.insert(2, Text{ "firstnow" });
    bMenu.insert(1, "first again");
    //bMenu.push_back("last");
    //bMenu.remove(2);
    //bMenu.remove(3);
    //bMenu.pop_back();

    for (int i = 0; i < bMenu.count; i++) {
        //cout << bMenu.option_list[i] << endl;
    }
    Menu cMenu{};
    cout << bMenu;
    //cout << bMenu.getText(1) << endl;
    int choice = bMenu.read_option_number();

    while (choice < 1 || choice > bMenu.count) {
        cout << "invalid choice " << choice << ". It must be in the range"
             << "[1, " << bMenu.count << "]" << endl;
        cout << bMenu;
        choice = bMenu.read_option_number();
    }
    cout << "You entered: " << choice;
    return 0;
}