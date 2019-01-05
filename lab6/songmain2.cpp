/*
 * Song main 2 program
 * For Lab 6
 *
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "song.h"

using namespace std;

const int SIZE = 3;




int main()
{
    Song array[SIZE];

    cout << "-> Testing cin -> " << endl;
    cin >> array[0];
    cin >> array[1];

    cout << "-> Testing cout ->"  << endl;
    for(int i=0; i<SIZE; i++)
    {
        cout << "for song #" << i << endl;
        cout << array[i];
    }

    cout << "-> Testing assignment ->" << endl;
    cout << "-> array[2] = array[0] ->" << endl;
    array[2] = array[0];

    for(int i=0; i<SIZE; i++)
    {
        cout << array[i];
    }

    return 0;
}
