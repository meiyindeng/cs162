#include <iostream>

using namespace std;

class Clock {
    public:
        //Mutator Function: Modifies the values of the variables
        Clock(int, int ,int); //constructor with parameters
        void setTime (int, int, int);
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();

        //Accessor Function: Only access the values of the member variables
        //a constant member function of a class can only call other constant member functions of that class
        void getTime (int&, int&, int&) const;
        void printTime() const;
        bool equalTime(const Clock&) const; //const cannot modify the member variables of a variable type Clock.



private: //instance variable, every object instance has its own copy of data
        Clock(); //default constructor
        int hr;
        int min;
        int sec;

};
//constructor
Clock::Clock(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}
Clock::Clock() //default constructor
{
    hr = 0;
    min = 0;
    sec = 0;
}

int main()
{
    Clock myClock;
    Clock yourClock;
    int hours;
    int minutes;
    int seconds;
    myClock.setTime(3, 4, 30);

    cout << "My Clock: ";
    myClock.printTime();
    cout << endl;

    yourClock.setTime(5, 45, 16);
    cout << "After setting, Your Clock: ";
    yourClock.printTime();
    cout << endl;


    if (myClock.equalTime(yourClock)){
        cout << "Both times are equal." << endl;
    }

    else{
        cout << "The two times are not equal.";
    }

    myClock.incrementSeconds();
    cout << "After adding 1 second, My Clock: ";
    myClock.printTime();
    cout << endl;

    cin >> hours >> minutes >> seconds;

    //get time passing value from private variable, so what have keyed in doesn't display
    myClock.getTime(hours, minutes, seconds);
    cout << "hours = " << hours
        << "minutes = " << minutes
        << "seconds = " << seconds << endl;

    return 0;
}

void Clock::setTime(int hours, int minutes, int seconds) {
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void Clock::getTime(int& hours, int& minutes, int& seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

void Clock::printTime() const {
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

void Clock::incrementHours()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

void Clock::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void Clock::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

bool Clock::equalTime(const Clock& yourClock) const {
    return (hr == yourClock.hr
            && min == yourClock.min
            && sec == yourClock.sec);

}




