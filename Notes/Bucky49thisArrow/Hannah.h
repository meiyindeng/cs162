//
// Created by Meiyin Deng on 11/7/18.
//
#include <iostream>
using namespace std;

#ifndef BUCKY49THIS_HANNAH_H
#define BUCKY49THIS_HANNAH_H


class Hannah {
    public:
        //constructor1
        Hannah();

        //constructor2
        Hannah(int);

        int num;

        void printHannah();

        //operator overloading using the addition operator
        Hannah operator+ (Hannah);
private:

        //private variable name h
        int h;

};


#endif //BUCKY49THIS_HANNAH_H
