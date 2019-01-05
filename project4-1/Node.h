//
// Created by Meiyin Deng on 12/11/18.
//

#ifndef PROJECT5_NODE_H
#define PROJECT5_NODE_H


#include "Task.h"

class Node {
public:
    Node(Task task);

    const Task &getTask() const;

    void setTask(const Task &task);

    Node *getNext() const;

    void setNext(Node *next);

private:
    Task task;
    Node* next;
};


#endif //PROJECT5_NODE_H
