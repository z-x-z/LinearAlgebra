//
// Created by zxz on 2019/12/10.
//
#include "Vector.h"

Vector Vector::vecAdd(const Vector& v) const
{
    Vector result = *this;
    for(int i = 0; i < length; ++i)
    {
        result._Vector[i] += v._Vector[i];
    }
    return result;
}

Vector Vector::vecSub(const class Vector& v) const
{
    Vector result = *this;
    for(int i = 0; i < length; ++i)
    {
        result._Vector[i] -= v._Vector[i];
    }
    return result;
}

Vector Vector::vecMul(const Vector& v) const
{
    Vector result = *this;
    for(int i = 0; i < length; ++i)
    {
        result._Vector[i] *= v._Vector[i];
    }
    return result;
}

Vector Vector::vecDiv(const Vector& v) const
{
    Vector result = *this;
    for(int i = 0; i < length; ++i)
    {
        result._Vector[i] /= v._Vector[i];
    }
    return result;
}


Vector_T Vector::innerProduct(const Vector& v) const
{
    Vector_T product = 0;
    for(int i = 0; i < length; ++i)
    {
        product += (_Vector[i] * v._Vector[i]);
    }
    return product;
}

// v1(m*1) * v2T(1*n) -> (m*n)
Matrix Vector::outerProduct(const Vector& v) const
{
    Matrix product(length, v.length);
    for(int i = 0; i < product.getRow(); ++i)
    {
        for(int j = 0; j < product.getCol(); ++j)
        {
            product[i][j] = _Vector[i] * v._Vector[j];
        }
    }
    return product;
}