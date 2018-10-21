#include <iostream>
using namespace std;
void deleteValue(int array[], int deletePosition, int count);
int main(){

    int array[]={1, 3, 5, 7, 9};

    int count=5;


    deleteValue(array, 0, count);

    for (int i=0; i< count; i++){
        cout << array[i] << ' ';

    }

    return 0;

}

void deleteValue(int array[], int deletePosition, int count){

    for (int index=deletePosition; index < count; index++){
        array[index]=array[index+1];

    }
    count--;


}

