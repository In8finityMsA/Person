//
// Created by Admin on 04.11.2020.
//

#ifndef PERSON_LECTURE_PERSON_H
#define PERSON_LECTURE_PERSON_H


#include <string>

class Person {
private:
    const int ID;
    std::string name;
    static int nextID;
    void Clone(const Person& other);
public:
    Person(std::string aName);
    Person(const Person& other);
    Person& operator=(const Person& other);
    std::string getName() const;
    virtual ~Person();
};


#endif //PERSON_LECTURE_PERSON_H
