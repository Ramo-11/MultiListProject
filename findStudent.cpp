#include "findStudent.h"

bool findStudent(int stdNum) 
{
    pointer1 = head;

    while(pointer1->nextStudent != nullptr) {
        if(pointer1->studentID == stdNum) {
            return true;
        }
        pointer1 = pointer1->nextStudent;
    }
    if(pointer1->studentID == stdNum) {
        return true;
    }
    return false;
}