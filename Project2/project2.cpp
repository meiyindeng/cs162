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


void readTask (string fileName, int &count, taskType Task[]);
void displayTask(int &count, taskType Task[]);
void printTask(taskType Task[], int i);
void addTask(int &count, taskType Task[]);
void writeTask1(string outFileName, int &count, taskType Task[]);
bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);
bool checkDayInput(int day);
bool checkMonthInput(int month);
bool checkYearInput(int year);


int main(){
    taskType Task[200];
    taskType meetStartDate[200];
    int count = 0;
    int menuChoice;
    int entry = 0;


    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Add Task" << endl;
    cout << "4 - Quit" << endl;

    do{
        cout << "Enter choice:";

        bool correctInput=false;
            while(!correctInput){
                cin >> menuChoice;
                if (menuChoice>=1 && menuChoice<=4){
                    correctInput=true;
                }
                else cout << "Invalid Input";

                }
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
            int meetStartReq;
            correctInput=false;
            while (!correctInput){
            cout << "Input Begin Date: " << endl;
            cout << "Enter Month (1 to 12): " << endl;
            cin >> startMonth;
                if(checkMonthInput(startMonth)){
                correctInput=true;
                }
            }
            correctInput=false;
            while (!correctInput){
            cout << "Enter Day (1 to 31): " << endl;
            cin >> startDay;
                if(checkDayInput(startDay)){
                    correctInput=true;
                }
            }
            correctInput=false;
            while (!correctInput){
            cout << "Enter Year (2017 to 2067)" << endl;
            cin >> startYear;
                if(checkYearInput(startYear)){
                    correctInput=true;
                }
            }

            correctInput=false;
            while (!correctInput){
            cout << "Input End Date: " << endl;
            cout << "Enter Month (1 to 12): " << endl;
            cin >> endMonth;
                if(checkMonthInput(endMonth)){
                        correctInput=true;
                }
            }

            correctInput=false;
            while (!correctInput){
            cout << "Enter Day (1 to 31): " << endl;
            cin >> endDay;
                if(checkDayInput(endDay)){
                    correctInput=true;
                }
            }

            correctInput=false;
            while(!correctInput){
            cout << "Enter Year (2017 to 2067)" << endl;
            cin >> endYear;
                if(checkYearInput(endYear)){
                    correctInput=true;
                }
            }

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

bool checkDayInput(int day){
    if(day>=1 && day<=31){
        return true;
    }
}

bool checkMonthInput(int month){
    if(month>=1 && month<=12){
        return true;
    }
}

bool checkYearInput(int year){
    if(year>=2017 && year<=2067){
        return true;
    }
}






