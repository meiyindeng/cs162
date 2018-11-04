#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>
#include "task.h"

#define MAX_STR 30
#define MAX_STR2 100


using namespace std;

void addTask(int &count, Task listOfTask[], char taskName[]);


void printRequest(string input);

void requestDate(string typeOfTime, int begin, int end);

int validateAndReturnUserInput(int lowNumber, int highNumber);

void displayTask(int count, Task listOfTask[]);

int main() {
    Task listOfTask[200];
    int count = 0;
    int menuChoice;
    int entry = 0;
    char taskName[30];
    char description[100];
    int month;
    int day;
    int year;
    bool complete;

    addTask(count, listOfTask, taskName);

    listOfTask[count].getTaskName(taskName);

    printf("T: %s",taskName);

    displayTask(count, listOfTask);





    //listOfTask[count].print();


    return 0;

}


//This function get task info from user and setting info for Object listOfTask
void addTask(int &count, Task listOfTask[], char taskName[]) {
    printRequest("Enter Name:");
    cin.clear();
    cin.getline(taskName, MAX_STR);
    listOfTask[count].setTaskName(taskName);

    /*printRequest("Enter Description (all on one line):")
    cin.getline(description, MAX_STR2);
    listOfTask[count].setDescription(description);

    printRequest("Entering Due Date:")
    requestDate("Month", 1, 12);
    month = validateAndReturnUserInput(1, 12);
    listOfTask[count].setMonth(month);

    requestDate("Day", 1, 31);
    day = validateAndReturnUserInput(1, 31);
    listOfTask[count].setDay(day);

    requestDate("Year", 2017, 2067);
    year = validateAndReturnUserInput(2017, 2067);
    listOfTask[count].setYear(year);

    complete = 0;
    listOfTask[count].setComplete(complete);*/
    count++;
}


void printRequest(string input) {
    cout << input << endl;
}

void displayTask(int count, Task listOfTask[]) {
    char *task;
    for (int i = 0; i < count; i++) {
        listOfTask[i].getTaskName(task);

        printf("taskname: %s",task);
        //cout << "Task Description: " << listOfTask[i].description << endl;
        //cout << "Month: " << Task[i].month << "/" << listOfTask[i].day << "/" << listOfTask[i].year <<
        //     endl;
        //if (listOfTask[i].complete == 1) {
        //    cout << "Task is: COMPLETE" << endl;
        //} else cout << "Task is: NOT COMPLETE" << endl;
    }

}
//this function request date input, can be month, day, year
//month should be range from 1 to 12
//day should be range from 1 to 31
//year should be range from 2017 to 2067
/*void requestDate(string typeOfTime, int begin, int end) {
    cout << "Enter " << typeOfTime << " (" << begin << " to " << end << "):" << endl;
}

int validateAndReturnUserInput(int lowNumber, int highNumber) {
    int input;
    bool valid = false;
    while (!valid) {
        cin >> input;
        if (input >= lowNumber && input <= highNumber) {
            valid = true;
        } else {
            cout << "Invalid Input" << endl;
        }
    }
    return input;
}*/



