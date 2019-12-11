//
// Created by zxz on 2019/12/10.
//
#include "Vector.h"

Vector Vector::add(const Vector_T vt) const
{
    Vector v = *this;
    for(int i = 0; i < v.length; ++i)
    {
        v._Vector[i] += vt;
    }
    return v;
}

Vector Vector::sub(const Vector_T vt) const
{
    Vector v = *this;
    for(int i = 0; i < v.length; ++i)
    {
        v._Vector[i] -= vt;
    }
    return v;
}

Vector Vector::mul(const Vector_T vt) const
{
    Vector v = *this;
    for(int i = 0; i < v.length; ++i)
    {
        v._Vector[i] *= vt;
    }
    return v;
}

Vector Vector::div(const Vector_T vt) const
{
    assert(vt != 0.0);
    Vector v = *this;
    for(int i = 0; i < v.length; ++i)
    {
        v._Vector[i] /= vt;
    }
    return v;
}
