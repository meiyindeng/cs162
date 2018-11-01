#include <iostream>
#include <string>
#include "BMI.h"
using namespace std;

int main(){

	string name;
	int height;
	double weight;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your height: ";
	cin >> height;
	cout << "Enter your weight: ";
	cin >> weight;

//creating the object
//type out the name of the class follow by name of 1st object
//using the overload constructor to pass in the 3 variables
	BMI Student_1(name, height, weight);

	cout << endl << "Student Name: " << Student_1.getName() << endl <<
	"Height: " << Studen_1.getHeight() << endl <<
	"Weight: " << Student_1.getWeight() << endl;

//Sample using the "set" function
//create another object by type in the class follow by name of the 2nd object
// Student_2
	BMI Student_2;
//to access the function only need to type the name of the object follow by function
	Student_2.setName(name);
	Student_2.setHeight(height);
	Student_2.setWeight(weight);
   cout << endl << "Student Name: " << Student_2.getName() << endl <<
        "Height: " << Studen_2.getHeight() << endl <<
        "Weight: " << Student_2.getWeight() << endl;

	"BMI: " << Student_2.calculateBMI() << endl;
return 0;
}
 
