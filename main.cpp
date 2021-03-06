#include "Node.h"
#include <cmath>

void setUp();
void indexNodes();
int getNodeNum();
void addElement(int);
bool findStudent(int);
int studentGrade(int);
void addGrade(int, int);

    Node *head = new Node();
    Node *second = new Node();
    Node *pointer = new Node();

int main() {
    
    int choice = 1;
    int gradeChoice = 1;

    setUp();

    std::cout << "Enter a student's number: \n";

    while((choice != 0) || (gradeChoice != 0)) 
    {
        std::cin >> choice;
        if(findStudent(choice))
        {
            std::cout << "student has been found!\n";
            std::cout << "student's grade is: " << studentGrade(choice) << std::endl;
        }
        else 
        {
            addElement(choice);
            std::cout << "student has been added!\n";
            std::cout << "Enter student's grade: \n";
            std::cin >> gradeChoice;
            addGrade(choice, gradeChoice);
            std::cout << "student's grade has been added\n";
        }
    }
    std::cout << "\n";
    return 0;
}

void setUp() {
    head->nextStudent = nullptr;
    indexNodes();
}

void indexNodes() {
    int index = 1;
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        pointer->studentID = index++;
        pointer = pointer->nextStudent;
    }
    pointer->studentID = index;
}

//returns the number of existing nodes
int getNodeNum() {
    int nodesNum = 0;

    pointer = head;
    while(pointer->nextStudent != nullptr) {
        pointer = pointer->nextStudent;
        nodesNum++;
    }
    return (nodesNum + 1);
}

void addElement(int choice) {
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        pointer = pointer->nextStudent;    //Find the last node
    } 

    Node *newNode = new Node();
    newNode = pointer;
    pointer = new Node();
    newNode->nextStudent = pointer;
    pointer->nextStudent = nullptr;

    newNode->studentID = choice;
}

bool findStudent(int choice) {
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

void addGrade(int choice, int gradeChoice)
{
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        if(pointer->studentID == choice) {
            pointer->grade = gradeChoice;
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