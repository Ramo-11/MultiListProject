#include "printNodes.h"

void printNodes() 
{
    int holdNum = 0;
    pointer1 = head;

    while(pointer1->nextStudent != nullptr) //while we are not at the last node
    {
        pointer1 = pointer1->nextStudent;
        if(pointer1->nextClass != nullptr)  //check if the student has classes
        {
            temp1 = pointer1->nextClass;
            while(temp1->nextClass != nullptr)  //while the student has more than one class
            {
                if(holdNum == temp1->studentID)
                {
                    std::cout << "   class: " << temp1->classID << " ";
                    temp1 = temp1->nextClass;
                }
                else 
                {
                    std::cout << "student: " << temp1->studentID << "\tclass: " << temp1->classID << " ";
                    holdNum = temp1->studentID;
                    temp1 = temp1->nextClass;
                }
            }
            if(holdNum == temp1->studentID)
            {
                std::cout <<  "   class: " << temp1->classID << std::endl;
            }   //end if
            else 
            {
                std::cout << "student: " << temp1->studentID << "\tclass: " << temp1->classID << "\n";
            }
        } //end if
    } //end while
} //end printNodes