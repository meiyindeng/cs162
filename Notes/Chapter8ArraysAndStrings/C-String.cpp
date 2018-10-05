#include <iostream>
#include <cstring>

using namespace std;




    //2. Move the smallest element to the beginning of the unsorted list
    //Swap the index



//Selection sort algorithm:
    //Sorting list

void selectionSort(char list[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp;

    //1. Find the location of the smallest element
    for (index = 0; index < length -1; index++){

        smallestIndex = index;
        for(location = index +1; location < length; location++){
            if (list[location] < list[smallestIndex])
                smallestIndex = location;
        }



    //2. To sort swap the value of the smallest index with the list index.
    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;

    }

}

void selectionSort2(char s1[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp;

    //1. Find the location of the smallest element
    for (index = 0; index < length -1; index++){

        smallestIndex = index;
        for(location = index +1; location < length; location++){
            if (s1[location] < s1[smallestIndex])
                smallestIndex = location;
        }



    //2. To sort swap the value of the smallest index with the list index.
    temp = s1[smallestIndex];
    s1[smallestIndex] = s1[index];
    s1[index] = temp;

    }

}

int main(){
    // An array whose components are of type char  ASCII and EBCDIC
    //ch = '\0';
    //C-String is null terminated, the last character is always null character;
    //Ex: char name[16]; only can have a length of 15, to leave room for '\0'
    //Initialize: char name [16] = "John";
    //Must include cstring as header file


    char s1[]="Kathy Brown";
    char list[]="Mark G. Clark";
    //int list[] = {2, 56, 34, 25};
    int i;

    //find the length of the C-String, excluding the null character, the total length will + 1.
    int length = strlen(list) + 1;
    int length2 = strlen(s1) + 1;

    selectionSort(list, length);
    selectionSort2(s1, length2);

    cout << "After sorting, the list elements are:" << endl;

    //for (i = 0; i < 4; i++)
        //cout << list[i] << " " << endl;

    //for (i = 0; i < 4; i++)
        //cout << s1[i] << " " << endl;
    if (length==length2){
        cout << "true";

    }
    else {
        cout << "false";
    }



    cout << "Comparing string 1 with string 2" << endl;
    if (strcmp(s1, list) == 0) {
        cout << "the words are same" << endl;
    }
    else if (strcmp(s1, list) > 0) {
             cout << "the first word is greater" << endl;
             }
             else  {
                cout << "the first word is less" << endl;
             }






    return 0;


}







    //"Air" is less than "An" because 'i' is < 'n';
    //Upper case is less than lower case








