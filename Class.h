#ifndef Class_H
#define Class_H

#include "Node.h"
#include "Student.h"

#include <iostream>

class Student;

class Class {
    //private:
    public:
        int ClassID;
        Class* C_nextClass;
        Student* C_nextStudent;

    //public:
        Class();
        Class(int);
        ~Class();

        void setID(int);
        int getID();
};

#endif