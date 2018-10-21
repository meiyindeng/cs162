#include <iostream>
#include <fstream>
using namespace std;
int returnUserInput(bool valid, int lowNumber, int highNumber, int &input);

int main()
{
    int input;
    cout << "Enter a number";
    input = returnUserInput(false, 1, 4, input);
    cout << "User Input is: " << input;

  return 0;
}

int returnUserInput(bool valid, int lowNumber, int highNumber, int &input){
    while(!valid){

    cin >> input;
        if(input >= lowNumber && input <= highNumber){
        valid = true;
        }
    }
    return input;
}

/*bool checkMenuChoice(int menuChoice){
    bool checkMenu = false
     if (menuChoice>=1 && menuChoice<=4){
        checkMenu = true;
     }
    return checkMenu;

}*/
