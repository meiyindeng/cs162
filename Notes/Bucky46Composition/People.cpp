//
// Created by Meiyin Deng on 11/7/18.
//
#include <iostream>
using namespace std;
#include "Birthday.h"
#include "People.h"

//need to use a member initializer list when working with a class inside another class
People::People(string x, Birthday bo)
//constructor passing the value and set the private variable
: name(x), dateOfBirth(bo) //start with colon, name of private variable (pass in value) inside the parentheses
{
}
//make sure don't put the initializer inside of the curly brace, put it on top

void People::printInfo() {
    cout << name << " was born on ";
    //using the printBirthday function from the birthday class
    dateOfBirth.printBirthday();
}