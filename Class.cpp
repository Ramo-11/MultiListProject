#include "Class.h"

Class::Class()
:ClassID(0), 
 C_nextClass(nullptr),
 C_nextStudent(nullptr)
{}

Class::Class(int ClassID) 
:C_nextClass(nullptr),
 C_nextStudent(nullptr)
{
    this->ClassID = ClassID;
}

Class::~Class() 
{
    delete C_nextClass;
    delete C_nextStudent;
}

void Class::setID(int ClassID) 
{
    this->ClassID = ClassID;
}

int Class::getID() 
{
    return this->ClassID;
}