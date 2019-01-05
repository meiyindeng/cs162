#include <iostream>

using namespace std;

//step 1: write an iterative function to solve the problem (using loop)
int totalDiff(int array1[], int array2[], int size);

//step 2: write a "dispatch function" with minimal data set, example size == 0
// if size == 0, the absolution difference will be 0
//must pass smaller data set to iterative function (size -1).
//dispatch must handle last elements in the array

//step 3: In dispatcher, replace call iterative function with call to dispatcher

/*int findLargestNumber(int array [], int size){
    int max = array[0];
    for (int i = 0; i < size; i++){
        if (array[i] > max){
            max = array[i];
        }

    }
    return max;
}*/

int max(int a, int b) {
    if (a > b) {
        return a;
    } else return b;
}

int findLargestNumber(int array[], int size) {

    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return array[0];
    } else {
        return max(array[size - 1], findLargestNumber(array, size - 1));
    }


}

int main() {

    int arrayA[5] = {15, -4, 100, 10, -23};
    int arrayB[5] = {14, -9, 56, 14, -23};

    cout << totalDiff(arrayA, arrayB, 5) << endl;

    cout << findLargestNumber(arrayA, 5) << endl;
    return 0;
}


/*int totalDiff(int array1[], int array2[], int size){
    int diff = 0;
    for (int i = 0; i < size; i++){
        diff += abs(array1[i]-array2[i]);
    }

    return diff;
}*/

int totalDiff(int array1[], int array2[], int size) {
    int diff;
    if (size == 0) {
        return 0;
    } else {
        int lastElementDiff = abs(array1[size - 1] - array2[size - 1]);
        int diff = totalDiff(array1, array2, size - 1) + lastElementDiff;
        return diff;
    }
}

