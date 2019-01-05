//
// Created by Meiyin Deng on 11/7/18.
//

#ifndef BUCKY46COMPOSITION_PEOPLE_H
#define BUCKY46COMPOSITION_PEOPLE_H

#include "Birthday.h"
#include <string>
using namespace std;



class People {

    public:
        People(string x, Birthday bo);
        void printInfo();

    private:
        string name;
        //since each person has a birthday, we will have a birthday object in People class
        //declare dateOfBirth object here
        Birthday dateOfBirth;


};


#endif //BUCKY46COMPOSITION_PEOPLE_H
