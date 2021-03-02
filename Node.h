#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    public:
        int studentID;
        int classID;
        int grade;
        Node* nextClass;
        Node* nextStudent;

        Node();
        Node(int, int, int);
        ~Node();
};

#endif