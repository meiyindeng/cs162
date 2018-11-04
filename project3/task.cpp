#include <iostream>
#include <string>
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Task::Task() {
    taskName[0] = '\0';
    //description[MAX_STR2] = '\0';
    //month = 0;
    //day = 0;
    //year = 0;
    //complete = 0;
}


void Task::setTaskName(char n[]) {
    strcpy(taskName, n);

}

void Task::getTaskName(char *tn) {
    tn = new char[MAX_STR];
    strcpy(tn, Task::taskName);
}

/*void Task::setDescription(char d[]) {
    strcpy(description, d);
}

void Task::setMonth(int m) {
    month = m;
}

void Task::setDay(int d) {
    day = d;
}

void Task::setYear(int y){
    year = y;
}

void Task::setComplete(bool c){
    complete = c;
}
*/


Task::~Task() {

}




    
