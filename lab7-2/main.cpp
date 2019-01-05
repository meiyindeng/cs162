#include <cstdlib>
#include <iostream>
#include <cstring>

#define MAX_SIZE 201

using namespace std;



struct Node {
    char data[MAX_SIZE];
    Node *next;
};


void AddNode(char *addData, struct Node *&head, struct Node *&tail);

void DeleteNode(char *delData, struct Node *&head);

void PrintList(struct Node *head);

void addData(char *data, struct Node *&head, struct Node *&tail);

void delete1Item(char *data, struct Node *&head);

void destroyList(struct Node *&head);


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    char word[MAX_SIZE];


    addData(word, head, tail);

    PrintList(head);

    //delete1Item(word, head);


    destroyList(head);

    PrintList(head);


    return 0;
}

void AddNode(char *addData, struct Node *&head, struct Node *&tail) {
    Node *newNode = new Node;
    strcpy(newNode->data, addData);
    addData(word, head, tail);

    PrintList(head);

    //delete1Item(word, head);


    destroyList(head);

    PrintList(head);


    return 0;
}

void AddNode(char *addData, struct Node *&head, struct Node *&tail) {
    Node *newNode = new Node;
    strcpy(newNode->data, addData);
    newNode->next = NULL;
    newNode->next = NULL;





    /*if (head != NULL){
        tail = head;
        while (tail -> next != NULL){
            tail = tail -> next;
        }
        tail -> next = newNode;
    }

    else{
        head = newNode;
    }*/


    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode = NULL;

    } else {
        tail->next = newNode;
        tail = newNode;


    }
}

void DeleteNode(char *delData, struct Node *&head) {
    Node *temp = NULL;
    Node *tail = NULL;
    Node *delPtr = NULL;
    temp = head;
    tail = head;
    while (tail != NULL && strcmp(tail->data, delData) != 0) {
        temp = tail;
        tail = tail->next;
    }
    if (tail == NULL) {
        cout << delData << " is not in the list" << endl;
        delete delPtr;
    } else {
        delPtr = tail;
        tail = tail->next;
        temp->next = tail;
        delete delPtr;
        cout << "The word '" << delData << "' is deleted" << endl;
    }
}

void PrintList(struct Node *head) {
    Node *tail = NULL;
    tail = head;
    while (tail != NULL) {
        printf("%s", tail->data);
        cout << endl;
        tail = tail->next;

    }
}

void addData(char *data, struct Node *&head, struct Node *&tail) {
    do {
        cout << "enter data: " << endl;
        cin.getline(data, MAX_SIZE);
        if (strcmp(data, "quit") == 0) {
            break;
        }
        AddNode(data, head, tail);
    } while (true);

}

void delete1Item(char *data, struct Node *&head) {

    cout << "enter data to be deleted" << endl;
    cin.getline(data, MAX_SIZE);
    DeleteNode(data, head);
}

void destroyList(struct Node *&head) {
    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;
        }
        AddNode(data, head, tail);
    } while (true);

}

void delete1Item(char *data, struct Node *&head) {

    cout << "enter data to be deleted" << endl;
    cin.getline(data, MAX_SIZE);
    DeleteNode(data, head);
}

void destroyList(struct Node *&head) {
    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;

-- INSERT --
    }

    head = NULL;

}







