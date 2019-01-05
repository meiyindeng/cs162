/* Final proctor exam version example
 * 
 * INSTRUCTIONS
 * =========================
 * 
 *  Write two functions between the comments
 *  indicated below.
 * 
 *   The first function will take a referenced
 *  pointer to a Node (this is the head of the list),
 * an array of numbers and the size of the array. 
 * It will then build a linked list from these numbers
 * using the BACKWARDS order so that the numbers are in 
 * reverse order as in the array.
 * 
 *    The second function will take the head of the
 * list and two numbers: 'newvalue' and 'find'. 
 *  It will insert a node containing 'newvalue' 
 *  BEFORE a node containing 'find'.  If 'find' is not
 *  in the list, it will put 'newvalue' at the end
 *  of the list.
 * 
 * PLEASE SEE MAIN FUNCTION BELOW FOR NAMES OF 
 * FUNCTIONS AND WHAT ORDER THE PARAMETERS ARE IN
 * REMEMBER YOUR CODE NEEDS TO MATCH THESE CALLS.
 * 
 * NOTES
 * ===================================
 * You can change this file all you want during
 * the exam but keep in mind that I will ONLY BE
 * USING YOUR FUNCTIONS by copying them to another
 * main.cpp file.
 * 
 * Do not code to the given data. I will be using 
 * different values in my grading source code file.
 * 
 * Do not use global variables/constants
 * or goto's in your code. head and tail pointers
 * will be provided inside main function
 * and passed in as parameters to your functions.
 * 
 *  You can make more than two functions
 *  but keep all functions between the
 *  given comment lines below.
 * 
 * Do not remove the comment lines as my
 * grading script will not be able to 
 * copy your functions over to my
 * grading source file.
 * 
 * Don't ask the user for information.  The main
 * function will get all information needed and pass it
 * into your function.  See main function for
 * how your function will be called.
 * 
 *
 * three example runs are below:
BEFORE
-----------
11
6
1
10
----------------
What number to insert?20
What number to insert it before? 6
AFTER
-----------
11
20
6
1
10
----------------
BEFORE
-----------
11
6
1
10
----------------
What number to insert?100
What number to insert it before? 19
AFTER
-----------
11
6
1
10
100
----------------

BEFORE
-----------
11
6
1
10
----------------
What number to insert?90
What number to insert it before? 11
AFTER
-----------
90
11
6
1
10
----------------

 */
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE.
// DO NOT REMOVE THE COMMENT LINE ABOVE


//  END OF FUNCTIONS - DO NOT REMOVE THIS COMMENT LINE.

void printList(Node* head)
{
   cout << "-----------" << endl;
   Node* current = head;
   while(current) 
   {
      cout << current->data << endl;
      current = current->next;
   }
   cout << "----------------" << endl;	
}

int main()
{
    Node *head = NULL;
    int array[200] = {10, 1, 6, 11};
	int count = 4;
	
    int newvalue, find;
	
    // this how the first function
    // will be called
    buildList(head, array, count);
    
    cout << "BEFORE" << endl;
    printList(head); 
	
	
	cout << "What number to insert?";
	cin >> newvalue;
    cout << "What number to insert it before? ";
	cin >> find;
    
    // this how the second function will
    // be called.
	insertNumber(head, newvalue, find);
	
	cout << "AFTER" << endl;
    printList(head); 
    
    return 0;
}
