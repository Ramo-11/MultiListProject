#include "findNode.h"
#include "getStdNode.h"

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