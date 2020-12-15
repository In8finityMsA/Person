//
// Created by Admin on 04.11.2020.
//

#ifndef PERSON_LECTURE_PERSON_H
#define PERSON_LECTURE_PERSON_H


#include <string>
#include <iostream>

class Person {
public:
    enum class Sex {MALE, FEMALE};
    enum class Status {ALIVE, DEAD};

    Person(const Person& other);
    Person& operator=(const Person& other) = delete;
    virtual ~Person() = default;

    const int getID() const;
    std::string getName() const;
    void setName(const std::string &name);
    Sex getSex() const;
    std::string getSexToString() const;
    Status getStatus() const;
    std::string getStatusToString() const;
    void kill();
    unsigned int getAge() const;
    void setAge(unsigned int age);
    void birthday();
    const Person* getFather() const;
    const Person* getMother() const;

    [[nodiscard]] static Person getAdam();
    [[nodiscard]] static Person getEva();

    [[nodiscard]] std::shared_ptr<Person> haveSex(Person* partner, bool condom, const std::string& name = "Unnamed");
    [[nodiscard]] Person giveBirth(const std::string& name, const Sex& sex, Person* father = nullptr);

    friend std::ostream& operator << (std::ostream& out, const Person&);

private:
    static int nextID;
    const int id;
    std::string _name;
    Sex _sex;
    Status _status;
    unsigned int _age = 0;
    Person* _mother = nullptr;
    Person* _father = nullptr;
    Person(const std::string& name, Sex sex, Status status, unsigned int age, Person* mother, Person* father = nullptr);
    Person(int id, const std::string& name, Sex sex, Status status, unsigned int age);
};


#endif //PERSON_LECTURE_PERSON_H
