#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>
#include "task.h"

#define MAX_STR 30
#define MAX_STR2 100


using namespace std;

void menuPrompt();

bool checkMenuChoice(int menuChoice);

int menuResult(int menuChoice);

void requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay);

bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                   int endYear);

void writeTask(string outFileName, int count, Task *listOfTask);

void readTask(string fileName, int &count, Task listOfTask[], char taskName[], char description[], int month, int day,
              int year, bool complete);

void addTask(int &count, Task listOfTask[], char taskName[], char description[], int month, int day, int year,
             bool complete);


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
    readTask("tasks.txt", count, listOfTask, taskName, description, month, day, year, complete);

    Task meetStartDate[200];


    do {
        menuPrompt();

        menuChoice = validateAndReturnUserInput(1, 5);

        if (menuChoice == 1) {
            displayTask(count, listOfTask);
        }

        if (menuChoice == 4) {
            addTask(count, listOfTask, taskName, description, month, day, year, complete);
        }

        if (menuChoice == 2) {
            int startMonth;
            int startDay;
            int startYear;
            int endMonth;
            int endYear;
            int endDay;

            requestDateRange(startMonth, startDay, startYear, endMonth, endYear, endDay);

            for (int i = 0; i < count; i++) {
                if (isDateInRange(listOfTask[i].getDay(), listOfTask[i].getMonth(), listOfTask[i].getYear(), startDay, startMonth, startYear, endDay,
                                  endMonth, endYear)) {

                    meetStartDate[entry] = listOfTask[i];
                    entry++;
                }
            }

            displayTask(entry, meetStartDate);


        }

    } while (menuChoice != 5);

    writeTask("tasks1.txt", count, listOfTask);

    return 0;




    //listOfTask[count].print();



}

void readTask(string fileName, int &count, Task listOfTask[], char taskName[], char description[], int month, int day,
              int year, bool complete) {
    count = 0;
    ifstream taskInputFile(fileName);
    char c = taskInputFile.peek();

    if (!taskInputFile) {
        cout << "could not open file" << endl;
    }

    while (!taskInputFile.eof() && c != '\n') {
        taskInputFile.getline(taskName, MAX_STR);
        listOfTask[count].setTaskName(taskName);

        taskInputFile.getline(description, MAX_STR2);
        listOfTask[count].setDescription(description);

        taskInputFile >> month;
        listOfTask[count].setMonth(month);

        taskInputFile >> day;
        listOfTask[count].setDay(day);

        taskInputFile >> year;
        listOfTask[count].setYear(year);

        taskInputFile >> complete;
        listOfTask[count].setComplete(complete);
        taskInputFile.ignore(2, '\n');
        count++;
        c = taskInputFile.peek();
    }
}


//This function get task info from user and setting info for Object listOfTask
void addTask(int &count, Task listOfTask[], char taskName[], char description[], int month, int day, int year,
             bool complete) {
    printRequest("Enter Name:");
    cin.clear();
    cin.getline(taskName, MAX_STR);
    listOfTask[count].setTaskName(taskName);

    printRequest("Enter Description (all on one line):");
    cin.getline(description, MAX_STR2);
    listOfTask[count].setDescription(description);

    printRequest("Entering Due Date:");
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
    listOfTask[count].setComplete(complete);
    count++;
}


void printRequest(string input) {
    cout << input << endl;
}

void displayTask(int count, Task listOfTask[]) {
    char task[MAX_STR];
    char des[MAX_STR2];
    for (int i = 0; i < count; i++) {
        listOfTask[i].getTaskName(task);
        printf("Task Name: %s", task);
        cout << endl;
        listOfTask[i].getDescription(des);
        printf("Task Description: %s", des);
        cout << endl;
        cout << "Month: " << listOfTask[i].getMonth() << "/" << listOfTask[i].getDay() << "/" << listOfTask[i].getYear()
             << endl;
        if (listOfTask[i].getComplete() == 1) {
            cout << "Task is: COMPLETE" << endl;
        } else cout << "Task is: NOT COMPLETE" << endl;
    }

}

//this function request date input, can be month, day, year
//month should be range from 1 to 12
//day should be range from 1 to 31
//year should be range from 2017 to 2067
void requestDate(string typeOfTime, int begin, int end) {
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
}

void menuPrompt() {
    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Add Task" << endl;
    cout << "4 - Quit" << endl;
    cout << "Enter choice:";
}

//this function request date range from user and set date for future implementation
void requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay) {
    cout << "Input Begin Date: " << endl;
    requestDate("Month", 1, 12);
    startMonth = validateAndReturnUserInput(1, 12);

    requestDate("Day", 1, 31);
    startDay = validateAndReturnUserInput(1, 31);

    requestDate("Year", 2017, 2067);
    startYear = validateAndReturnUserInput(2017, 2067);

    cout << "Input End Date: " << endl;
    requestDate("Month", 1, 12);
    endMonth = validateAndReturnUserInput(1, 12);

    requestDate("Day", 1, 31);
    endDay = validateAndReturnUserInput(1, 31);

    requestDate("Year", 2017, 2067);
    endYear = validateAndReturnUserInput(2017, 2067);
}

bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                   int endYear) {

    int entryDate = (year * 10000) + (month * 100) + day;
    int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
    int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

    return entryDate >= startDate && entryDate <= endDate;
}

void writeTask(string outFileName, int count, Task *listOfTask) {
    ofstream outFile;
    outFile.open(outFileName);

    char taskName[30];
    char description[100];

    for (int i = 0; i < count; i++){
        listOfTask[i].getTaskName(taskName);
        outFile << taskName << endl;
        listOfTask[i].getDescription(description);
        outFile <<  description << endl;
        outFile << listOfTask[i].getMonth() << endl;
        outFile << listOfTask[i].getDay() << endl;
        outFile << listOfTask[i].getYear() << endl;
        outFile << listOfTask[i].getComplete() << endl;
    }
    outFile.close();
}







