#include <iostream>
using namespace std;
#include "Birthday.h"
#include "People.h"


int main() {
    //create birthObject of Birthday class;
    Birthday birthObject(7, 21, 1987);
    //create MeganObject of People class, also passing birthObject from Birthday class
    // as parameter
    People MeganObject("Megan", birthObject);
    MeganObject.printInfo();
    cout << endl;

    //every class can have friend
    // a friend of a class is totally separate from the class but can access the class

    //calling function with the actual birthObject
    cout << julianDate(birthObject);
    return 0;
}

//create function passing reference& of the Object
int julianDate (Birthday &mDay){
    int julianDate = (mDay.month*30) + (mDay.day);
    return julianDate;
}

