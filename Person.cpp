//
// Created by Admin on 04.11.2020.
//

#include "Person.h"
#include <exception>
#include <iostream>
#include <limits>
#include <random>
#include <memory>

int Person::nextID = 2;
static bool isAdamCreated = false;
static bool isEvaCreated = false;
static constexpr int AdamID = 0;
static constexpr int EvaID = 1;

//region Constructors
Person::Person(const std::string& name, Sex sex, Status status, unsigned int age, Person* mother, Person* father): id(nextID++)
{
    if (mother == nullptr) {
        throw std::exception("Mother is not specified");
    }
    if (mother->_sex == Sex::MALE) {
        throw std::exception("Mother must be female");
    }

    if (father != nullptr && father->_sex == Sex::FEMALE) {
        throw std::exception("Father must be male");
    }

    if (name.empty()) {
        throw std::exception("Name is empty!");
    }

    _mother = mother;
    _father = father;

    _name = name;
    _sex = sex;
    _status = status;
    _age = age;
}

Person::Person(int id, const std::string& name, Sex sex, Status status, unsigned int age) : id(id) {
    _name = name;
    _sex = sex;
    _status = status;
    _age = age;
}

Person::Person(const Person& other) : id(-1) {
    throw std::exception("No clones here. We don't want Order 66, right?");
}
//endregion

//region First people
Person Person::getAdam() {
    if (isAdamCreated) {
        throw std::exception("Adam has already been created");
    }
    isAdamCreated = true;
    return Person(AdamID, "Adam", Sex::MALE, Status::ALIVE, 7529);
}

Person Person::getEva() {
    if (isEvaCreated) {
        throw std::exception("Eva has already been created");
    }
    isEvaCreated = true;
    return Person(EvaID, "Eva", Sex::FEMALE, Status::ALIVE, 7529);
}
//endregion

//region Birth funcs
Person Person::giveBirth(const std::string& name, const Sex& sex, Person* father) {
    if (this->_status == Status::DEAD || (father != nullptr && father->_status == Status::DEAD)) {
        throw std::exception("Parents must be alive to give birth");
    }
    return Person(name, sex, Status::ALIVE, 0, this, father);
}

std::shared_ptr<Person> Person::haveSex(Person* partner, bool condom, const std::string& name) {
    if (this->_status == Status::DEAD) {
        throw std::exception("Dead person can't have sex, I guess");
    }

    if (partner == nullptr) {
        std::cout << "Having fun alone" << std::endl;
    }
    else if (partner->_status == Status::DEAD) {
        std::cout << "Oh, you are a necrophiliac. What a filth.";
    }
    else {
        if (this->_sex == partner->_sex) {
            std::cout << "Welcome to LGBT club" << std::endl;
        } else if (this->_sex != partner->_sex) {

            std::cout << "Fe, getero" << std::endl;

            float probability;
            if (condom) {
                probability = 0.01;
            } else {
                probability = 0.2;
            }
            std::uniform_real_distribution<> dis(0.0f, 1.0f);
            std::random_device rd;
            std::mt19937 gen(rd());
            float dice = dis(gen);
            if (dice <= probability) {
                std::cout << "You have a baby!" << std::endl;
                std::shared_ptr<Person> p(new Person(
                        name,
                        dice <= probability / 2 ? Sex::FEMALE : Sex::MALE,
                        Status::ALIVE,
                        0,
                        this->_sex == Sex::FEMALE ? this : partner,
                        this->_sex == Sex::FEMALE ? partner : this));
                return p;
            }
        }
    }

    return nullptr;
}
//endregion

//region Getters
std::string Person::getName() const {
    return _name;
}

const int Person::getID() const {
    return id;
}

const Person* Person::getMother() const {
    if (_mother == nullptr) {
        throw std::exception("There is no mother");
    }
    return _mother;
}

const Person* Person::getFather() const {
    if (_father == nullptr) {
        throw std::exception("There is no father");
    }
    return _father;
}

Person::Sex Person::getSex() const {
    return _sex;
}

std::string Person::getSexToString() const {
    return _sex == Sex::MALE ? "Male" : "Female";
}

Person::Status Person::getStatus() const {
    return _status;
}

std::string Person::getStatusToString() const {
    return _status == Status::ALIVE ? "Alive" : "Dead";
}

unsigned int Person::getAge() const {
    return _age;
}
//endregion

//region Setters
void Person::setName(const std::string& name) {
    if (name.empty()) {
        throw std::exception("Name is empty!");
    }
    _name = name;
}

void Person::setAge(unsigned int age) {
    _age = age;
}
//endregion

//region State funcs
void Person::kill() {
    if(_status == Status::DEAD) {
        throw std::exception("What is dead may never die");
    }
    _status = Status::DEAD;
}

void Person::birthday() {
    if (_age == std::numeric_limits<unsigned int>::max()) {
        throw std::exception("This is too old. You must be a God!");
    }
    _age++;
}
//endregion

//region Help funcs
std::ostream& operator<<(std::ostream& out, const Person& other) {
    out << "ID: " << other.id << std::endl << "Name: " << other._name << std::endl
    << "Sex: " << other.getSexToString() << std::endl << "Status: " << other.getStatusToString() << std::endl
    << "Age: " << other._age << " years;" << std::endl;
    return out;
}
//endregion

