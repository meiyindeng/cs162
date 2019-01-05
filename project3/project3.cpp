#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>
#include "task.h"
#include "Tasklist.h"

#define MAX_STR 30
#define MAX_STR2 100


using namespace std;

void menuPrompt();

void requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay);

bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                   int endYear);

void writeTask(const char *outFileName, int count, Task *listOfTask);

void readTask(const char *fileName, int &count, Task *listOfTask, char *taskName, char *description, int month, int day,
              int year, bool complete);




void printRequest(const char *input);

void requestDate(const char *typeOfTime, int begin, int end);

int validateAndReturnUserInput(int lowNumber, int highNumber);

void displayTask(int count, Task listOfTask[]);

bool isSame(char a[], const char b[]);

void completeTask(Task *listOfTask, int count);

void handleMenu2 (int count, Task * listOfTask);

int main() {
    Tasklist manager;
    int count = 0;
    int menuChoice;

    char taskName[30];
    char description[100];
    int month = 1;
    int day = 1;
    int year = 2017;
    bool complete = false;
    readTask("tasks.txt", count, listOfTask, taskName, description, month, day, year, complete);



//keep
    //do {
        menuPrompt();

        menuChoice = validateAndReturnUserInput(1, 5);

        /*if (menuChoice == 1) {
            displayTask(count, listOfTask);
        }

        if (menuChoice == 4) {
            addTask(count, listOfTask, taskName, description, month, day, year, complete);
        }

        if (menuChoice == 2) {
            handleMenu2(count, listOfTask);
        }

        if (menuChoice == 3) {
            completeTask(listOfTask, count);
        }

    } while (menuChoice != 5);

    writeTask("tasks.txt", count, listOfTask);*/

    return 0;







}

void readTask(const char *fileName, int &count, Task *listOfTask, char *taskName, char *description, int month, int day,
              int year, bool complete) {
    count = 0;
    ifstream taskInputFile(fileName);
    char c = taskInputFile.peek();


    if(taskInputFile.fail()){
        return;
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

    taskInputFile.close();


}


//This function get task info from user and setting info for Object listOfTask
void addTask(int &count, Task listOfTask[], char taskName[], char description[], int month, int day, int year,
             bool complete) {
    printRequest("Enter Name:");
    cin.ignore();
    cin.getline(taskName, MAX_STR);
    Task &task = listOfTask[count];
    task.setTaskName(taskName);

    printRequest("Enter Description (all on one line):");
    cin.getline(description, MAX_STR2);
    task.setDescription(description);

    printRequest("Entering Due Date:");
    requestDate("Month", 1, 12);
    month = validateAndReturnUserInput(1, 12);
    task.setMonth(month);

    requestDate("Day", 1, 31);
    day = validateAndReturnUserInput(1, 31);
    task.setDay(day);

    requestDate("Year", 2017, 2067);
    year = validateAndReturnUserInput(2017, 2067);
    task.setYear(year);

    complete = 0;
    task.setComplete(complete);
    count++;
}


void printRequest(const char *input) {
    cout << input << endl;
}

void displayTask(int count, Task listOfTask[]) {
    for (int i = 0; i < count; i++) {
        Task &currentTask = listOfTask[i];

        printf("Task Name: %s", currentTask.getTaskName());
        cout << endl;
        printf("Task Description: %s", currentTask.getDescription());
        cout << endl;
        cout << "Month: " << currentTask.getMonth() << "/" << currentTask.getDay() << "/" << currentTask.getYear()
             << endl;
        if (currentTask.getComplete() == 1) {
            cout << "Task is: COMPLETE" << endl;
        } else cout << "Task is: NOT COMPLETE" << endl;
    }

}

//this function request date input, can be month, day, year
//month should be range from 1 to 12
//day should be range from 1 to 31
//year should be range from 2017 to 2067
void requestDate(const char *typeOfTime, int begin, int end) {
    cout << "Enter " << typeOfTime << " (" << begin << " to " << end << "):" << endl;
}

//keep
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

//keep
void menuPrompt() {
    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Complete a task" << endl;
    cout << "4 - Add Task" << endl;
    cout << "5 - Quit" << endl;
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

void writeTask(const char *outFileName, int count, Task *listOfTask) {
    ofstream outFile;
    outFile.open(outFileName);

    for (int i = 0; i < count; i++) {
        Task &task = listOfTask[i];

        outFile << task.getTaskName() << endl;
        outFile << task.getDescription() << endl;
        outFile << task.getMonth() << endl;
        outFile << task.getDay() << endl;
        outFile << task.getYear() << endl;
        outFile << task.getComplete() << endl;
    }
    outFile.close();
}


void completeTask(Task *listOfTask, int count) {
    char taskName[MAX_STR];
    printRequest("Enter name of task to complete");
    cin.ignore();
    cin.getline(taskName, MAX_STR);
    for (int i = 0; i < count; i++) {
        Task &task = listOfTask[i];
        if (isSame(taskName, task.getTaskName())) {
            task.setComplete(true);
            cout << "the task " << taskName << " has been completed" << endl;
            return;
        }

    }
    cout << "task " << taskName << " was not found in the list" << endl;

}


bool isSame(char a[], const char b[]) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

//ask name of the task
//if the name of the task does match, display not found in list
//change complete status


void handleMenu2 (int count, Task * listOfTask){
    int startMonth;
    int startDay;
    int startYear;
    int endMonth;
    int endYear;
    int endDay;
    Task meetStartDate[200];
    int entry = 0;

    requestDateRange(startMonth, startDay, startYear, endMonth, endYear, endDay);

    for (int i = 0; i < count; i++) {
        Task &task = listOfTask[i];
        if (isDateInRange(task.getDay(),
                          task.getMonth(),
                          task.getYear(),
                          startDay,
                          startMonth,
                          startYear,
                          endDay,
                          endMonth,
                          endYear
        )) {

            meetStartDate[entry] = listOfTask[i];
            entry++;
        }
    }

    displayTask(entry, meetStartDate);

}








