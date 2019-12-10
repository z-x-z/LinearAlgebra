//
// Created by zxz on 2019/12/5.
//

#include "Matrix.h"


Matrix::~Matrix()
{
    for(int i = 0; i < r; i++)
    {
        delete _Matrix[i];
    }
    delete _Matrix;
    r = -1;
    c = -1;
}

Matrix::Matrix(int row, int col): r(row),  c(col)
{
    _Matrix = new double* [row];
    for(int i = 0; i < r; i++)
    {
        _Matrix[i] = new double[c];
    }
}

Matrix::Matrix(int row, int col, double init): r(row),  c(col)
{
    _Matrix = new double* [r];
    for(int i = 0; i < r; i++)
    {
        _Matrix[i] = new double[c];
        for(int j = 0; j < c; j++)
        {
            _Matrix[i][j] = init;
        }
    }
}

Matrix::Matrix(int n): r(n),  c(n)
{
    _Matrix = new double* [r];
    for(int i = 0; i < n; i++)
    {
        _Matrix[i] = new double[c];
    }
}

Matrix::Matrix(int n, double init): r(n),  c(n)
{
    _Matrix = new double* [r];
    for(int i = 0; i < r; i++)
    {
        _Matrix[i] = new double[c];
        for(int j = 0; j < c; j++)
        {
            _Matrix[i][j] = init;
        }
    }
}

Matrix Matrix::copy() const
{
    Matrix m(r, c);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            m._Matrix[i][j] = _Matrix[i][j];
        }
    }
    return m;
}


int Matrix::getRow()
{
    return r;
}

int Matrix::getCol()
{
    return c;
}


int Matrix::Matrix_T_to_int(Matrix_T t)
{
    int it = (int) t;
    if(t > 0 && t - it > MATRIX_T_ZERO)
    {
        return 1 + it;
    }
    else if(t < 0 && it - t > MATRIX_T_ZERO)
    {
        return -1 + it;
    }
    return it;
}

Vector Matrix::getColVector(int col)
{
    Vector colArray(r);
    for(int i = 0; i < r; ++i)
    {
        colArray[i] = _Matrix[i][col];
    }
    return colArray;
}

Vector Matrix::getArrayByColOrder()
{
    Vector array(r * c);
    for(int j = 0; j < c; ++j)
    {
        for(int i = 0; i < r; ++i)
        {
            array[i + j * r] = _Matrix[i][j];
        }
    }
    return array;
}

Vector Matrix::getRowVector(int row)
{
    Vector colArray(c);
    for(int i = 0; i < c; ++i)
    {
        colArray[i] = _Matrix[row][i];
    }
    return colArray;
}

Vector Matrix::getArrayByRowOrder()
{
    Vector array(r * c);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            array[j + i * c] = _Matrix[i][j];
        }
    }
    return array;
}


Matrix Matrix::getMatrixByArray(int row, int col, const double* array)
{
    Matrix m(row, col);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            // 注意此处i乘的是col
            m._Matrix[i][j] = array[j + i * col];
        }
    }
    return m;
}

class Matrix Matrix::getMatrixByArray(int n, const double* array)
{
    return getMatrixByArray(n, n, array);
}


class Matrix Matrix::getReshapeByRow(int row, int col)
{
    Matrix reshape(row, col);
    int num;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            num = row * i + j;
            reshape._Matrix[i][j] = _Matrix[num / row][num % row];
        }
    }
    return reshape;
}

class Matrix Matrix::getReshapeByCol(int row, int col)
{
    Matrix reshape(row, col);
    int num;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            num = row * i + j;
            reshape._Matrix[i][j] = _Matrix[num % col][num / col];
        }
    }
    return reshape;
}

/// set
void Matrix::setRowVector(int row, Vector rowVector)
{
    for(int i = 0; i < c; ++i)
    {
        _Matrix[row][i] = rowVector[i];
    }
}

void Matrix::setColVector(int col, Vector colVector)
{
    for(int i = 0; i < r; ++i)
    {
        _Matrix[i][col] = colVector[i];
    }
}

