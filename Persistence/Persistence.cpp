/* 
 * File:   Persistence.cpp
 * Author: marlon
 * 
 * Created on March 7, 2014, 5:26 PM
 */

#include "Persistence.h"

Persistence::Persistence(int numLin, int numCol) {
    values.reserve(numLin); //Allocates lines of the matrix
    for (int ii=0;ii<numLin;ii++)
        //Allocates columns of the matrix
    {
        values[ii].reserve(numCol);
    }
}

Persistence::Persistence(const Persistence& orig) {
}

Persistence::~Persistence() {
}

int Persistence:: getNumLin()
{
    return values.size();
}

int Persistence:: getNumCol(int numLin)
{
    return values[numLin].size();
}

int Persistence:: getLinCap()
{
    return values.capacity();
    
}

int Persistence:: getColCap()
{
    return values[0].capacity();
    
}