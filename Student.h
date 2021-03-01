#ifndef STUDENT_H
#define STUDENT_H

#include "Node.h"
#include "Class.h"

#include <iostream>

class Class;

class Student {
    //private:
    public:
        int studentID;
        Student* S_nextStudent;
        Class* S_nextClass;

    //public:
        Student();
        Student(int);
        ~Student();

        void setID(int);
        int getID();
};

#endif