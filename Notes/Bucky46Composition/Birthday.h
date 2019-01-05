//
// Created by Meiyin Deng on 11/7/18.
//

#ifndef BUCKY46COMPOSITION_BIRTHDAY_H
#define BUCKY46COMPOSITION_BIRTHDAY_H


class Birthday {
    public:
        //constructor:
        Birthday(int m, int d, int y);
        void printBirthday();
    private:
        //private variable:
        int month;
        int day;
        int year;
        //need to class permission to use its data/variable
    //creating a friend function prototype inside of the class,
    // so function outside can use the variable
    friend int  julianDate (Birthday &mDay);



};


#endif //BUCKY46COMPOSITION_BIRTHDAY_H
