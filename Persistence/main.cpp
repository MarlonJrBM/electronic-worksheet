/* 
 * File:   main.cpp
 * Author: marlon
 *
 * Created on March 7, 2014, 5:13 PM
 */

#include "Persistence.h"



/*
 * 
 */
int main(int argc, char** argv) {
    Persistence matrix; //default is 10x10
    string fileName = "outputTest.csv";
    string values[] = {"Hello World", "I am the Walrus", "", "Love, Hate, Love"};
    string again[] = {"Let it Bleed", "You Can't Always Get What You Want", "", "Monkey Man"};
    cout << "Creating Matrix. Initial capacity: " << endl;
    cout << matrix.getMaxNumLine() << 'x' << matrix.getMaxNumCol() <<  endl;
    
    cout << "Now Adding Values..." << endl;
    for (int ii=0; ii<4; ii++)
    {
        matrix.addValue(values[ii]);
        matrix.addValue(again[ii]);
        matrix.addValue(values[ii]);
        matrix.addValue(again[ii]);
        matrix.addValue(again[ii]);
        matrix.addValue(values[ii]);
        matrix.addValue(again[ii]);
    }
    cout << "Values Added to Vector" << endl;
    cout << "Number of lines filled: " << matrix.getNumLine() << endl;
    
    
    cout << "Now Writing Values to file 'outputTest.csv'" << endl;
    matrix.writeFile(fileName);
    cout << "File was written" << endl;
    
    return 0;
}

