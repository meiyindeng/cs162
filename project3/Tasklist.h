
#define MAX_STR 30
#define MAX_STR2 100
#define MAX_SIZE 200

#include "task.h"

#ifndef PROJECT3_TASKLIST_H
#define PROJECT3_TASKLIST_H


class Tasklist {

private:
    Task listOfTask [MAX_SIZE];
    int count;

};

public:
    void addTask(int &count, char taskName[], char description[], int month, int day, int year,
             bool complete);


#endif //PROJECT3_TASKLIST_H
