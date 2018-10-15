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
    int date;
    int year;
    bool complete;

};


void readTask (string fileName, int &count, taskType Task[]);
void writeTask1(int &count, taskType Task[]);
void printTask(taskType Task[], int i);

int main(){
    taskType Task[200];
    int count = 0;
    int menuChoice=1;

    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3 - Add Task" << endl;
    cout << "4 - Quit" << endl;


    cout << "Enter choice:";
    //do{
    bool correctInput=false;
        while(!correctInput){
            cin >> menuChoice;
            if (menuChoice>=1 && menuChoice<=4){
                correctInput=true;
            }
            //else cout << "Invalid Input";

            }

    readTask("tasks.txt", count, Task);

    if(menuChoice==1){
            writeTask1(count, Task);
    }




    if(menuChoice==3){
        //cout << "Start Count is: " << count;
        cout << "Enter Name:" << endl;

            cin.get(Task[count].taskName, sizeof(Task[count].taskName));

        //cout << "Enter description (all on one line):" << endl;
            //cin.getline(Task[3].description, 101);

        /*cout << "Entering Due Date:" << endl;
        cout << "Enter Month (1 to 12):" << endl;
            cin >> Task[count].month;
        cout << "Enter Day (1 to 31):" << endl;
            cin >> Task[count].date;
        cout << "Enter Year (2017 to 2067):" << endl;
            cin >> Task[count].year;
            Task[count].complete=0;
            count++;
        writeTask1(count, Task);*/





    }



    //}
    //while (menuChoice !=4);







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
        taskInputFile >> Task[count].date;
        taskInputFile >> Task[count].year;
        taskInputFile >> Task[count].complete;
        taskInputFile.ignore(2, '\n');
        count ++;
        c = taskInputFile.peek();



    }


}

void writeTask1(int &count, taskType Task[]){
    //ofstream outFile;
    //outFile.open(outFileName);
    for (int i = 0; i < count; i++) {


        cout << "Task Name: " << Task[i].taskName << endl;
        cout << "Task Description: " << Task[i].description << endl;
        cout << "Month: " <<Task[i].month << "/" << Task[i].date << "/" << Task[i].year <<
        endl;
        if(Task[i].complete==1) {
            cout << "Task is: COMPLETE"<< endl;
        }
        else cout << "Task is: NOT COMPLETE" << endl;


    }
    //outFile.close();
}

void printTask(taskType Task[], int i){
        cout << Task[i].taskName << endl;
        cout << Task[i].description << endl;
        cout << Task[i].month << endl;
        cout << Task[i].date << endl;
        cout << Task[i].year << endl;



}












