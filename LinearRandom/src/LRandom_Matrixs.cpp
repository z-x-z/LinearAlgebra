//
// Created by zxz on 2019/12/11.
//
#include "LRandom.h"

Matrix LRandom::randMatrix(int r, int c, Matrix_T begin, Matrix_T end)
{
    Matrix m(r, c);
    std::uniform_real_distribution<Matrix_T> distribution(begin, end);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            m[i][j] = distribution(generator);
        }
    }
    return m;
}

Matrix LRandom::randMatrix(int n, Matrix_T begin, Matrix_T end)
{
    return randMatrix(n, n, begin, end);
}


Matrix LRandom::randIntMatrix(int n, int begin, int end)
{
    return randIntMatrix(n, n, begin, end);
}

Matrix LRandom::randIntMatrix(int r, int c, int begin, int end)
{
    Matrix m(r, c);
    std::uniform_int_distribution<int> distribution(begin, end);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            m[i][j] = distribution(generator);
        }
    }
    return m;
}

