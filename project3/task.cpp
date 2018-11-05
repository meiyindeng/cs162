#include <iostream>
#include <string>
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Task::Task() {
    taskName[0] = '\0';
    description[0] = '\0';
    //month = 0;
    //day = 0;
    //year = 0;
    //complete = 0;
}


void Task::setTaskName(char n[]) {
    strcpy(taskName, n);
}

void Task::getTaskName(char *tn) {
    strcpy(tn, Task::taskName);
}

void Task::setDescription(char d[]) {
    strcpy(description, d);
}

void Task::getDescription(char *d){
    strcpy(d, Task::description);
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

void Task::setComplete(bool c){
    complete = c;
}

bool Task::getComplete() {
    return complete;
}


Task::~Task() {

}




    
