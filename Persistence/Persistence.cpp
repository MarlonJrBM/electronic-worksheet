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
    numLines = 0;
}

Persistence::Persistence(const Persistence& orig) {
}

Persistence::~Persistence() {
}

int Persistence:: getNumLine()
{
    return numLines;
}

int Persistence:: getNumCol(int numLin)
{
    return values[numLin].size();
}

int Persistence:: getMaxNumLine()
{
    return values.capacity();
    
}

int Persistence:: getMaxNumCol()
{
    return values[0].capacity();
    
}

void Persistence::readFile(string fileName)
{
    ifstream file(fileName.c_str());
    
    
    
    
    
    file.close();
    
}

void Persistence::writeFile(string fileName)
{
    ofstream file(fileName.c_str());
    string currWord;
    
    for (int ii=0;ii<getNumLine();ii++)
    {
        for (int jj=0;jj<getNumCol(ii);jj++)
        {
            currWord = values[ii][jj];
            file << processStringForWrite(currWord) << ',';
        }
        file << '\n'; //starts a new line in the output file
    }
    
    
    
    file.close();
    
}


string Persistence::processStringForWrite(string line)
{
    string result;
    
    if (line.find(',') != NOT_FOUND)
        //there is a comma in the string. Therefore, the string must be
        //put between quotes
    {
        result = '\"' + line + '\"';
    }
    else
        //otherwise, the string need not be quoted
        result = line;
    
     
    
    return result;
}

void Persistence::addValue(string value)
{
    bool foundPos = false;
    int ii=0;
    while (!foundPos)
        //iterates through the lines to find if there is enough room
    {
        if (isLineFull(ii))
            //This line is full
        {
            if (ii==getMaxNumLine()-1)
                //there are no more lines, we have a problem Houston!
            {
                throw "Matrix is fully loaded. Cannot add another value.";
            }
            ii++;
            
        }
        else
            //this line is not full, push the element to the vector
        {
            //If this is the first element of the new line, then we must
            //increment the count variable. (This is a workaround for a potential
            //hazard for this application)
            if (getNumCol(ii)==0) 
                numLines++;
            values[ii].push_back(value);
            foundPos = true;
        }
    }
}

bool Persistence::isLineFull(int linNum)
{
    //The number of elements in a line should never be greater than the 
    //Number of Columns allocated. Just putting this as an insanity check!
    return (getNumCol(linNum) >= getMaxNumCol());
}