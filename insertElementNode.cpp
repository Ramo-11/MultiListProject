#include "insertElementNode.h"
#include "getStdNode.h"

void insertElementNode(int stdNum, int clssNum)
{
    Node *newNode = new Node();
    Node *temp2 = new Node();

    pointer2 = getStdNode(stdNum); //pointer2 = head

    while(pointer2->nextClass != nullptr) 
    {
        if(clssNum < pointer2->classID)
        {
            temp2->nextClass = newNode;
            newNode->nextClass = pointer2;
            newNode->nextStudent = nullptr;

            newNode->classID = clssNum;
            newNode->studentID = stdNum;
            return;
        }
        else
        {
            temp2 = pointer2;
            pointer2 = pointer2->nextClass;
        }
    }

    if(clssNum < pointer2->classID)
    {
        temp2->nextClass = newNode;
        newNode->nextClass = pointer2;
        newNode->nextStudent = nullptr;
    }
    else 
    {
        pointer2->nextClass = newNode;
        newNode->nextClass = nullptr;
        newNode->nextStudent = nullptr;
    }
    newNode->studentID = stdNum;
    newNode->classID = clssNum;
}