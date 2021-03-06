#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    public:
        int studentID;
        int classID;
        int grade;
        Node *nextStudent;
        Node *nextClass;

        Node();
        Node(int, int, int);
        ~Node();
};

#endif