#include <iostream>
#include "Person.h"
#pragma warning(disable: 4996)

using namespace std;

int main() {
    try {
        Person Eva = Person::getEva();
        Person Adam = Person::getAdam();

        Person Kain = Eva.giveBirth("Kain", Person::Sex::MALE, &Adam);

        //cout << Kain << endl;
        //delete Kain.getMother();
        //cout << *Kain.getMother() << endl;
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
    }
}