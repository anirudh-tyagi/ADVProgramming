#include <iostream>
using namespace std;

class ClassA {
private:
    int data;

public:
    ClassA(int d) : data(d) {}
    friend void accessPrivateData(ClassA &, ClassB &);
};


class ClassB {
private:
    double data;

public:
    ClassB(double d) : data(d) {}
    friend void accessPrivateData(ClassA &, ClassB &);
};

void accessPrivateData(ClassA &a, ClassB &b) {
    cout << "Class A's private data: " << a.data << endl;
    cout << "Class B's private data: " << b.data << endl;
}

int main() {
    ClassA obj1(10);
    ClassB obj2(20.5); accessPrivateData(obj1, obj2); return 0; }