//
// Created by zxz on 2019/12/5.
//

#include "Matrix.h"

void Matrix::add(double d)
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            _Matrix[i][j] = _Matrix[i][j] + d;
        }
    }
}

void Matrix::sub(double d)
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            _Matrix[i][j] = _Matrix[i][j] - d;
        }
    }
}

void Matrix::mul(double d)
{

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            _Matrix[i][j] = _Matrix[i][j] * d;
        }
    }
}

void Matrix::div(double d)
{

    mul(1 / d);
}

void Matrix::rowAdd(int row, Matrix_T d)
{
    for(int i = 0; i < c; ++i)
    {
        _Matrix[row][i] += d;
    }
}

void Matrix::rowSub(int row, Matrix_T d)
{
    for(int i = 0; i < c; ++i)
    {
        _Matrix[row][i] -= d;
    }
}


void Matrix::rowMul(int row, Matrix_T d)
{
    for(int i = 0; i < c; ++i)
    {
        _Matrix[row][i] *= d;
    }
}

void Matrix::rowDiv(int row, Matrix_T d)
{
    rowMul(row, 1 / d);
}

void Matrix::rowExchange(int i, int j)
{
    Matrix_T tmp = 0;
    for(int k = 0; k < c; ++k)
    {
        tmp = _Matrix[i][k];
        _Matrix[i][k] = _Matrix[j][k];
        _Matrix[j][k] = tmp;
    }
}

void Matrix::colExchange(int i, int j)
{
    Matrix_T tmp = 0;
    for(int k = 0; k < r; ++k)
    {
        tmp = _Matrix[k][i];
        _Matrix[k][i] = _Matrix[k][j];
        _Matrix[k][j] = tmp;
    }
}