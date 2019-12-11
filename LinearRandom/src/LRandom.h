//
// Created by zxz on 2019/12/11.
//

#ifndef CPP_HEAD_FILES_LRANDOM_H
#define CPP_HEAD_FILES_LRANDOM_H

#include <random>
#include <ctime>
#include "../../Matrix/src/Matrix.h"
#include "../../Vector/src/Vector.h"


class LRandom
{
private:
    std::default_random_engine generator;
public:
    explicit LRandom(time_t t = time(nullptr));

    /// Random Matrix [begin, end]
    Matrix randMatrix(int n, Matrix_T begin = 0, Matrix_T end = 1);

    Matrix randMatrix(int r, int c, Matrix_T begin = 0, Matrix_T end = 1);

    Matrix randIntMatrix(int n, int begin, int end);

    Matrix randIntMatrix(int r, int c, int begin, int end);

    /// Random Vector [begin, end]
    Vector randVector(int length, Vector_T begin = 0, Vector_T end = 1);

    Vector randIntVector(int length, int begin, int end);

};


#endif //CPP_HEAD_FILES_LRANDOM_H
