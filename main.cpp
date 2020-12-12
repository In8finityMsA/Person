#include <iostream>
#include "Person.h"
#pragma warning(disable: 4996)

using namespace std;

int main() {
    Person p("Serge Kashkevich");
    Person p1(p);
    Person p2("Person");

    cout << p2.getName() << endl;
    p2 = p1;
    p1 = Person("Oreshko");
    cout << p2.getName() << endl;
    cout << p1.getName() << endl;
}