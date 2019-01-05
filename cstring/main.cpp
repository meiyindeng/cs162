#include <iostream>

using namespace std;

void PrintLabel(char * the_label){
    //when we declare an array as the parameter to a function, we only get a pointer
    //array automatically passed by reference
    cout << "Label: " << the_label << endl;
}

int main() {
    char label[] = "single";

    char *labelPtr = label;

    //when funciton is call, its
    PrintLabel(labelPtr);
    return 0;
}