/* 
 * File:   main.cpp
 * Author: marlon
 *
 * Created on March 7, 2014, 5:13 PM
 */

#include "Matriz.h"



/*This is a prototype for the Persistence Module for the Electronic Spreadsheet
 * In the main function are a couple of tests for it. If anything goes wrong, an
 * exception of type const char will be thrown
 */
int main(int argc, char** argv) {
    Matriz matrix(5,4), matrix2(20,20); //default is 10x10
    string fileName = "outputTest.csv";
    string values[] = {"Hello World", "I am the Walrus", "", "Love, Hate, Love"};
    string again[] = {"Let it Bleed", "You Can't Always Get What You Want", "", "Monkey Man"};
    cout << "Creating Matrix. Initial capacity: " << endl;
    cout << matrix.getMaxNumLine() << 'x' << matrix.getMaxNumCol() <<  endl;
    cout << matrix(1,1) << endl;
    
 
    
    cout << "Now Adding Values..." << endl;
    for (int ii=0; ii<4; ii++)
    {
        matrix.addValue(values[ii]);
        matrix.addValue(again[ii]);
        matrix.addValue(values[ii]);
        matrix.addValue(again[ii]);
    }
    cout << "Values Added to Vector" << endl;
    cout << "Number of lines filled: " << matrix.getNumLine() << endl;
    
    
  
    
    cout << "Now Writing Values to file 'outputTest.csv'" << endl;
    matrix.writeFile(fileName);
    cout << "File was written" << endl;
    
    
    
    cout << "Now Reading Values from the file 'outputTest.csv'" << endl;
    matrix2.readFile(fileName);
    cout << "File was read" << endl;
    
    
     
    
    cout << "Trying to access value at pos [2,3]:" << endl;
    cout << matrix(2,3) << endl;
    cout << "It worked!" << endl;
    
    cout << "Trying to set value at pos [2,3]:" << endl;
    matrix(2,3) = "Let it bleed";
    cout << matrix(2,3) << endl;
    cout << "It worked!" << endl;
    
    cout << "Trying to access value at pos [3,3]" << endl;
    cout << matrix(3,3) << endl;
    cout << "It worked!" << endl;
    
    cout << "Trying to set value at pos [3,3]:" << endl;
    matrix(3,3) = "Midnight Rambler";
    cout << matrix(3,3) << endl;
    cout << "It worked!" << endl;
    
    
    cout << "Trying to resize the matrix..." << endl;
    cout << "Current number of lines: " << matrix.getMaxNumLine() << endl;
    cout << "Current number of columns: " << matrix.getMaxNumCol() << endl;
    matrix.growMatrix(1,2);
    cout << "Performing resizeMatrix(1,1)... " << endl;
    cout << "Number of lines afterwards " << matrix.getMaxNumLine() << endl;
    cout << "Number of columns afterwards " << matrix.getMaxNumCol() << endl;
    
    matrix(5,5) = "BLAAAH";
    cout << matrix(5,5) << endl;
    
    
    cout << "Trying to resize the matrix..." << endl;
    cout << "Current number of lines: " << matrix.getMaxNumLine() << endl;
    cout << "Current number of columns: " << matrix.getMaxNumCol() << endl;
    matrix.shrinkMatrix(1,1);
    cout << "Performing resizeMatrix(1,1)... " << endl;
    cout << "Number of lines afterwards " << matrix.getMaxNumLine() << endl;
    cout << "Number of columns afterwards " << matrix.getMaxNumCol() << endl;
    
   //-----------------------------------------------------------------------
   //---------- getSubMatrix ----------------------------------------------
   
    Matriz matriz3(matrix.getSubMatrix(1,2,3,0));
    matriz3(0,0) = "VSF";
    cout << matrix(1,2) << endl;
    cout << matriz3(0,0) << endl;
    cout << matriz3.getMaxNumLine() << endl;
    cout << matriz3.getMaxNumCol() << endl;

    
    Matriz mm(5,6);
   
    
    return 0;
}

