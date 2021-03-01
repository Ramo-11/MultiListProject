#include "Node.h"

Node::Node()
:studentID(0), 
 classID(0),
 N_nextClass(nullptr),
 N_nextStudent(nullptr)  
{}

Node::Node(int studentID, int classID) 
 :N_nextClass(nullptr),
  N_nextStudent(nullptr)
{
    this->studentID = studentID;
    this->classID = classID;
}

Node::~Node() 
{
    delete N_nextStudent;
    delete N_nextClass;
}