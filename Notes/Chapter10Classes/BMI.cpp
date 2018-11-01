#include <iostream>
#include <string>
#include "BMI.h"

//function definition
//How to access function inside of that class?
//Need to type out the name of the class first follow by double ::

BMI::BMI(){
	//define what is null constructor listed at the header file 
	string newName;
        int newHeight=0;
        double newWeight=0.0;
}

BMI::BMI(string name, int height, double weight){
	//define the overload constructor
	newName = name;
	newHeight = height;
	newWeight = weight;
}

//define destructor
BMI::~BMI(){
}

//define getName for class BMI
string BMI::getName() const{
	return newName;
}

//define getHeight for class BMI
int BMI::getHeight() const{
	return newHeight;
}
//define getWeight for class BMI
double BMI::getWeight() const{
	return newWeight;
}

//defind setName for class BMI
void BMI::setName(string name){
	newName = name;
}

void BMI::setHeight(int height){
	newHeight = height;
}

void BMI::setWeight(double weight){
	newWeight = weight;
}

double BMI::calculateBMI(){
	return (newWeight * 703) / (newHeight*newHeight);
}

