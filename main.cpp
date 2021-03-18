#include "Node.h"
#include "setUp.h"
#include "addGrade.h"
#include "findNode.h"
#include "findStudent.h"
#include "getNodeGrade.h"
#include "getStdNode.h"
#include "globalVariables.h"
#include "insertElementNode.h"
#include "insertStudentNode.h"
#include "printNodes.h"

#include <cmath>

int main() {
    
    int stdNum;
    int clssNum;
    int gradeChoice = 1;
    int userChoice = 0;
    bool keepGoing = true;

    setUp();

    while(keepGoing) 
    {
        std::cout << "\nPress 1 to insert a node \tPress 2 to enter a grade\tPress 3 to get a grade from an existing node\tPress 4 to print all nodes\tPress 5 to exit\n";
        std::cin >> userChoice;
        if(userChoice == 1) 
        {
            std::cout << "Enter a student's number and a class number to add: \n";
            std::cin >> stdNum;
            std::cin >> clssNum;
            if(findStudent(stdNum))
            {
                if(findNode(stdNum, clssNum))
                {
                    std::cout << "Node already exist\n";
                    continue;
                }
                insertElementNode(stdNum, clssNum);
                std::cout << "Class node has been added to the student\n";
            }
            else 
            {
                insertStudentNode(stdNum);
                insertElementNode(stdNum, clssNum);
                std::cout << "Node has been created\n";
            }
        }
        else if(userChoice == 2)
        {
            std::cout << "Enter a student's number and a class number to add grade for: \n";
            std::cin >> stdNum;
            std::cin >> clssNum;
            if(findStudent(stdNum) && findNode(stdNum, clssNum))
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
            std::cout << "Node does not exist\n";
        }
        else if(userChoice == 3)
        {
            std::cout << "Enter student's number and class number:\n";
            std::cin >> stdNum;
            std::cin >> clssNum;
            if(findStudent(stdNum) && findNode(stdNum, clssNum))
            {
                if(getNodeGrade(stdNum, clssNum) == 0)
                {
                    std::cout << "No grade was found for the student in this class!\n";
                }
                else 
                {
                    std::cout << "Grade: " << getNodeGrade(stdNum, clssNum) << std::endl;
                } //end else
            } //end if
        }  //end else if  
        else if(userChoice == 4)
        {
            printNodes();
            continue;
        }
        else {
            break;
        }
    } //end while

    delete pointer1;
    std::cout << "\n";
    return 0;
}