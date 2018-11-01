#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct taskType {
    char taskName[30];
    char description[100];
    int month;
    int day;
    int year;
    bool complete;

};

void menuPrompt();

bool checkMenuChoice(int menuChoice);

int menuResult(int menuChoice);

void readTask(string fileName, int &count, taskType Task[]);

void displayTask(int &count, taskType Task[]);

void requestDate (string typeOfTime, int begin, int end);

int validateAndReturnUserInput(int lowNumber, int highNumber);

void addTask(int &count, taskType Task[]);

void requestDateRange(int& startMonth, int& startDay, int& startYear, int& endMonth, int& endYear, int& endDay);

bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                   int endYear);
void writeTask1(string outFileName, int &count, taskType Task[]);



int main() {
    taskType Task[200];
    taskType meetStartDate[200];
    int count = 0;
    int menuChoice;
    int entry = 0;


    readTask("tasks.txt", count, Task);
    do {
        menuPrompt();

        menuChoice = validateAndReturnUserInput(1, 4);

        if (menuChoice == 1) {
            displayTask(count, Task);
        }

        if (menuChoice == 3) {
            addTask(count, Task);
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
                if (isDateInRange(Task[i].day, Task[i].month, Task[i].year, startDay, startMonth, startYear, endDay,
                                  endMonth, endYear)) {

                    meetStartDate[entry] = Task[i];
                    entry++;
                }
            }

            displayTask(entry, meetStartDate);


        }

    } while (menuChoice != 4);

    writeTask1("tasks.txt", count, Task);

    return 0;

}

//prompt menu when program starts
void menuPrompt() {
    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Add Task" << endl;
    cout << "4 - Quit" << endl;
    cout << "Enter choice:";
}

//read task from file
void readTask(string fileName, int &count, taskType Task[]) {
    count = 0;
    ifstream taskInputFile(fileName);
    char c = taskInputFile.peek();

    if (!taskInputFile) {
        cout << "could not open file" << endl;
    }

    while (!taskInputFile.eof() && c != '\n') {
        taskInputFile.getline(Task[count].taskName, 30);
        taskInputFile.getline(Task[count].description, 100);
        taskInputFile >> Task[count].month;
        taskInputFile >> Task[count].day;
        taskInputFile >> Task[count].year;
        taskInputFile >> Task[count].complete;
        taskInputFile.ignore(2, '\n');
        count++;
        c = taskInputFile.peek();
    }
}


int validateAndReturnUserInput(int lowNumber, int highNumber) {
    int input;
    bool valid=false;
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




void displayTask(int &count, taskType Task[]) {
    for (int i = 0; i < count; i++) {
        cout << "Task Name: " << Task[i].taskName << endl;
        cout << "Task Description: " << Task[i].description << endl;
        cout << "Month: " << Task[i].month << "/" << Task[i].day << "/" << Task[i].year <<
             endl;
        if (Task[i].complete == 1) {
            cout << "Task is: COMPLETE" << endl;
        } else cout << "Task is: NOT COMPLETE" << endl;
    }

}


void addTask(int &count, taskType Task[]) {
    cout << "Enter Name:" << endl;
    cin.clear();
    cin.ignore();
    cin.get(Task[count].taskName, sizeof(Task[count].taskName));
    cin.ignore();
    cout << "Enter Description (all on one line):" << endl;
    cin.getline(Task[count].description, sizeof(Task[count].description));
    cout << "Entering Due Date:" << endl;
    requestDate("Month", 1, 12);
    Task[count].month = validateAndReturnUserInput(1, 12);
    requestDate("Day", 1, 31);
    Task[count].day = validateAndReturnUserInput(1, 31);
    requestDate("Year", 2017, 2067);
    Task[count].year = validateAndReturnUserInput(2017, 2067);
    Task[count].complete = 0;
    count++;
}

void writeTask1(string outFileName, int &count, taskType Task[]) {
    ofstream outFile;
    outFile.open(outFileName);
    for (int i = 0; i < count; i++) {
        outFile << Task[i].taskName << endl;
        outFile << Task[i].description << endl;
        outFile << Task[i].month << endl;
        outFile << Task[i].day << endl;
        outFile << Task[i].year << endl;
        outFile << Task[i].complete << endl;
    }
    outFile.close();
}




//this function request date input, can be month, day, year
//month should be range from 1 to 12
//day should be range from 1 to 31
//year should be range from 2017 to 2067
void requestDate (string typeOfTime, int begin, int end){
    cout << "Enter " << typeOfTime << " (" << begin << " to " << end << "):" << endl;
}

//this function request date range from user and set date for future implementation
void requestDateRange(int& startMonth, int& startDay, int& startYear, int& endMonth, int& endYear, int& endDay){
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













