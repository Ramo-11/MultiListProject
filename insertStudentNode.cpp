#include "insertStudentNode.h"

void insertStudentNode(int stdNum) 
{
    Node *newNode = new Node();
    Node *temp1 = new Node();

    pointer1 = head;

    while(pointer1->nextStudent != nullptr)
    {
        //Insert node in the middle
        if(stdNum < pointer1->studentID) 
        {
            temp1->nextStudent = newNode;
            newNode->nextStudent = pointer1;
            newNode->nextClass = nullptr;

            newNode->studentID = stdNum;
            newNode->classID = 0;
            return;
        }
        else 
        {
            temp1 = pointer1;
            pointer1 = pointer1->nextStudent;
        }
    }

    //Insert node before the last one
    if(stdNum < pointer1->studentID)
    {
        temp1->nextStudent = newNode;
        newNode->nextStudent = pointer1;
        newNode->nextClass = nullptr;
    }
    //Insert node as the last one and make it point to null
    else 
    {
        pointer1->nextStudent = newNode;
        newNode->nextStudent = nullptr;
        newNode->nextClass = nullptr;
    }

    newNode->studentID = stdNum;
    newNode->classID = 0;
}