#include <iostream>
#include <cstring>
#include "Task.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Task::Task() {
    taskName[0] = '\0';
    description[0] = '\0';
    month = 0;
    day = 0;
    year = 0;
    complete = 0;

}




istream &operator>>(istream &input, Task &t) {

    input.getline(t.taskName, MAX_STR);
    input.getline(t.description, MAX_STR2);
    input >>t.month >>t.day >> t.year >>
          t.complete;
    input.ignore();
    return input;
}



ostream &operator << (ostream &output, const Task &t){
    output << t.taskName << endl
    << t.description << endl
    << t.month << endl
    <<t.day << endl
    <<t.year << endl
    << t.complete << endl;
    return output;
}


void Task::setTaskName(char n[]) {
    strcpy(taskName, n);
}


void Task::setDescription(char d[]) {
    strcpy(description, d);
}

const char * Task::getDescription() {
    return description;
}

void Task::setMonth(int m) {
    month = m;
}
int Task::getMonth(){
    return month;
}

void Task::setDay(int d) {
    day = d;
}

int Task::getDay() {
    return day;
}

void Task::setYear(int y){
    year = y;
}

int Task::getYear() {
    return year;
}

void Task::setComplete(bool b){
    complete = b;
}

bool Task::getComplete() {
    return complete;
}

const char * Task::getTaskName(){
    return taskName;
}





Task::~Task() {

}





