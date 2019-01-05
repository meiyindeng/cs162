/* 
 * Song program
 * For Lab 4
 * 
 * Create two separate files called song.cpp and song.h
 * to be compiled with this file.
 * DO NOTls CHANGE THIS FILE!.  I will be using an exact copy of this file
 * with different data to compile your code with so whatever changes
 *  are made will not be used when I grade your lab submission.
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "song.h"


using namespace std;

void printRequest(string input) {
    cout << input << endl;
}

void gatherSongFromUser(int size, Song *list, char *title, char *artist, int year, double duration);

void printSong(int size, Song *list);

int askNumberOfSong();


int main() {

    Song *list;
    //list is a pointer to Song Class
    char title[MAX_STR];
    char artist[MAX_STR];
    int year=0;
    double duration=0;

    int size = askNumberOfSong();
    list = new Song[size];
    int size;
    Song mySong[size];
    for (int i = 0, i < size, i++){


    }
    cin >> mySong[0];


    cout << mySong;


    //gatherSongFromUser(size, list, title, artist, year, duration);


    // [] list;

    return 0;
}

// This function gather songs info from user
/*void gatherSongFromUser(int size, Song *list, char *title, char *artist, int year, double duration) {
    cout << "setting array values and getting values of array" << endl;
    for (int i = 0; i < size; i++) {
        cout << "for song " << i << endl;
        printRequest("title?");
        cin.ignore();

        cin.getline(title, MAX_STR);
        (list + i)->setTitle(title);

        printRequest("artist? ");
        cin.getline(artist, MAX_STR);
        (list + i)->setArtist(artist);

        printRequest("year?");
        cin >> year;
        (list + i)->setYear(year);
        printRequest("duration in minutes");
        cin >> duration;
        (list + i)->setDuration(duration);

        cout << endl << endl;
    }
}*/

//This function get print each song info
/*void printSong(int size, Song *list) {
    for (int i = 0; i < size; i++) {
        cout << "printing song " << i << " information again" << endl;
        cout << "======Song======" << endl;
        cout << (list + i)->getTitle() << endl;
        cout << (list + i)->getArtist() << endl;
        cout << (list + i)->getYear() << endl;
        cout << (list + i)->getDuration() << endl;
    }
}*/

int askNumberOfSong() {
    int size;
    cout << "How many songs you like to add? " << endl;
    cin >> size;
    cin.ignore();

    return size;

}