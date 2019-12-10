//
// Created by zxz on 2019/12/7.
//
#include <random>
#include "Matrix.h"

Matrix Matrix::identity(int n)
{
    Matrix In(n, 0.0);
    for(int i = 0; i < n; ++i)
    {
        In._Matrix[i][i] = 1.0;
    }
    return In;
}

Matrix Matrix::random(int n)
{
    return randMatrix_T(n, 0, 1.0);
}

Matrix Matrix::random(int r, int c)
{
    return randMatrix_T(r, c, 0, 1.0);
}

Matrix Matrix::randMatrix_T(int n, Matrix_T begin, Matrix_T end)
{
    return randMatrix_T(n,n,begin, end);
}

Matrix Matrix::randMatrix_T(int r, int c, Matrix_T begin, Matrix_T end)
{
    Matrix m(r, c);
    std::default_random_engine generator(time(0));
    std::uniform_real_distribution<Matrix_T> distribution(begin, end);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            m._Matrix[i][j] = distribution(generator);
        }
    }
    return m;
}


Matrix Matrix::randInt(int n, int begin, int end)
{
    return randInt(n, n, begin, end);
}

Matrix Matrix::randInt(int r, int c, int begin, int end)
{
    Matrix m(r, c);
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(begin, end);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            m._Matrix[i][j] = distribution(generator);
        }
    }
    return m;
}