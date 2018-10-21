#include <iostream>
#include <array>
using namespace std;

//void insertValue(int value, int index, int array[], int& count);
int main(){
int nums [] = {1, 3, 5, 8, 10};
    for (int i=0; i<5; i++){
    cout << nums[i] << ' ' << endl;
    cout << i;
    }


/*insertValue(7, 2, array, count);
	for (int i=0; i<sizeof(array); i++){
		cout << array[i];
	}

*/
return 0;
}

/*void insertValue(int value, int index, int array[], int& count){
//current count is 5,
//last index is 4; count -1
//starting from the last index, increase each index down one
//insert value to 2nd inde

	for (int i = count -1; i>=index; i-- ){
	array[i+1] = array[i];
	}
//make sure insert after the loop
	array[index]=value;
	count++;



}*/
