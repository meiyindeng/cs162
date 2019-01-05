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

void buildList(Node* &head, int array[], int count){
    Node* tail = NULL;
    head = new Node();
    tail = head;
    head->data = array[0];
    head->next = NULL;
    for (int i = 1; i < count; i++){
        Node* newNode = new Node;
        newNode->data = array[i];
        //going backward
        newNode->next = head;
        head = newNode;

        //if forward
        //tail->next=newNode;
        //tail = newNode;

    }
}



void insertNumber(Node* &head, int value, int findNumber){
    Node* trailing = NULL;
    Node* current = head;
    while(current != NULL){
        Node* newNode = new Node();
        newNode->data = value;
        if (current->data == findNumber){
            //if insert only when data found, create new node inside the if statement
            //link newNode before find node.
            newNode->next = current;
            //case 1 insert at the head
            if(trailing==NULL){
                head = newNode;
            }
                //case 2 insert in between
            else{
                trailing->next = newNode;
            }
            break;
        }

        //if number not found
        if(current->next == NULL){
            //match trailer to current
            trailing = current;
            //point newNode to NULL
            newNode->next = current->next;
            //link last node to newNode
            trailing->next = newNode;
            //move current to last node
            current = newNode;
        }

        //traversing the list
        trailing = current;
        current = current->next;

    }

}


//pay attention how she call the function

void deleteZeros(Node* &head){
    Node* trailing = NULL;
    Node* current = head;
    while(current != NULL){
        if (current->data==0){
            //delete 1st of the list
            if(trailing==NULL){
                head=head->next;
                delete current;
                current=head;
            }
            //in between
            else{
                trailing->next = current->next;
                delete current;
                current= trailing;
            }

        }
    trailing=current;
    current=current->next;
    }
}


int main()
{
    Node *head = NULL;
    int array[200] = {0, 10, 1, 0, 6, 11, 0};
    int count = 7;

    buildList(head, array, count);
    printList(head);

    /*int newvalue, find;
    cout << "What number to insert?";
    cin >> newvalue;
    cout << "What number to insert it before? ";
    cin >> find;

    // this how the second function will
    // be called.
    insertNumber(head, newvalue, find);

    cout << "AFTER" << endl;*/

    deleteZeros(head);
    printList(head);




    return 0;
}

