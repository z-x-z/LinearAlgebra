//
// Created by zxz on 2019/12/11.
//

#include "LAlgorithm.h"

Vector LAlgorithm::solveLinearEquation(Matrix& A, Vector& b)
{
    return Vector(0);
}

Vector LAlgorithm::leastSquaresMethod(Matrix& A, Vector& b)
{
    return (A * A.transpose(), b);
}
