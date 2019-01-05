#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>

#define MAX_SIZE 30

using namespace std;



struct Student {
    char studentName[MAX_SIZE];
    //need to check ID is positive
    int studentID;

    //need to check if grade is between 1.0 and 4.0
    float studentGrade;


    Student* next;
};

void addNode(char* word, int number, float number2, struct Student *&head, struct Student *&tail, int &size);
void addData(struct Student *&head, struct Student *&tail, int &size);
void PrintList(struct Student *head);
void destroyList(struct Student *&head);
void menuPrompt();
int validateInput(string instruction, int &input, int lowNumber, int highNumber);
float validateFloatInput(string instruction, float &floatInput, float lowValue, float highValue);
void deleteNode(Student* &head, Student* &tail, int &size);


int main() {

    Student *head = NULL;
    Student *tail = NULL;
    int size = 0;


    int menuChoice;
    do {
        menuPrompt();

        validateInput("Enter data =>", menuChoice, 1, 4);


        if (menuChoice == 1) {
            addData(head, tail, size);
        }

        if (menuChoice == 2) {
            PrintList(head);
        }

        if (menuChoice == 3) {
            deleteNode(head, tail, size);
        }



    }

    while(menuChoice!=4);



    destroyList(head);

    return 0;
}

void addNode(char* word, int number, float number2, struct Student *&head, struct Student *&tail, int &size) {
    Student* newNode = new Student;
    strcpy(newNode->studentName, word);
    newNode->studentID = number;
    newNode->studentGrade = number2;
    newNode->next = NULL;
    //case 1 - empty list
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode = NULL;
    }

    else{
        Student* Current = head;
        Student* tail = NULL;
        while (Current != NULL){
            if(Current->studentID >= newNode->studentID){
                break;
            }
            else{
                tail = Current;
                Current = Current -> next;
            }
        }
        //case 2 - insert at head
        if(Current == head){
            newNode->next = Current;
            head = newNode;
        }

        else{
            //case 3 - insert between
            newNode->next = Current;
            tail ->next = newNode;
        }

    }

    size++;

}

void addData(struct Student *&head, struct Student *&tail, int &size) {
    char word [MAX_SIZE]; int number; float number2;
    cout << "enter student name: " << endl;
    cin.ignore();
    cin.getline(word, MAX_SIZE);
    validateInput("enter student ID (positive number): ", number, 0, 10000);
    validateFloatInput("enter student grade (1.0 to 4.0):  ", number2, 1.00, 4.00);
    addNode(word, number, number2, head, tail, size);

}

void PrintList(struct Student *head) {
    if (head==NULL){
        cout << "No data in the list" << endl;
    }
    else {
        Student *tail = NULL;
        tail = head;
        while (tail != NULL) {
            cout << "ID: " << tail->studentID << endl;
            cout << "name: "; printf("%s", tail->studentName); cout << endl;
            cout << "grade: " << setprecision(3) << showpoint << tail->studentGrade << endl;
            tail = tail->next;

        }
    }
}

void destroyList(struct Student *&head) {
    Student *curr = head;
    Student *temp = NULL;

    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;

    }

    head = NULL;

}

void menuPrompt(){

    cout << "????? What do you want to do ?????" << endl;
    cout << "1. add student" << endl;
    cout << "2. print all students" << endl;
    cout << "3. delete student" << endl;
    cout << "4. quit" << endl;

}

int validateInput(string instruction, int &input, int lowNumber, int highNumber){
    bool inputValidity = false;
    while(!inputValidity){
        cout << instruction << endl;
        cin >> input;
        if (input >= lowNumber && input <= highNumber){
            inputValidity = true;
        }
        else{
            cout << "invalid input, please re-enter" << endl;
        }
    }

    return input;
}

float validateFloatInput(string instruction, float &floatInput, float lowValue, float highValue){
    bool inputValidity = false;
    while(!inputValidity){
        cout << instruction << endl;
        cin >> floatInput;
        if (floatInput >= lowValue && floatInput <= highValue){
            inputValidity = true;
        }
        else{
            cout << "invalid input, please re-enter" << endl;
        }
    }

    return floatInput;
}

void deleteNode(Student* &head, Student* &tail, int &size){
    int deleteNumber;
    validateInput("Enter student ID to delete", deleteNumber, 0, 10000);
    //case 1 - empty list
    if(head == NULL){
        cout << "Node cannot be deleted from an empty linked list" << endl;
    }

    else{
        //create Current and Trailing node like when you do insert
        Student* Current = head;
        tail = NULL;
        //Traverse list to find the node to delete
        while (Current != NULL){
            if(Current->studentID==deleteNumber){
                break;
            }
            else{

                tail = Current;
                Current = Current->next;
            }
        }

        //after go through traversing the list
        if(Current == NULL){
            cout << "StudentID is not found." << endl;
        }
        else{
            //both case need to delete the node
            //case 3 delete from the head node
            if(head == Current){
                head = head->next;

            }
                //case 4 delete beyond the head node
            else{
                //move the trail->next pointer to point pass the current pointer (current->next)
                tail->next = Current->next;

            }
            delete Current;
            size--;
        }

    }

}