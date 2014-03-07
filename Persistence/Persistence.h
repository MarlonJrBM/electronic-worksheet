/* 
 * File:   Persistence.h
 * Author: marlon
 *
 * Created on March 7, 2014, 5:26 PM
 */

#ifndef PERSISTENCE_H
#define	PERSISTENCE_H


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Persistence {
public:
    Persistence(int numLin=10, int numCol=10);
    Persistence(const Persistence& orig);
    virtual ~Persistence();
    //Returns number of non-empty lines on the Matrix
    int getNumLin();
    //Returns number of non-empty columns at specified lines
    int getNumCol(int numLin=0);
    //Returns number of allocated lines
    int getLinCap();
    //Returns number of allocated columns
    int getColCap();
    
private:
    
    vector <vector<string> > values;
    
    

};

#endif	/* PERSISTENCE_H */

