//
// Created by Oz on 5/14/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_TEXT_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_TEXT_H


class Text {

public: //TODO: change to public
    char* pStore;
public:
    virtual ~Text();
    Text();
    Text(const Text&);
    Text(const char*);
    void assign(const char*);
    void assign(const Text&);
    Text operator= (const Text&);
    void append(const char*);
    void append(const Text&);
    void clear();
    int length();
    bool isEmpty() const;
    const char* getCstring() const;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_1_TEXT_H
