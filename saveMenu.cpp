#include "Node.h"
#include <cmath>

void setUp();
void menu();
void insertStudentNode(int);   //Adds a student element node
void insertElementNode(int, int);
bool findStudent(int);  //Finds if a node with the given index exist
bool findNode(int, int);
int getStdGrade(int);  //returns the grade of the given student
void addGrade(int, int);    //assigns a grade to the given student node
void printNodes();
Node* getStdNode(int);
void addGrade(int, int, int);

    Node *head = new Node();
    Node *temp1 = new Node();
    Node *pointer1 = new Node();
    Node *pointer2 = new Node();

int main() {
    int menuChoice;
    int stdNum = 1;
    int clssNum = 1;
    int gradeChoice = 1;
    bool keepGoing = true;

    std::cout << "\nWelcome to my multi linked list program!\n\n";

    while(keepGoing) {
        menu();
        std::cin >> menuChoice;

        switch(menuChoice)
        {   
            case 1:
                std::cout << "Enter a student's number and a class number to add (enter zero for both to exit): \n";
                std::cin >> stdNum;
                std::cin >> clssNum;
                if(findStudent(stdNum) && findNode(stdNum, clssNum))
                {
                    std::cout << "Node already exist\n";
                    continue;
                }
                else if(findStudent(stdNum))
                {
                    insertElementNode(stdNum, clssNum);
                    std::cout << "Node has been added\n\n";
                    continue;
                }
                else 
                {
                    insertStudentNode(stdNum);
                    insertElementNode(stdNum, clssNum);
                    std::cout << "Node has been created!\n\n";
                    continue;
                }
            case 2:
                std::cout << "type student number and class number that you want to add the grade to: \n";
                std::cin >> stdNum;
                std::cin >> clssNum;
                if(findStudent(stdNum) && findNode(stdNum, clssNum))
                {
                    std::cout << "What grade would you like to input? (Enter a number between 0 and 100): \n";
                    std::cin >> gradeChoice;
                    if((gradeChoice < 0) || (gradeChoice > 100))
                    {
                        std::cout << "Invalid Input\n\n";
                        continue;
                    }
                    addGrade(stdNum, clssNum, gradeChoice);
                    std::cout << "Grade has been added\n\n";
                    continue;
                }
                else 
                {
                    std::cout << "Node does not exist!\n\n";
                    continue;
                }
            } //end switch      
        } //end while

    delete pointer1;
    std::cout << "\n";
    return 0;
} //end main

    //printNodes();


void setUp() 
{
    head->studentID = 1;
    head->classID = 1;

    head->nextStudent = nullptr;
    head->nextClass = nullptr;
}

void menu()
{
    setUp();

    std::cout << "Please choose what you would like to do from the following menu:\n";
    std::cout << "1- Add a node\n";
    std::cout << "2- add a grade to an existence node\n";
    std::cout << "3- Print all the nodes\n";
    std::cout << "4- Exit\n\n";
}

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

bool findNode(int stdNum, int clssNum)
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

/*int getStdGrade(int stdNum)
{
    pointer1 = head;

    while(pointer1->nextStudent != nullptr) 
    {

    }
}*/

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

/*#include "Node.h"
#include <cmath>

void setUp();
void insertStudentNode(int);   //Adds a student element node
void insertElementNode(int, int);
bool findStudent(int);  //Finds if a node with the given index exist
bool findNode(int, int);
int getStdGrade(int);  //returns the grade of the given student
void addGrade(int, int);    //assigns a grade to the given student node
void printNodes();
Node* getStdNode(int);
void addGrade(int, int, int);

    Node *head = new Node();
    Node *temp1 = new Node();
    Node *pointer1 = new Node();
    Node *pointer2 = new Node();

int main() {
    
    int stdNum = 1;
    int clssNum = 1;
    int gradeChoice = 1;

    setUp();

    while(stdNum != 0) 
    {
        std::cout << "Enter a student's number and a class number to add (enter zero for both to exit): \n";
        std::cin >> stdNum;
        std::cin >> clssNum;
        if((stdNum == 0) || (clssNum == 0)) 
            break;
        if(findStudent(stdNum))
        {
            if(findNode(stdNum, clssNum))
            {
                std::cout << "Node has been Found\n";
                std::cout << "Would you like to input a grade? (enter 1 for yes and 0 for no)\n";
                std::cin >> gradeChoice;
                if(gradeChoice == 1)
                {
                    std::cout << "What grade would you like to input? (Enter a number between 0 and 100): \n";
                    std::cin >> gradeChoice;
                    if((gradeChoice < 0) || (gradeChoice > 100))
                    {
                        std::cout << "Invalid Input\n";
                        continue;
                    }
                    addGrade(stdNum, clssNum, gradeChoice);
                    std::cout << "Grade has been added\n";
                    continue;
                }
            }
            insertElementNode(stdNum, clssNum);
            std::cout << "Node has been added\n";
            continue;
        }
        insertStudentNode(stdNum);
        insertElementNode(stdNum, clssNum);
        std::cout << "Node has been created!\n";
    } //end while

    printNodes();

    delete pointer1;
    std::cout << "\n";
    return 0;
}

void setUp() 
{
    head->studentID = 1;
    head->classID = 1;

    head->nextStudent = nullptr;
    head->nextClass = nullptr;
}

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

bool findNode(int stdNum, int clssNum)
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

/*int getStdGrade(int stdNum)
{
    pointer1 = head;

    while(pointer1->nextStudent != nullptr) 
    {

    }
}//

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
} //end printNodes*/