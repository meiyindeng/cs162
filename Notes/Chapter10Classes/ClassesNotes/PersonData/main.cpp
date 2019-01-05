#include <iostream>
#include <string>
#include "PersonData.h"
using namespace std;

int main() {
    string firstName;
    string lastName;
    int age;
    int month;
    int day;
    int year;

    /*PersonData Student_1;
        Student_1.setNewFirstName("Megan Meiyin");
        Student_1.setNewLastName("Deng");
        Student_1.setNewAge(31);
        Student_1.setNewBirthMonth(7);
        Student_1.setNewBirthDay(21);
        Student_1.setNewBirthYear(1987);
        Student_1.printPersonInfo();*/


    PersonData Student_2;
        //cout << "First Name? ";
        //cin >> firstName;
        cout << "Last Name? ";
        cin >> lastName;
         /*cout << "Age? ";
        cin >> age;
        cout << "Month? ";
        cin >> month;
        cout << "Date? ";
        cin >> day;
        cout << "Year? ";
        cin >> year;
        Student_2.setAll(firstName, lastName, age, month, day, year);
        cout << "Student_2's first name is: " << Student_2.getNewFirstName() << endl;*/
         cout << lastName << endl;
        string* newLastName;
        newLastName = &lastName;
        //print out content of the memory space newLastName is pointing to;

         cout << *newLastName << endl;
        //reassigning value of the memory space of the pointer is pointing to.
        *newLastName = "Soso";

        //lastName has a different value now;
        cout << lastName;
















    return 0;
}