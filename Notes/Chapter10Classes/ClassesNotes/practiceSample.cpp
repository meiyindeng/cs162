#include <iostream>

using namespace std;

int main()
{
class clockType
{
public:
    //int hr, int min, int sec
    void setTime(int, int, int);
    void getTime(int&, int&, int) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;
    //passing by reference: the formal parameter receives the address of the actual parameter(hence can change outcome on variable in the main function)
        //actual parameter is parameter in the main function
        //formal parameter is parameter in the separate function
    //const specifies these function cannot modify the member variables of clockType
private:
    int hr;
    int min;
    int sec;
};

    clockType myClock;
    clockType yourClock;

    if(myClock.equal)

return 0;
}
