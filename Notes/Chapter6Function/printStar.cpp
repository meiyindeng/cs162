#include <iostream>
using namespace std;
void printStars (int blanks, int starsInline);

int main()
{
int numberOfLines;
int numberOfBlanks;
int counter;

    cout << "Enter the number of star line (1 to 20) to be printed: ";
    cin >> numberOfLines;

    while (numberOfLines < 0 || numberOfLines > 20)
    {
    cout << "Enter the number of star lines "
    << "(1 to 20) to be printed: ";
    cin >> numberOfLines;
    }

    cout << endl << endl;
    numberOfBlanks = 5;

    for (counter = 1; counter <= numberOfLines; counter++)
    {
    printStars(numberOfBlanks, counter);
    numberOfBlanks--;
    }
return 0;
}



void printStars (int blanks, int starsInline)
{
    int count;
    int starsInLine;
    for (count = 1; count <= blanks; count ++)
        cout << ' ';

    for (count = 1; count <= starsInLine; count ++)
        cout << " *";
    cout << endl;
}
