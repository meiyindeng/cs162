#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#ifndef PersonData_h
#define PersonData_h

class PersonData{
    public:
        PersonData();

        void setNewFirstName(string);
        void setNewLastName(string);
        void setNewAge(int);
        void setNewBirthMonth(int);
        void setNewBirthDay(int);
        void setNewBirthYear(int);
        void setAll(string, string, int, int, int, int);
        void printPersonInfo();

        string getNewFirstName() const;
        string getNewLastName() const;
        int getNewAge() const;
        int getNewBirthMonth() const;
        int getNewBirthDay() const;
        int getNewBirthYear() const;

        ~PersonData();



    private:
        string newFirstName;
        string newLastName;
        int newAge;
        int newBirthMonth;
        int newBirthDay;
        int newBirthYear;



};



#endif
