#include "Node.h"

Node::Node()
:studentID(0), 
 classID(0),
 grade(0),
 nextClass(nullptr),
 nextStudent(nullptr)  
{}

Node::Node(int studentID, int classID, int grade) 
 :nextClass(nullptr),
  nextStudent(nullptr)
{
    this->studentID = studentID;
    this->classID = classID;
    this->grade = grade;
}

Node::~Node() 
{
    delete nextStudent;
    delete nextClass;
}