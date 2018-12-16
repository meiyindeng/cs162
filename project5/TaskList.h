#include "Node.h"

#define MAX_STR 30
#define MAX_STR2 100
#define MAX_SIZE 200

#ifndef PROJECT4_TASKLIST_H
#define PROJECT4_TASKLIST_H
using namespace std;



class TaskList {

private:

    Node* head;
    Node* tail;



public:

    TaskList();


    //This is for linked list
    void addTaskToList(Task t);

    bool markTaskComplete(Task task, char *taskNameInput);

    bool compareTaskName(Task task, char taskNameInput[]);

    void completeTask();

    void readTask(const char * fileName);

    void addTask();

    int validateAndReturnUserInput(int lowNumber, int highNumber);

    void printRequest(const char *input);

    void requestDate(const char *typeOfTime, int begin, int end);


    void requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay);

    bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                       int endYear);

    void handleMenu2 ();

    void displayTask();





    bool isSame(char a[], const char b[]);

    void writeTask(const char * outFileName);


    void printInComplete();

        ~TaskList();

};

#endif //PROJECT4_TASKLIST_H
