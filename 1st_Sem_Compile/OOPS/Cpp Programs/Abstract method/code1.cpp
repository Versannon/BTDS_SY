/*
Assignment 1:
- Create an abstract class with name 'flower'.
- use run() function.
- Perform any operation related to flower.
*/
#include <iostream>
using namespace std;

class Flower {
public:
    virtual void run() = 0; // pure virtual function
};

class Rose : public Flower {
public:
    void run() {
        cout << "Rose is blooming." << endl;
    }
};

class Tulip : public Flower {
public:
    void run() {
        cout << "Tulip Flower pollinates." << endl;
    }
};

int main() {
    Rose fl1;
    Tulip fl2;

    Flower* f1 = &fl1;
    Flower* f2 = &fl2;

    f1->run();
    f2->run();

    return 0;
}