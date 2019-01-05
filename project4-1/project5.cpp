#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>

#include "TaskList.h"

#define MAX_STR 30
#define MAX_STR2 100


using namespace std;

void menuPrompt();

int validateAndReturnUserInput(int lowNumber, int highNumber);


int main() {


    TaskList manager;


    int menuChoice;

    manager.readTask("tasks.txt");

    do {
        menuPrompt();


        menuChoice = validateAndReturnUserInput(1, 7);
        if (menuChoice == 1) {
            manager.displayTask();

        }

         if (menuChoice == 2) {
            manager.handleMenu2();
        }

        if (menuChoice == 5) {
            manager.addTask();
        }

        if (menuChoice == 4) {
            manager.completeTask();
        }

        if (menuChoice == 3) {
           manager.printInComplete();
        }

        if (menuChoice == 6) {
            manager.deleteTask();
        }

    } while (menuChoice != 7);

    manager.writeTask("tasks.txt");


    return 0;
}

void menuPrompt() {
    cout << "*********MAIN MENU**********" << endl;
    cout << "1 - PRINT ALL Tasks" << endl;
    cout << "2 - Print Tasks in Date Range" << endl;
    cout << "3-  Print Task that are still uncompleted" << endl;
    cout << "4 - Complete a task" << endl;
    cout << "5 - Add Task" << endl;
    cout << "6 - Delete Task" << endl;
    cout << "7 - Quit" << endl;
    cout << "Enter choice:";
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









