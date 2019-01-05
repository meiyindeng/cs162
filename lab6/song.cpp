#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "song.h"


using namespace std;




Song::Song() {
    title = nullptr;
    artist = nullptr;
    year = 0;
    duration = 0.00;

}


istream &operator>>(istream &isObject, Song &Song) {
    cout << "title: ";
    isObject.ignore();
    isObject.getline(Song.title, MAX_STR);

    cout << "artist: ";
    isObject.getline(Song.artist, MAX_STR);
    cout << "year: ";
    isObject >> Song.year;
    cout << "duration ";
    isObject >> Song.duration;
    return isObject;
}


ostream &operator<<(ostream &osObject, const Song &Song) {
    osObject << "Title: " << Song.title << endl
             << "Artist: " << Song.artist << endl
             << "Year: " << Song.year << endl
             << "Duration: " << Song.duration << endl;
    return osObject;
}
const Song &Song::operator=(const Song& rightHandSong) {
    if (this != &rightHandSong) {
        this->title = strcpy (title, rightHandSong.title);
        this->artist = strcpy (artist, rightHandSong.artist);
        this->year = rightHandSong.year;
        this->duration = rightHandSong.duration;
    }
    return *this;
}

int Song::getYear() {
    return year;
}

void Song::setYear(int y) {
    year = y;

}


double Song::getDuration() {
    return duration;
}

void Song::setDuration(double d) {
    duration = d;
}


const char *Song::getTitle() {
    return title;
}

const char *Song::getArtist() {
    return artist;
}

void Song::setTitle(char t[]) {
    if (title != nullptr) {
        delete title;
    }
    title = new char[strlen(t) + 1];
    strcpy(title, t);
}

void Song::setArtist(char a[]) {
    if (artist != nullptr) {
        delete artist;
    }
    artist = new char[strlen(a) + 1];
    strcpy(artist, a);
}

Song::~Song() {
    delete title;
    delete artist;

}




