#include <iostream>
#include <string>

using namespace std;

int main() {

    char firstName[200];
    int *pointer;
    char *pointer2;

    firstName[1] = 'A';
    firstName[2] = 'm';
    firstName[3] = 'a';
    firstName[4] = 'n';
    firstName[5] = 'd';
    firstName[6] = 'a';

    int number[4];
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};

    double *p;

    p = balance;

    //replace 2nd value

     cout << *p << endl;
     cout << *(p+2) << endl;







    //pointer = firstName[1];
/*

    // cout << *pointer;

    pointer2 = &firstName[2];

    cout << pointer2 << endl;

    *pointer2 = 'C';

    cout << firstName[2];
*/


    return 0;
}