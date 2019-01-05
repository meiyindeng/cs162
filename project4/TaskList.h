#define MAX_STR 30
#define MAX_STR2 100
#define MAX_SIZE 200

#ifndef PROJECT4_TASKLIST_H
#define PROJECT4_TASKLIST_H
using namespace std;



class TaskList {

private:
    Task array[MAX_SIZE];
    int count;


public:

    TaskList();

    void readTask(const char * fileName);

    void addTask();

    int validateAndReturnUserInput(int lowNumber, int highNumber);

    void printRequest(const char *input);

    void requestDate(const char *typeOfTime, int begin, int end);

    void displayTask();

    void requestDateRange(int &startMonth, int &startDay, int &startYear, int &endMonth, int &endYear, int &endDay);

    bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth,
                       int endYear);

    void handleMenu2 ();

    void displayRange(int entry, Task meetStartDate []);

    void completeTask();

    bool isSame(char a[], const char b[]);

    void writeTask(const char * outFileName);

    void uncompleteTask();

    ~TaskList();

};

#endif //PROJECT4_TASKLIST_H
