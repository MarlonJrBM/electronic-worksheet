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

