#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "song.h"


using namespace std;


Song::Song() {

    title[0] = '\0';
    artist[0] = '\0';
    year = 0;
    duration = 0;

}

int Song::getYear() {
    return year;
}

void Song::setYear(int year) {
    Song::year = year;
}

double Song::getDuration() {
    return duration;
}

void Song::setDuration(double duration) {
    Song::duration = duration;
}

void Song::getTitle(char *title) {

    strcpy(title, Song::title);
}

void Song::getArtist(char *artist) {

    strcpy(artist, Song::artist);
}

void Song::setTitle(char title[]) {
    strcpy(Song::title, title);
}

void Song::setArtist(char artist[]) {
    strcpy(Song::artist, artist);
}

void Song::print() {
    cout << Song::title << endl;
    cout << Song::artist << endl;
    cout << Song::year << endl;
    cout << Song::duration << endl;
}




