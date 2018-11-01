#include <iostream>
#include <cstring>
#include "task.h"

using namespace std;

Task::Task(){
    taskName[0] = '\0';
    description[0] = '\0';
    month = 0;
    day = 0;
    year = 0;
    complete = false;
}

void Task::setTaskName(char taskName[]){
    strcpy(Task::getTaskName, taskName);
}
    
