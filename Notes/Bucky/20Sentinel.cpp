#include <iostream>
using namespace std;

int main()
{
	//special code -1
	//enter the age of all people
	//calculate the average age
	int age;
	//initialize ageTotal starts with 0
	int ageTotal = 0;
	//initialize count starts with 0
	int count = 0;
	cout << "Enter first persons age or  -1 to quit" << endl;
	cin >> age;
	//use -1 for sentinel control proram
	while(age != -1){

	ageTotal = ageTotal + age;
	count ++;
	cout << "Enter next persons age or -1 to quit" << endl;
	cin >> age;
	}
	cout << "Number of people entered : " << count << endl;
	cout << "Average age: " << ageTotal/count << endl;

        return 0;
}


