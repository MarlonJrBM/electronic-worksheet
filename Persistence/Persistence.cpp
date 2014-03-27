/* 
 * File:   Persistence.cpp
 * Author: marlon
 * 
 * Created on March 7, 2014, 5:26 PM
 */

#include "Persistence.h"

Persistence::Persistence(int numLin, int numCol) {
    vector<string> v(numCol,"");
    values.resize(numLin,v); //Allocates lines of the matrix
//    for (int ii=0;ii<numLin;ii++)
//        //Allocates columns of the matrix
//    {
//        values[ii].resize(numCol, "");
//    }
    numLines = 0;
    numCols.resize(numLin, 0);
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
    return numCols[numLin];
}

int Persistence:: getMaxNumLine()
{
    return values.size();
    
}

int Persistence:: getMaxNumCol()
{
    return values[0].size();
    
}

void Persistence::readFile(string fileName, bool header)

{
    ifstream file(fileName.c_str());
    string currLine, currWord;
    
    if (!header)
    {
        



        while (getline(file,currLine))
            
        {

            processStringForRead(currLine);
            //TODO- Refactor this method and the ones it calls. 
            //This is doing a lot of repeated work. 
            //Perhaps adding a count variable to keep track of the
            //current line will avoid this unnecessary load of work
        }
    
    }
    else
    {
        //TODO - Implement logic for file with header (indicating a complex table)
        
    }
    
    
    
    file.close();
    
}

void Persistence::writeFile(string fileName, bool header)
{
    
    ofstream file(fileName.c_str());
    string currWord;
    
    if (!header)
    {
    
        for (int ii=0;ii<getMaxNumLine();ii++)
        {
            for (int jj=0;jj<getMaxNumCol();jj++)
            {
                currWord = values[ii][jj];
                file << processStringForWrite(currWord) << ',';
            }
            if (ii<getMaxNumLine()-1)file << '\n'; //starts a new line in the output file,
            //if this is not the last line
        }
    }
    else
    {
        //TODO - Implement logic for file with header (indicating a complex table)
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

void Persistence::processStringForRead(string line)
{
    
    //TODO - Two quotes together should be parsed as a quotation mark, not as
    // the end or beginning a string
    
    string word;
    int foundPos;
    bool isDone = false;
    
    while (!isDone)
    {
    
        if (line[0]=='\"')
        //If the word starts with double quotes, then we must find
        //the next double quotes followed by a comma
        {     
                foundPos = line.find("\",", 1);
                word = line.substr(1, foundPos-1 ); //extracts the word
                if (foundPos!=line.length()-2)
                //Here we are checking to see if this is the last word in the line.
                //If it is, time to stop the while loop.
                //This is a workaround to avoid an exception being thrown and caught. 
                //There probably is a better way to do it
                line = line.substr(foundPos+2 ); //Removes the current word from the string
                //and continues to process it
                else
                isDone = true;
        }
        else
                //No quotes around the word. In this case, just search for the next comma
        {
                foundPos = line.find(',');
                word = line.substr(0,foundPos);
                if (foundPos!=line.length()-1)
                //Same workaround as above
                line = line.substr(foundPos+1);
                else
                isDone = true;
        }
    
        cout << "Element being added: " << word << endl;
        addValue(word); //Finally adds the value to the matrix
    }
    
}

void Persistence::addValue(string value)
{
    bool foundPos = false;
    int ii=0, jj;
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
            jj = getNumCol(ii); 
            //gets reference to the number of elements in the current line
            //If this is the first element of the new line, then we must
            //increment the size of the vector (which represent the lines)
            if (jj==0) 
                numLines++;
            values[ii][jj] = value ;
            numCols[ii]++; //we have a new element in the line, so the variable
            //must be updated
            foundPos = true;
        }
    }
}


void Persistence::growMatrix(int d_i, int d_j)
{
    vector<string> newLine(getMaxNumCol() + d_j,"");
    
    if (d_j>0)
    {
    
    for (int ii=0;ii<getMaxNumLine();ii++)
        //adds more columns to the old lines
    {
        for (int jj=0;jj<d_j;jj++)
        {
            values[ii].push_back("");
            //numCols[ii]++;      
        }
    }
    }
    
    for (int ii=0;ii<d_i;ii++)
        //adds new lines (with right number of columns)
    {
        values.push_back(newLine);
        
    }
          
}

void Persistence::shrinkMatrix(int d_i, int d_j)
{
    int numCol = getMaxNumCol();
    
    if (d_j>0)
        //removes the columns
    {
        for (int ii=0;ii<getMaxNumLine();ii++)
            
        {
            values[ii].resize(numCol-d_j);
            numCols[ii]-=d_j;
        }
    }
    
    if (d_i>0) 
    {
        values.resize(getMaxNumLine()-d_i);
        numLines-=d_i;
    }
    
    
    
    
    
}



bool Persistence::isLineFull(int linNum)
{
    //The number of elements in a line should never be greater than the 
    //Number of Columns allocated. Just putting this as an insanity check!
    return (getNumCol(linNum) >= getMaxNumCol());
}


string& Persistence::operator ()(int line, int column)
{
    return values[line][column];
}

