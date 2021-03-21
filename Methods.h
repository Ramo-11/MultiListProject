#ifndef METHODS_H
#define METHODS_H

#include "Node.h"

class Methods
{
    public:
        Node* head;
        Node* temp1;
        Node* pointer1;
        Node* pointer2;

        Methods();
        ~Methods();

        void setUp();
        void addGrade(int, int, int); 
        bool findNode(int, int);
        bool findStudent(int);
        int getNodeGrade(int, int);

        Node* getStdNode(int);
        void insertElementNode(int, int);
        void insertStudentNode(int);
        void printNodes();
};
#endif