#include <iostream>
#include "Hannah.h"
using namespace std;

int main() {

    //Hannah has 2 objects, store 23 to ho and 24 to b
    Hannah ho(23);
    Hannah b(24);

    //c using the blank constructor without parameter
    Hannah c;
    //only need to add ho to b, no need to access function,
    //already define at Hannah.cpp

    c = ho + b;

    cout << c.num << endl;

    ho.printHannah();


    return 0;
}