//
// Created by Meiyin Deng on 11/7/18.
//

#include "Hannah.h"
#include <iostream>
using namespace std;

Hannah::Hannah() {}

//assigning int to variable num
Hannah::Hannah(int a){
    num = a;
}


//Class Hannah has 2 object
//overloading operator add one object to
Hannah Hannah::operator+(Hannah also){ //another object
        //declare Hannah brandNew object
        Hannah brandNew;

        //give number value of the brandNew Hannah object
        brandNew.num = num + also.num;

        //return the value of the brandNew Hannah object
        return(brandNew);

}

void Hannah::printHannah() {
    //this function print out the value of set to h
    cout << "num = " << num << endl;

    //this (keyword) identify it's a pointer store the address of the current object you working with
    //int *this = &ho (address of Object ho)
    //tell compiler to get the value or (using the function) the pointer is pointing to
    cout << "this->num = " << this->num << endl;

    //dereference the pointer and use the access operator to access variable h of the object
    cout << "(*this).num = " << (*this).num << endl;
}