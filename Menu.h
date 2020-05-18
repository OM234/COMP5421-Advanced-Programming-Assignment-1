#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_MENU_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_MENU_H
#include "Text.h"


class Menu
{
public: //TODO : change to public
	
	Text* option_list;
	int capacity;
	int count;
	Text top_message;
	Text bottom_message;
	void double_capacity();

public:
	
	Menu();
	Menu(const Menu&);
	virtual ~Menu();
	Menu& operator=(const Menu& m);
	void insert(int, Text&);
	void insert(int, const char*);
	void push_back(const char*);
	void push_back(const Text&);
	void remove(int);
	int size() const;
	int getCapacity() const;
	void pop_back();
	Text get(int);
	Text toString() const;
	int read_option_number();
	void set_top_message(const Text&);
	void set_bottom_message(const Text&);
	void clear_top_message();
	void clear_bottom_message();
	bool isEmpty() const;
};

#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_MENU_H
