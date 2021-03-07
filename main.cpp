#include "Node.h"
#include <cmath>

void setUp();
//int getNodeNum();
void insertNode(int);   //Adds a student element node
bool findStudent(int);  //Finds if a node with the given index exist
int studentGrade(int);  //returns the grade of the given student
void addGrade(int, int);    //assigns a grade to the given student node
void printNodes();

    Node *head = new Node();
    Node *second = new Node();
    Node *pointer = new Node();

int main() {
    
    int choice = 1;
    int gradeChoice = 1;

    setUp();

    while((choice != 0) || (gradeChoice != 0)) 
    {
        std::cout << "Enter a student's number (and zero to exit): \n";
        std::cin >> choice;
        if(choice == 0) {
            break;
        }
        if(findStudent(choice))
        {
            std::cout << "student has been found!\n";
            std::cout << "student's grade is: " << studentGrade(choice) << std::endl;
        }
        else 
        {
            insertNode(choice);
            std::cout << "student has been added!\n";
            std::cout << "Enter student's grade (and zero to exit): \n";
            std::cin >> gradeChoice;
            if(gradeChoice == 0) {
                break;
            }
            addGrade(choice, gradeChoice);
            std::cout << "student's grade has been added\n\n";
        }
    } //end while

    printNodes();

    std::cout << "\n";
    return 0;
}

void setUp() 
{
    head->studentID = 1;
    head->nextStudent = nullptr;
}

/*int getNodeNum() 
{
    int nodesNum = 0;

    pointer = head;
    while(pointer->nextStudent != nullptr) {
        pointer = pointer->nextStudent;
        nodesNum++;
    }
    return (nodesNum + 1);
}*/

bool findStudent(int choice) 
{
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        if(pointer->studentID == choice) {
            return true;
        }
        pointer = pointer->nextStudent;
    }
    if(pointer->studentID == choice) {
        return true;
    }
    return false;
}

void insertNode(int choice) 
{
    Node *newNode = new Node();
    Node *temp1 = new Node();
    Node *temp2 = new Node();

    pointer = head;

    while(pointer->nextStudent != nullptr)
    {
        if(choice < pointer->studentID)
        {
            temp1->nextStudent = newNode;
            newNode->nextStudent = pointer;

            newNode->studentID = choice;
            return;
        }
        else 
        {
            temp1 = pointer;
            pointer = pointer->nextStudent;
        }
    }

    if(choice < pointer->studentID)
    {
        temp1->nextStudent = newNode;
        newNode ->nextStudent = pointer;
    }
    else {
        pointer->nextStudent = newNode;
        newNode->nextStudent = nullptr;
    }

    newNode->studentID = choice;
}

void addGrade(int choice, int gradeChoice)
{
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        if(pointer->studentID == choice) {
            pointer->grade = gradeChoice;
            return;
        }
        pointer = pointer->nextStudent;
    }
    pointer->grade = gradeChoice;
}

int studentGrade(int choice)

{
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        if(pointer->studentID == choice) {
            return pointer->grade;
        }
        pointer = pointer->nextStudent;
    }
    return pointer->grade;
}

void printNodes() 
{
    pointer = head;

    while(pointer ->nextStudent != nullptr) 
    {
        std::cout << pointer->studentID << std::endl;
        pointer = pointer->nextStudent;
    }
    std::cout << pointer->studentID << std::endl;
}