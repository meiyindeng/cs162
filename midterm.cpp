//this function find the first instance of the maximum value of an array
#include <iostream>
using namespace std;
int findMaxValue(int array[]);
int main(){

	int array[]={10, 24, 35, 23, 11};
	cout <<	findMaxValue(array);
}
int findMaxValue(int array[]){
	int maxValue=array[0];    
	int first=0;
	for (int i=0; i < sizeof(*array); i++){
	    if (array[i]>maxValue) {
		maxValue=array[i];
		first=i;
	     }
	}
	return first;
}
