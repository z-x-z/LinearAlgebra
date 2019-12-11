//
// Created by zxz on 2019/12/11.
//

#include "LRandom.h"

// [begin, end]
Vector LRandom::randVector(int length, Vector_T begin, Vector_T end)
{
    Vector v(length);
    std::uniform_real_distribution<Vector_T> distribution(begin, end);
    for(int i = 0; i < length; ++i)
    {
        v[i] = distribution(generator);
    }
    return v;
}

Vector LRandom::randIntVector(int length, int begin, int end)
{
    Vector v(length);
    std::uniform_int_distribution<int> distribution(begin, end);
    for(int i = 0; i < length; ++i)
    {
        v[i] = distribution(generator);
    }
    return v;
}