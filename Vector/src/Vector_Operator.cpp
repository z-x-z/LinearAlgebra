//
// Created by zxz on 2019/12/9.
//

#include "Vector.h"

Vector& Vector::operator=(const class Vector& v)
{
    if(this!=&v)
    {
        newVector(v.length);
        for(int i = 0; i < length; ++i)
        {
            _Vector[i] =  v._Vector[i];
        }
    }
    return *this;
}

Vector_T & Vector::operator[](int i) const
{
    return _Vector[i];
}