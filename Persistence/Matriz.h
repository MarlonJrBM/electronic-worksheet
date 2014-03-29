/* 
 * File:   Matriz.h
 * Author: Marlon
 *
 * Created on 29 de Março de 2014, 19:02
 */

#ifndef MATRIZ_H
#define	MATRIZ_H

#include "Persistence.h"

class Matriz: public Persistence {
public:
    Matriz(int n, int m);
    Matriz(const Matriz& orig);
    virtual ~Matriz();
    int getNumberofRows();
    int getNumberofColumns();
    string getMatrixCell(int i, int j);
    void setMatrixCell(int i, int j, string data);
    void resizeMatrix(int d_i, int d_j);
    Matriz getSubMatrix(int i_0, int j_0, int i, int j);
    
private:

};

#endif	/* MATRIZ_H */

