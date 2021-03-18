#include "getNodeGrade.h"

int getNodeGrade(int stdNum, int clssNum)
{
    pointer1 = head;

    while(pointer1->nextStudent != nullptr)
    {
        pointer1 = pointer1->nextStudent;
        if(pointer1->studentID == stdNum) //if student node was found, now search for class
        {
            temp1 = pointer1->nextClass;
            while(temp1->nextClass != nullptr)
            {
                if(temp1->classID == clssNum)
                {
                    return temp1->grade;
                }
                temp1 = temp1->nextClass;
            }
            return temp1->grade; //It is the last node if not the previous one
        } //end if
    } //end while
    temp1 = pointer1->nextClass;
    while(temp1->nextClass != nullptr)
    {
        if(temp1->classID == clssNum)
        {
            return temp1->grade;
        }
        temp1 = temp1->nextClass;
    }
    return temp1->grade;
}