//
// Created by zxz on 2019/12/11.
//

#ifndef CPP_HEAD_FILES_LALGORITHM_H
#define CPP_HEAD_FILES_LALGORITHM_H

#include "../../Matrix/src/Matrix.h"
#include "../../Vector/src/Vector.h"

class LAlgorithm
{
    // Solve the linear equation of Ax = b
    static Vector solveLinearEquation(Matrix& A, Vector& b);

    static Vector leastSquaresMethod(Matrix& A, Vector& b);

};


#endif //CPP_HEAD_FILES_LALGORITHM_H
