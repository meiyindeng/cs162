
#define MAX_STR 30
#define MAX_STR2 100
#define MAX_SIZE 200
using namespace std;


class Task{

    friend istream& operator >> (istream &input, Task &t);
    friend ostream& operator << (ostream &output, const Task& t);


private:
    char taskName [MAX_STR];
    char description [MAX_STR2];
    int month;
    int day;
    int year;
    bool complete;
public:
    Task();
    char * insertTaskName();
    void setTaskName(char taskName[]);
    void setDescription(char description[]);
    void setMonth(int m);
    int getMonth();
    void setDay(int d);
    int getDay();
    void setYear(int y);
    int getYear();
    void setComplete(bool b);
    bool getComplete();
    const char * getTaskName();
    const char * getDescription();



    ~Task();
};

