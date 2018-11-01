#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "song.h"


using namespace std;


Song::Song() {

    title = nullptr;
    artist = nullptr;
    year = nullptr;
    duration = nullptr;

}

const int * Song::getYear(){
    return year;
}

void Song::setYear(int y) {
    if(year != nullptr){
        delete year;
    }
    year = &y;

}



const double * Song::getDuration(){
    return duration;
}

void Song::setDuration(double d) {
    if (duration != nullptr) {
        delete duration;
    }
    duration = &d;
}


const char * Song::getTitle() {
    return title;
}

const char * Song::getArtist(){
    return artist;
}

void Song::setTitle(char t[]) {
    if(title != nullptr){
        delete title;
    }
    title = new char[strlen(t)+1];
    strcpy(title, t);
}

void Song::setArtist(char a[]) {
    if(artist != nullptr){
        delete artist;
    }
    artist = new char[strlen(a)+1];
    strcpy(artist, a);
}

void Song::print() {
    cout << Song::title << endl;
    cout << Song::artist << endl;
    cout << Song::year << endl;
    cout << Song::duration << endl;
}

Song::~Song(){

}




