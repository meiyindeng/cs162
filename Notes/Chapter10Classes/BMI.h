//Header file: function declaration
#include <iostream>
#include <string>

using namespace std;
#ifdef BMI_h
#define BMI_h
class BMI{
	public:
	//Default constructor, set your member variable to null
	//Type out the name of the class
	BMI();
	
	//Overload constructor
	//Add parameter into the constructor
	//Don't need to give name, just the data type
	//Setting our member variable (the private variable) to what we pass in 
	//the function
	BMI(string, int, double);

	//Destructor: once done using the object, need to be destroy out of
	//memory
	~BMI();

	//Accessor Functions: return our (private member variable)
	//return name from class BMI newName
		string getName() const;
	//return height from class BMI newHeight
		int getHeight() const;
	//return weight from class BMI newWeight
		double getWeight() const;

	//retrieve the member variable of which we set using the overload
	// constructor
	
	//mutator function modify member variable one at a time
	//change the name
	//instead of passing the actual parameter using the overload constructor
	//by typing the name at main 
		void setName(string);
	//changing the height of the object	
		void setHeight(int);
	//changing the weight of the object
		void setWeight(double);
	
	//function calculate BMI
	double calculateBMI();
		
	private:
	//member variables
	string newName;
	int newHeight;
	double newWeight;

};
#endif
