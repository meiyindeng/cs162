//
// Created by Meiyin Deng on 12/11/18.
//

#include "Node.h"

Node::Node(Task task) {
    this->task = task;
    this->next = NULL;

}

const Task &Node::getTask() const {
    return task;
}

void Node::setTask(const Task &task) {
    this->task = task;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}
