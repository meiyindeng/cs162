#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct taskType{
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
void readTask (string fileName, int &count, taskType Task[]);
void displayTask(int &count, taskType Task[]);
void addTask(int &count, taskType Task[]);
void writeTask1(string outFileName, int &count, taskType Task[]);
int returnUserInput(bool valid, int lowNumber, int highNumber, int &input);
bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);




int main(){
    taskType Task[200];
    taskType meetStartDate[200];
    int count = 0;
    int menuChoice;
    int entry = 0;

    menuPrompt();


    do{
        cout << "Enter choice:";

        returnUserInput(false, 1, 4, menuChoice);

        readTask("tasks.txt", count, Task);
        if(menuChoice==1){
            displayTask(count, Task);
        }

        if(menuChoice==3){

            addTask(count, Task);

            writeTask1("tasks.txt", count, Task);
        }

        if (menuChoice==2){

            int startMonth;
            int startDay;
            int startYear;
            int endMonth;
            int endDay;
            int endYear;

            cout << "Input Begin Date: " << endl;
            cout << "Enter Month (1 to 12): " << endl;
            startDay=returnUserInput(false, 1, 12, startDay);

            cout << "Enter Day (1 to 31): " << endl;
            startMonth=returnUserInput(false, 1, 31, startMonth);

            cout << "Enter Year (2017 to 2067)" << endl;
            startYear=returnUserInput(false, 2017, 2067, startYear);

            cout << "Input End Date: " << endl;
            cout << "Enter Month (1 to 12): " << endl;
            endDay=returnUserInput(false, 1, 12, endDay);

            cout << "Enter Day (1 to 31): " << endl;
            endMonth=returnUserInput(false, 1, 31, endMonth);

            cout << "Enter Year (2017 to 2067)" << endl;
            endYear=returnUserInput(false, 2017, 2067, endYear);

            for(int i=0; i<count; i++){
                if(isDateInRange(Task[i].day, Task[i].month, Task[i].year, startDay, startMonth, startYear, endDay, endMonth, endYear)==true){
                    meetStartDate[entry]=Task[i];
                    entry++;
                }
            }

            displayTask(entry, meetStartDate);


        }

    }
    while (menuChoice !=4);

    return 0;

}

int returnUserInput(bool valid, int lowNumber, int highNumber, int &input){
    while(!valid){

    cin >> input;
        if(input >= lowNumber && input <= highNumber){
            valid = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }
    return input;
}


void readTask (string fileName, int &count, taskType Task[]){
    count=0;
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
        count ++;
        c = taskInputFile.peek();
    }
}

void displayTask(int &count, taskType Task[]){
    for (int i = 0; i < count; i++) {
        cout << "Task Name: " << Task[i].taskName << endl;
        cout << "Task Description: " << Task[i].description << endl;
        cout << "Month: " <<Task[i].month << "/" << Task[i].day<< "/" << Task[i].year <<
        endl;
        if(Task[i].complete==1) {
            cout << "Task is: COMPLETE"<< endl;
        }
        else cout << "Task is: NOT COMPLETE" << endl;
    }

}




void addTask(int &count, taskType Task[]){
        cout << "Enter Name:" << endl;
            cin.clear();
            cin.ignore();
            cin.get(Task[count].taskName, sizeof(Task[count].taskName));
            cin.ignore();
        cout << "Enter Description (all on one line):" << endl;
            cin.getline(Task[count].description, sizeof(Task[count].description));

        cout << "Entering Due Date:" << endl;
        cout << "Enter Month (1 to 12):" << endl;
            cin >> Task[count].month;
        cout << "Enter Day (1 to 31):" << endl;
            cin >> Task[count].day;
        cout << "Enter Year (2017 to 2067):" << endl;
            cin >> Task[count].year;
            Task[count].complete=0;
            count++;
}

void writeTask1(string outFileName, int &count, taskType Task[]){
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

bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear){

    int entryDate = (year * 10000) + (month * 100) + day;
    int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
    int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

    return entryDate >= startDate && entryDate <= endDate;
}

void menuPrompt(){
    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Add Task" << endl;
    cout << "4 - Quit" << endl;
}










