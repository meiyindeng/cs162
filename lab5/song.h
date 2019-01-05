#define MAX_STR 200
#include <iostream>
#include <cstring>
using namespace std;


class Song {

    friend istream& operator>> (istream&, Song&);

    friend ostream& operator<< (ostream& Song, const class Song&);

private:

    int year;
    double duration;
    char * title;
    char * artist;
public:
    Song();

    const Song& operator= (const Song&);

    int getYear();

    void setYear(int year);

    double getDuration();

    void setDuration(double duration);

    const char * getTitle();

    const char * getArtist();

    void setTitle(char title[]);

    void setArtist(char artist[]);



    ~Song();

};