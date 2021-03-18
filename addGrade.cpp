#include "addGrade.h"

void addGrade(int stdNum, int clssNum, int gradeChoice)
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
                    temp1->grade = gradeChoice;
                    return;
                }
                temp1 = temp1->nextClass;
            }
            temp1->grade = gradeChoice; //It is the last node if not the previous one
            return;
        } //end if
    } //end while
    temp1 = pointer1->nextClass;
    while(temp1->nextClass != nullptr)
    {
        if(temp1->classID == clssNum)
        {
            temp1->grade = gradeChoice;
            return;
        }
        temp1 = temp1->nextClass;
    }
    temp1->grade = gradeChoice;
    return;
}