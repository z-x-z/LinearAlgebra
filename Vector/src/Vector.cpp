//
// Created by zxz on 2019/12/9.
//

#include "Vector.h"

Vector::Vector(int _length) : length(_length)
{
    _Vector = new Vector_T[length];
}

Vector::Vector(int _length, int init) : length(_length)
{
    _Vector = new Vector_T[length];
    for(int i = 0; i < length; ++i)
    {
        _Vector[i] = init;
    }
}

Vector::Vector(int _length, const Vector_T* vec) : length(_length)
{
    _Vector = new Vector_T[length];
    for(int i = 0; i < length; ++i)
    {
        _Vector[i] = vec[i];
    }
}

Vector::~Vector()
{
    delete _Vector;
    length = -1;
}

int Vector::getLength() const
{
    return length;
}

Vector_T* Vector::getVector() const
{
    return _Vector;
}

Vector Vector::Copy() const
{
    Vector copy(length);
    for(int i = 0; i < length; ++i)
    {
        copy._Vector[i] = _Vector[i];
    }
    return copy;
}

bool Vector::isNull() const
{
    return length == 0;
}
