#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    try {
        Person Eva = Person::getEva();
        Person Adam = Person::getAdam();
        Person Kain = Eva.giveBirth("Kain", Person::Sex::MALE, &Adam);
        shared_ptr<Person> pt = Eva.haveSex(&Adam, false, "Avel");
        if (pt != nullptr) {
            cout << *pt;
        }
        cout << endl;
        Adam.haveSex(&Kain, false);
        Person AdamClone = Person(Adam);
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
    }
}