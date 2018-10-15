#include <iostream>
#include <ctime>

using namespace std;
struct tm{
	//struct contains these components
	int mon;
	int day;
	int year;
};

//delcare variable of a struct
tm dueDate;


int main()
{
	//adding components to the variable;
	dueDate.mon = 10;
	dueDate.day = 15;
	dueDate.year = 2018;

	cout << "due date: "<< dueDate.mon<<"/"<<dueDate.day<<"/"<<dueDate.year << endl;

        return 0;
}

