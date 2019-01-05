#include <iostream>
#include <cstring>
#include "Task.h"
#include "TaskList.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;



TaskList::TaskList(){
    Task array;
    count = 0;
}


void TaskList::writeTask(const char * outFileName) {
    ofstream outFile;
    outFile.open(outFileName);
    for (int i = 0; i < count; i++){
        outFile << array [i];
    }

    outFile.close();


}

void TaskList::readTask(const char *fileName) {
    ifstream taskInputFile(fileName);
    char c = taskInputFile.peek();

    if (taskInputFile.fail()) {
        return;
    }


    while (!taskInputFile.eof() && c!= '\n') {

        taskInputFile >> array[count];

        count++;
        taskInputFile.peek();

    }

        taskInputFile.close();



}



void TaskList::addTask() {
    char taskName [MAX_STR];
    char description [MAX_STR2];
    int month;
    int day;
    int year;
    bool complete;


    printRequest("Enter Name:");
    cin.ignore();
    cin.getline(taskName, MAX_STR);
    array[count].setTaskName(taskName);

    printRequest("Enter Description (all on one line):");
    cin.getline(description, MAX_STR2);
    array[count].setDescription(description);

    printRequest("Entering Due Date:");
    requestDate("Month", 1, 12);
    month = validateAndReturnUserInput(1, 12);
    array[count].setMonth(month);

    requestDate("Day", 1, 31);
    day = validateAndReturnUserInput(1, 31);
    array[count].setDay(day);

    requestDate("Year", 2017, 2067);
    year = validateAndReturnUserInput(2017, 2067);
    array[count].setYear(year);

    complete = 0;
    array[count].setComplete(complete);

    count++;

}

void TaskList::displayTask(){

    for (int i = 0; i < count; i++) {
        printf("Task Name: %s", array[i].getTaskName());
        cout << endl;
        printf("Task Description: %s", array[i].getDescription());
        cout << endl;
        cout << "Month: " << array[i].getMonth() << "/" << array[i].getDay() << "/" << array[i].getYear()
             << endl;
        if (array[i].getComplete() == 1) {
            cout << "Task is: COMPLETE" << endl;
        } else cout << "Task is: NOT COMPLETE" << endl;
    }

}

void TaskList::displayRange(int entry, Task *meetStartDate) {

    for (int i = 0; i < entry; i++) {
        printf("Task Name: %s", meetStartDate[i].getTaskName());
        cout << endl;
        printf("Task Description: %s", meetStartDate[i].getDescription());
        cout << endl;
        cout << "Month: " << meetStartDate[i].getMonth() << "/" << meetStartDate[i].getDay() << "/"
        << meetStartDate[i].getYear()
        << endl;
        if (meetStartDate[i].getComplete() == 1) {
            cout << "Task is: COMPLETE" << endl;
        } else cout << "Task is: NOT COMPLETE" << endl;
    }

}



void TaskList::printRequest(const char *input) {
    cout << input << endl;
}

void TaskList::requestDate(const char *typeOfTime, int begin, int end) {
    cout << "Enter " << typeOfTime << " (" << begin << " to " << end << "):" << endl;
}

int TaskList::validateAndReturnUserInput(int lowNumber, int highNumber) {
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

void TaskList::requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay){
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

bool TaskList::isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay,
        int endMonth, int endYear){

    int entryDate = (year * 10000) + (month * 100) + day;
    int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
    int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

    return entryDate >= startDate && entryDate <= endDate;
}

void TaskList::handleMenu2 (){
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
        if (isDateInRange(array[i].getDay(),
                          array[i].getMonth(),
                          array[i].getYear(),
                          startDay,
                          startMonth,
                          startYear,
                          endDay,
                          endMonth,
                          endYear
        )) {

            meetStartDate[entry] = array[i];
            entry++;

        }
    }

    displayRange(entry, meetStartDate);


}



void TaskList::completeTask() {
    char taskNameInput[MAX_STR];
    printRequest("Enter name of task to complete");
    cin.ignore();
    cin.getline(taskNameInput, MAX_STR);
    for (int i = 0; i < count; i++) {
        if (isSame(taskNameInput, array[i].getTaskName())) {
            array[i].setComplete(true);
            cout << "the task " << array[i].getTaskName() << " has been completed" << endl;
            return;
        }

    }
    cout << "task " << taskNameInput << " was not found in the list" << endl;

}

void TaskList::uncompleteTask(){
    for (int i = 0; i < count; i++){
        if (array[i].getComplete()==0) {
            printf("Task Name: %s", array[i].getTaskName());
            cout << endl;
            printf("Task Description: %s", array[i].getDescription());
            cout << endl;
            cout << "Month: " << array[i].getMonth() << "/" << array[i].getDay() << "/" << array[i].getYear()
                 << endl;
            if (array[i].getComplete() == 1) {
                cout << "Task is: COMPLETE" << endl;
            } else cout << "Task is: NOT COMPLETE" << endl;
        }
    }
}



bool TaskList::isSame(char a [], const char b []) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (strncmp(a, b, MAX_STR)==0 ){
            return true;
        }
    }
    return false;
}

TaskList::~TaskList() {

}












