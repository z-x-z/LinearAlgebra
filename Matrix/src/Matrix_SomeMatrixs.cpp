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
