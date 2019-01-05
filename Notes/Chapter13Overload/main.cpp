#include <iostream>
using namespace std;
#include "rectangle.h"

//Encapsulation: The ability to combine data and operation on the data
//Overload: Instead of calling a function on the object, you directly use the operator on the object
//The operator function is a value-returning function
//Syntax

//returnType operator operatorSymbol (formal parameter)
// bool operator==(const ClockType& otherClockType) const -- reference to another object as parameter
// bool clockType::operator==(const clockType& otherClock) const

//This
    //Every object of a class maintain a pointer to itself (this).
    //return the value of entire object
    //rectangleType doubleDimensions(); -- the function prototype return the object

    /*rectangleType rectangleType::doubleDimensions()
     * this function return the double value of width and length.
        {
        length = 2 * length;
        width = 2 * width;
        return *this;
        }*/
    //In main function: newYad = oldYard.doubleDimension();
    // when this function call, the value of the entire oldYard object copy to newYard (length, width)

void area (Rectangle rec){
    int area;
    area = rec.width * rec.length;
    cout << area;

}
int main() {
   Rectangle rec1(10, 20);



    cout << "Area of Rec1: "; area(rec1);  cout << endl;




    Rectangle rec2=rec1;

    Rectangle rec3 = rec1 + rec2;



    cout << "Area of Rec2: "; area(rec2); cout << endl;

    cout << "Area of Rec3: "; area(rec3); cout << endl;

    return 0;
}