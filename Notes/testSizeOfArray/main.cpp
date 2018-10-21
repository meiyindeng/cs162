#include <iostream>

using namespace std;

int main()
{
    int array[20] = {1, 3, 5, 7, 10};
    int count=0;

    int numberOfElement = sizeof(array)/sizeof(array[0]);
    for ( int i = 0; i < numberOfElement; i++){
        if (array[i]!='\0'){
            count++;
        }
    }

    cout << count;
    return 0;
}
