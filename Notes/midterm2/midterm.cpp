#include <iostream>
#include <cstring>
using namespace std;
int findMaxValueIndex(int array[], int count);
void insertZero(int array[], int insertPosition, int value, int& count);
int numberOfElement(int array[]);
int main(){
    char Hello[20] = "Merry Christmas!";

    char Christmas[20];

    //copy Hello into Christmas
    strcpy(Christmas, Hello);
         for (int c = 0; c < 20; c++){
            cout << Christmas[c] << endl;
        }
    //length of string
    cout << strlen(Hello);

    char name[20];
    cin.get(name, 20);
    cout << name;
       return 0;

}

    /*
	int array[20]={10, 24, 35, 23, 11};
	cout << sizeof(array) << endl;
	cout << sizeof(array[0]) << endl;
	cout << sizeof(array)/sizeof(array[0]) << endl;
	int length;
	length = numberOfElement(array);
	cout << length << endl;

	int count = sizeof(array)/sizeof(array[0]);
	int firstMaxIndex;
	firstMaxIndex = findMaxValueIndex(array, count);
	insertZero(array, firstMaxIndex, 0, count);
	for (int index = 0; index < count; index++){
	cout << array[index] << ' ';
	}

	return 0;
}


int findMaxValueIndex(int array[], int count){
	int maxValue = array[0];
	int first = 0;
	for (int i = 0; i<count; i++){
	if(array[i] > maxValue){
		maxValue = array[i];
		first = i;
		}
	}
	return first;
}

void insertZero(int array[], int insertPosition, int value, int& count){
	for (int i = count-1; i >= insertPosition; i--){
	array[i+1] = array[i];

	}
	array[insertPosition] = value;
	count ++;
}*/










