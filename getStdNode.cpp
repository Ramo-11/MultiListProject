#include "getStdNode.h"

Node* getStdNode(int stdNum)
{
    pointer1 = head;

    while(pointer1->nextStudent != nullptr)
    {
        if(pointer1->studentID == stdNum)
        {
            return pointer1;
        }
        pointer1 = pointer1->nextStudent;
    }
    return pointer1;
}