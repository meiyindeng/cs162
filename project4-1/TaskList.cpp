#include <iostream>
#include <cstring>

#include "TaskList.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


TaskList::TaskList() {

    //Task task;
    //Task array[MAX_SIZE];
    head = NULL;
    tail = NULL;

}


void TaskList::writeTask(const char *outFileName) {
    Task task;
    ofstream outFile;
    outFile.open(outFileName);

    Node *current = head;
    if (head==NULL){
        return;

    }

    else {
        tail = NULL;
        while (current != NULL) {
            task = current->getTask();
            outFile << task;

            tail = current;
            current = current -> getNext();

        }


    }

    outFile.close();


}


void TaskList::readTask(const char *fileName) {
    ifstream taskInputFile(fileName);
    char c = taskInputFile.peek();

    if (taskInputFile.fail()) {
        return;
    }


    while (!taskInputFile.eof() && c != '\n') {

        Task task;
        taskInputFile >> task;


        addTaskToList(task);



        taskInputFile.peek();

    }

    taskInputFile.close();


}

void TaskList::addTaskToList(Task t) {
    Node *temp = new Node(t);

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->setNext(temp);
        tail = temp;

    }

}
void TaskList::deleteTask() {
    Task task;
    char taskNameInput[MAX_STR];
    printRequest("Enter name of task to delete");
    cin.ignore();
    cin.getline(taskNameInput, MAX_STR);

    if(markTaskDelete(task, taskNameInput)){
        cout << "the task " << taskNameInput << " deleted" << endl;
    }

    else{
        cout << "task not found" << endl;
    }

}

bool TaskList::markTaskDelete(Task task, char* taskNameInput){
    Node* current = head;
    if (head==NULL){
        cout << "No task in list" << endl;
        return false;
    }
    else{
        tail = NULL;
        while (current != NULL){
            task = current->getTask();
            if(compareTaskName(task, taskNameInput)){
                if(current == head){
                    head = head->getNext();
                    delete current;
                    return true;

                }
                else{
                    if (current->getNext()==NULL){
                        tail->setNext(NULL);
                        delete current;
                        return true;
                    }
                    else {
                        tail->setNext(current->getNext());
                        delete current;
                        current = tail;
                        return true;
                    }

                }



            } else {
                tail = current;
                current = current->getNext();
            }
        }
    }

    return false;
}


//1. compare task name see if match
//2. get the node contains this task name
//3. delete node
//4. markTaskDelete


bool TaskList::markTaskComplete(Task task, char *taskNameInput){
    Node *current = head;
    if (head==NULL){
            return false;

    }

    else {
        tail = NULL;
        while (current != NULL) {
            task = current->getTask();
            if (compareTaskName(task, taskNameInput)) {
                task.setComplete(true);
                current->setTask(task);
                return true;
            } else {
                tail = current;
                current = current->getNext();
            }
        }
    }

        return false;


}

bool TaskList::compareTaskName(Task task, char taskNameInput[]){
    bool searchResult;

    searchResult=isSame(taskNameInput, task.getTaskName());
    return searchResult;

}

void TaskList::completeTask() {
    Task task;
    char taskNameInput[MAX_STR];
    printRequest("Enter name of task to complete");
    cin.ignore();
    cin.getline(taskNameInput, MAX_STR);

    if(markTaskComplete(task, taskNameInput)){
        cout << "the task " << task.getTaskName() << " has been completed" << endl;
    }

    else{
        cout << "task not found" << endl;
    }

}

void TaskList::addTask() {
    char taskName[MAX_STR];
    char description[MAX_STR2];
    int month;
    int day;
    int year;
    bool complete;
    Task task;

    printRequest("Enter Name:");
    cin.ignore();
    cin.getline(taskName, MAX_STR);
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

    addTaskToList(task);



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

void TaskList::requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay) {
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
                             int endMonth, int endYear) {

    int entryDate = (year * 10000) + (month * 100) + day;
    int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
    int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

    return entryDate >= startDate && entryDate <= endDate;
}
void TaskList::displayTask() {
    Task meetRequestDate;
    Node *current = head;
    if (head==NULL){
        return;

    }

    else {
        tail = NULL;
        while (current != NULL) {
            meetRequestDate = current->getTask();
            printf("TaskName: %s", meetRequestDate.getTaskName()); cout << endl;
            printf("Task Description: %s", meetRequestDate.getDescription()); cout << endl;
            cout << "Month: " << meetRequestDate.getMonth() << "/" << meetRequestDate.getDay() << "/" << meetRequestDate.getYear()
                 << endl;
            if(meetRequestDate.getComplete()==1) {
                cout << "Task is: COMPLETE" << endl;
            }else{
                cout << "Task is NOT COMPLETE" << endl;
            }


            tail = current;
            current = current->getNext();
        }

    }


}
void TaskList::handleMenu2() {
    Task task;
    int startMonth;
    int startDay;
    int startYear;
    int endMonth;
    int endYear;
    int endDay;
    Task meetRequestDate;
    TaskList meetDate;



    requestDateRange(startMonth, startDay, startYear, endMonth, endYear, endDay);
    Node * current = head;
    if (head==NULL) {
        return;
    }
    tail=NULL;
    while (current != NULL){
        task = current->getTask();

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

            meetRequestDate = task;

            meetDate.addTaskToList(meetRequestDate);



        }

     tail = current;
     current = current->getNext();

    }

    meetDate.displayTask();


}










bool TaskList::isSame(char a[], const char b[]) {
        if (strcmp(a, b) == 0) {
            return true;
        }

    return false;
}

TaskList::~TaskList() {

}


void TaskList::printInComplete(){
    Task inComplete;
    Node *current = head;
    if (head==NULL){
        return;

    }

    else {
        tail = NULL;
        while (current != NULL) {
            inComplete = current->getTask();
            if (inComplete.getComplete()==0) {
                printf("TaskName: %s", inComplete.getTaskName());
                cout << endl;
                printf("Task Description: %s", inComplete.getDescription());
                cout << endl;
                cout << "Month: " << inComplete.getMonth() << "/" << inComplete.getDay() << "/" << inComplete.getYear()
                     << endl;
                if (inComplete.getComplete() == 1) {
                    cout << "Task is: COMPLETE" << endl;
                } else {
                    cout << "Task is NOT COMPLETE" << endl;
                }

            }
            tail = current;
            current = current->getNext();
        }

    }


}
















