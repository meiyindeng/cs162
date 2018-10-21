#include <iostream>
//#include <array>
using namespace std;

void insertValue (int nums[], int insertPosition, int value, int lastIndex, int &count);

int main()
{

    int nums[6] = {1, 3, 5, 7, 9};
    //int test[20] = {1, 3, 5, 7, 9};

    //nums[4+1]=nums[4];
    //nums[3+1]=nums[3];
    //nums[2+1]=nums[2];
    int insertPosition=2;
    int lastIndex;
    int value=10;

    int count = 5;

    //to insert value to 2nd position
    insertValue(nums, insertPosition, value, lastIndex, count);


    for ( int i = 0; i < 6; i++){
        cout << nums[i] << ' ';

    }

    return 0;
}

void insertValue (int nums[], int insertPosition, int value, int lastIndex, int &count){

    for (int lastIndex=(count-1); lastIndex >= insertPosition; lastIndex--){
        nums[lastIndex+1]=nums[lastIndex];
    }
      nums[insertPosition]=value;

      count++;

}


