#include "Student.h"

Student::Student()
:studentID(0), 
 S_nextStudent(nullptr),
 S_nextClass(nullptr) 
{}

Student::Student(int studentID) 
:S_nextStudent(nullptr),
 S_nextClass(nullptr) 
{
    this->studentID = studentID;
}

Student::~Student() 
{
    delete S_nextStudent;
    delete S_nextClass;
}

void Student::setID(int studentID) 
{
    this->studentID = studentID;
}

int Student::getID() 
{
    return this->studentID;
}