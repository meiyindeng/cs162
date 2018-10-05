#include<iostream>
using namespace std;
//Function with Array
int list1[5] = {1, 2, 3, 4, 5};
int list2 [5];
int listSize = 5;
int src;
int numberOfElements;
int tar;


//To copy some or all of the elements of one array into another
//int src specifies the position to start copy from list1
//int tar specifies the position in list2
//numofElements specified the number of elements of to be copy
void copyArray(int list1[], int src, int list2 [], int tar, int numOfElements)
{

    for (int index = src; index < (src + numOfElements); index++)
    {
        list2[tar] = list1[index];
        tar++;
    }

    ;
}

int main (){
    copyArray(list1[5], 0, list2[5], 0, 5);
    for (int count = 0; count < listSize; count ++){
            cout << list2[count] << endl;
    }

return 0;
}
