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

int main()
{
  Song * list;
  //list is a pointer to Song Class
  cout << "How many songs you like to add? " << endl;
  int size;
  cin >> size;
  list = new Song[size];








  //Declare Object called array with Song Class
  //Song array[2];  // note that this uses the default constructor

  // Save the address of first object


  char title[MAX_STR];
  char artist[MAX_STR];
  int  year;
  double duration;
  
  /*cout << "Just after array is created" << endl;
  for(int i=0; i<2; i++)
  {
	  cout << "printing " << i << " song in array" << endl;
	  array[i].print();
  }
  cout << endl << endl;*/
  cout << "setting array values and getting values of array" << endl;
  for(int i=0; i<2; i++)
  {
	  cout << "for song " << i << endl;
	  cout << "title? ";
	  cin.getline(title, MAX_STR);
	  //array[i].setTitle(title);
	  list[i].setTitle(char title[]);

	  cout << "artist? ";
	  cin.getline(artist, MAX_STR);
	  array[i].setArtist(artist[]);
	  //list[i].setArtist(char artist);
	  cout << "year? ";
	  cin >> year;
	  cin.ignore();
	  //array[i].setYear(year);
	  //list[i].setYear(int year);
	  cout << "duration in minutes? ";
	  cin >> duration;
	  cin.ignore();
	  //array[i].setDuration(duration);
	  //list[i].setDuration(double duration);
  }

  cout << endl << endl;
  
  for(int i=0; i<2; i++)
  {
      cout << endl;
	  // Using getters to get information to print.
	  cout << "getting song " << i << " information with getters" << endl;
	  //array[i].getTitle(title);
	  list[i].getTitle();
	  cout << "title: " << title << endl;
	  //array[i].getArtist(artist);
	  list[i].getArtist();
	  cout << "artist: " << artist << endl;
	  cout << "year: " << list[i].getYear() << endl;
	  //array[i].getYear() << endl;
	  cout << "duration: " << list[i].getDuration() << endl;
	  //array[i].getDuration() << endl;
	  cout << endl;
	  //Using a print function which is a member of the class Song
	  //This is a better solution but wanted to have students practice
	  // using getters.
	  cout << "printing song " << i << " information again" << endl;
	  //array[i].print();
	  list[i].print();

  }
  
  return 0;
}
