#include <iostream>

using namespace std;

int main()
{
    //3 Types of Data: Simple, Structured and Pointers
        //Simple - variables of that type can store only one value at a time
        //Structured data - a collection of other data items.
          //Ex: Array
    //Arrays: a collection of a fixed number of components (elements) all of the same data typeand in contiguous (adjacent) memory space.
        //One-dimensional array: Components are arranged in a list form.
        //Declare array: dataType arrayName [intExp]; intExp specifies the number of components
        //Ex: int num [5], an array named num of 5 components, each component is of type integer.

    //Accessing Array Components
        //arrayName[indexExp] use index specifies the position of the component. Starts at 0
        //[] array subscripting opeartor
        //Assignment statement list[5] = 34; stores 34 in list[5], the 6th components
        //individually separate variables: list[0]; list[2*i-3]=58; when i = 4, list [5] = 58
        //Declare a named constant const int ARRAY_SIZE = 10
        //int list [ARRAY_SIZE]

    //Processing One-Dimensional Arrays
        int list [5];
        int i;
        //Using for loop steps through each elemnet of the array list
        //1. Initializing an array
            for (i = 0; i < 5; i++){
             //initialize to 0.0
             list [i] = 0.0;
            }
        //2.
            cout << "Reading data into an array: " << endl;
            //input data:   cin >> list [i];
            for (i = 0; i < 5; i++){
                cin >> list[i];
            }
        //3.
            cout << "Print an array: " << endl;
            //output each data: cout << list [i];
            for (i = 0; i < 5; i++){
                cout << list[i];
            }
        //4.
            cout << "Find the sum an average of an array: " << endl;
            int sum = 0;
            for (i = 0; i < 5; i++){
                sum = sum + list[i];
            }
            cout << sum << endl;
            int average = sum / 5;
            cout << average << endl;
        //5.
            cout << "Largest element in the array: " << endl;
            //i. maxIndex is initialized to 0
            //ii. compare the element pointed to by maxIndex with every subsequent elemnt in the list
            //iii. whenever we find a larger element, we update maxIndex, so it points to the new larger element.
            int maxIndex = 0;
            for (i = 1; i < 5; i++){
                if (list[maxIndex] < list[i])
                    maxIndex = i;
            }
            int largestElement = list[maxIndex];
            cout << largestElement << endl;

        //6.
            cout << "List elements than average : " << endl;
            for (i = 0; i < 5; i++){
                if (list[i] < average)
                        cout << list[i] << " is less than average " << endl;
            }
    //Array Index Out of Bounds
        //C++ does not check whether the index value is within range (between 0 and ARRAY_SIZE -1)
        //Can result altering or accessing unintended data or memeory
    //Array Initialization during Declaration
    double sales[] = {12.25, 32.50, 16.90, 23, 45.68};
        //Values are placed between curly braces and separated by commas
        //The size is determined by the number of initial values in the braces
    //Partial Initialization of Arrays
        //int list [10] = {0};
        //If all of the values are not specified in the initialization statement, the array components for which the values are not specified are initialized to 0
    //Restrictions on Array Processing
        //Not allow to copy elements from one array to another;
        int myList[5] = {1, 2, 3, 4, 5};
        int yourList[5]; //illegal yourLIst = myList;
        //Must copy component-wise:
        //Ex: yourList[0] = myList[0]
        //Must read one component at a time: arrayName[Index]
        int index;
        for (index = 0; index < 5; index ++){
            yourList [index] = myList [index];
            cout << yourList[index] << endl;
        }










      return 0;
}
