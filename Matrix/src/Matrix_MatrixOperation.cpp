//
// Created by zxz on 2019/12/5.
//

#include "Matrix.h"

// static
Matrix Matrix::matAdd(const class Matrix& m1, const class Matrix& m2)
{
    return m1.matAdd(m2);
}

Matrix Matrix::matSub(const class Matrix& m1, const class Matrix& m2)
{
    return m1.matSub(m2);
}

Matrix Matrix::matMul(const class Matrix& m1, const class Matrix& m2)
{
    return m1.matMul(m2);
}

Matrix Matrix::matDiv(const class Matrix& m1, const class Matrix& m2)
{
    return m1.matDiv(m2);
}


Matrix Matrix::transpose(const class Matrix & m)
{
    return m.transpose();
}


// local
Matrix Matrix::matAdd(const class Matrix& m2) const
{
    Matrix m(r, c);
    for(int i = 0; i < m.r; ++i)
    {
        for(int j = 0; j < m.c; ++j)
        {
            m._Matrix[i][j] = _Matrix[i][j] + m2._Matrix[i][j];
        }
    }
    return m;

}

Matrix Matrix::matSub(const class Matrix& m2) const
{
    Matrix m(r, c);
    for(int i = 0; i < m.r; ++i)
    {
        for(int j = 0; j < m.c; ++j)
        {
            m._Matrix[i][j] = _Matrix[i][j] - m2._Matrix[i][j];
        }
    }
    return m;
}

Matrix Matrix::matMul(const class Matrix& m2) const
{
    Matrix m(r, m2.c);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < m.c; ++j)
        {
            double d = 0;
            for(int k = 0; k < c; ++k)
            {
                d += _Matrix[i][k] * m2._Matrix[k][j];
            }
            m._Matrix[i][j] = d;
        }
    }
    return m;
}

Matrix Matrix::matDiv(const class Matrix& m2) const
{
    Matrix m = this->matMul(this->inverse());
    return m;
}


Matrix Matrix::transpose() const
{
    Matrix m(c, r);
    for(int i = 0; i < c; ++i)
    {
        for(int j = 0; j < r; ++j)
        {
            m._Matrix[i][j] = _Matrix[j][i];
        }
    }
    return m;
}
