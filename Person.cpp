//
// Created by Admin on 04.11.2020.
//

#include "Person.h"
#include <cstring>
#include <exception>

int Person::nextID = 0;

Person::Person(std::string aName): ID(nextID++)
{
    if (aName.empty()) {
        throw std::exception("Name is empty!");
    }

    name = aName;
}

Person::Person(const Person& other): ID(nextID++)
{
    Clone(other);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        Clone(other);
    }
    return *this;
}

std::string Person::getName() const {
    return name;
}

Person::~Person() {
    Erase();
}

void Person::Clone(const Person& other) {
    name = other.name;
}