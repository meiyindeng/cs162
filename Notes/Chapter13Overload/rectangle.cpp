//
// Created by Meiyin Deng on 11/10/18.
//

#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(){
}

Rectangle::Rectangle(int l, int w) {
    length = l;
    width = w;
}

// specify return reference Rectangle object, use Rectangle class::operator#(const className& objectName) const
//using pointer this to copy the value itself.

//this stores the address of the current object
Rectangle& Rectangle::operator=(Rectangle& rec){
    if (this != &rec){
        length = rec.length;
        width = rec.width;
    }

    return *this;
}

Rectangle Rectangle::operator+(const Rectangle& rec){
    Rectangle rectangle;
    rectangle.length = length+rec.length;
    rectangle.width = width+rec.width;
    return rectangle;
}


void Rectangle ::setLength(int l) {
    length = l;
}

void Rectangle ::setWidth(int w) {
    width = w;
}




