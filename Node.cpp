#include "Node.h"

Node::Node() 
:studentID(0),
 classID(0),
 grade(0),
 nextStudent(nullptr),
 nextClass(nullptr)
{ }

Node::Node(int studentID, int classID, int grade) 
 :nextStudent(nullptr),
  nextClass(nullptr)
{ 
    this->studentID = studentID;
    this->classID = classID;
    this->grade = grade;
}

Node::~Node() {
    delete nextStudent;
    delete nextClass;
}

