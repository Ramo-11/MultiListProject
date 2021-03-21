#include "Methods.h"

Methods::Methods()
:head(nullptr),
 temp1(nullptr),
 pointer1(nullptr),
 pointer2(nullptr)
 {}

Methods::~Methods()
{
    delete head;
    delete temp1;
    delete pointer1;
    delete pointer2;
}

void Methods::setUp() 
{
    head = new Node();
    temp1 = new Node();
    pointer1 = new Node();
    pointer2 = new Node();

    head->studentID = 1;
    head->classID = 1;

    head->nextStudent = nullptr;
    head->nextClass = nullptr;
}

void Methods::addGrade(int stdNum, int clssNum, int gradeChoice)
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

bool Methods::findNode(int stdNum, int clssNum)
{
    pointer2 = getStdNode(stdNum);

    while(pointer2->nextClass != nullptr)
    {
        if(pointer2->classID == clssNum)
        {
            return true;
        }
        pointer2 = pointer2->nextClass;
    }
    if(pointer2->classID == clssNum)
    {
        return true;
    }
    return false;
}

bool Methods::findStudent(int stdNum) 
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

int Methods::getNodeGrade(int stdNum, int clssNum)
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

Node* Methods::getStdNode(int stdNum)
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

void Methods::insertElementNode(int stdNum, int clssNum)
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

void Methods::insertStudentNode(int stdNum) 
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

void Methods::printNodes() 
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