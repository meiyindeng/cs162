//
// Created by Meiyin Deng on 11/7/18.
//
#include <iostream>
using namespace std;
#include "Birthday.h"

Birthday::Birthday(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Birthday::printBirthday() {
    cout << month << '-' << day << '-' << year << endl;
}
