#include "PersonData.h"

PersonData::PersonData() {
    string newFirstName = " ";
    string newLastName = " ";
    int newAge = 0;
    int newBirthMonth = 0;
    int newBirthDay = 0;
    int newBirthYear = 0;

}

void PersonData::setNewFirstName(string firstName) {
    newFirstName = firstName;
}

void PersonData::setNewLastName(string lastName) {
    newLastName = lastName;
}

void PersonData::setNewAge(int age) {
    newAge = age;
}

void PersonData::setNewBirthMonth(int month) {
    newBirthMonth = month;
}

void PersonData::setNewBirthDay(int day) {
    newBirthDay = day;
}

void PersonData::setNewBirthYear(int year) {
    newBirthYear = year;
}

string PersonData::getNewFirstName() const{
    return newFirstName;
}

string PersonData::getNewLastName() const{
    return newLastName;
}
int PersonData::getNewAge() const{
    return newAge;
}
int PersonData::getNewBirthMonth() const{
    return newBirthMonth;
}
int PersonData::getNewBirthDay() const{
    return newBirthDay;
}
int PersonData::getNewBirthYear() const{
    return newBirthYear;
}

void PersonData::setAll(string firstName, string lastName, int age, int month, int day, int year) {
    newFirstName = firstName;
    newLastName = lastName;
    newAge = age;
    newBirthMonth = month;
    newBirthDay = day;
    newBirthYear = year;
}

void PersonData::printPersonInfo() {
    cout << "This person's first name: " << newFirstName << endl;
    cout << "last name: " << newLastName << endl;
    cout << "age: " << newAge << endl;
    cout << "birthdate: " << newBirthMonth << "-" << newBirthDay << "-" << newBirthYear << endl;
}

PersonData::~PersonData() {
}

