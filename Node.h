#ifndef NODE_H
#define NODE_H

#include "Class.h"
#include "Student.h"

#include <iostream>

class Class;
class Student;

class Node {
    //private:
    public:
        int studentID;
        int classID;
        Class* N_nextClass;
        Student* N_nextStudent;

    //public:
        Node();
        Node(int, int);
        ~Node();
};

#endif