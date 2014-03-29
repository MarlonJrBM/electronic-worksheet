/* 
 * File:   Matriz.cpp
 * Author: Marlon
 * 
 * Created on 29 de Março de 2014, 19:02
 */

#include "Matriz.h"

Matriz::Matriz(int n, int m) : Persistence(n,m) {
}

Matriz::Matriz(const Matriz& orig) {
}

Matriz::~Matriz() {
}

int Matriz::getNumberofRows()
{
    return values.size();
}

int Matriz::getNumberofColumns()
{
    return values[0].size();
}

string Matriz::getMatrixCell(int i, int j)
{
    return values[i][j];
}

void Matriz::setMatrixCell(int i, int j, string data)
{
    values[i][j] = data; 
}

Matriz Matriz::getSubMatrix(int i_0, int j_0, int i, int j)
{
    if (i<i_0) swap(i, i_0);
    if (j<j_0) swap(j, j_0);
    
    Matriz subMatrix(i-i_0 + 1, j-j_0 + 1);
    
    for (int ii=i_0;ii<=i;ii++)
    {
        for (int jj=j_0;jj<=j;jj++)
        {
            subMatrix.addValue(values[ii][jj]);
        }
    }
    
    return subMatrix;
}