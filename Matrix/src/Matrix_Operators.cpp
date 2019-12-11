//
// Created by zxz on 2019/12/7.
//
#include "Matrix.h"

double* Matrix::operator[](int row) const
{
    return _Matrix[row];
}

Matrix& Matrix::operator=(const class Matrix& m)
{
    // 先检查自我赋值
    if(this != &m)
    {
        this->newMatrix(m.r, m.c);
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                _Matrix[i][j] = m._Matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const class Matrix& m) const
{
    return this->matAdd(m);
}

Matrix Matrix::operator-(const class Matrix& m) const
{
    return this->matSub(m);
}

Matrix Matrix::operator*(const class Matrix& m) const
{
    return this->matMul(m);
}

Matrix Matrix::operator/(const class Matrix& m) const
{
    return this->matDiv(m);
}

Matrix Matrix::operator^(int n) const
{
    Matrix m = *this;
    for(int i = 0; i < n - 1; ++i)
    {
        m = m * (*this);
    }
    return m;
}
