//
// Created by zxz on 2019/12/9.
//

#ifndef CPP_HEAD_FILES_VECTOR_H
#define CPP_HEAD_FILES_VECTOR_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <random>
#include "../../Matrix/src/Matrix.h"

class Matrix;

using namespace std;

typedef double Vector_T;

class Vector
{
private:
    Vector_T* _Vector;
    int length;

    void deleteVector()
    {
        delete _Vector;
        length = 0;
    }

    void newVector(int _length)
    {
        deleteVector();
        length = _length;
        _Vector = new Vector_T[length];
    }

public:
    /// constructor and  destructor
    explicit Vector(int length);

    Vector(int length, int init);

    Vector(int length, const Vector_T* vec);

    virtual ~Vector();

    int getLength() const;

    Vector_T* getVector() const;

    Vector Copy() const;

    bool isNull() const;

    /// Operator override
    Vector_T& operator[](int i) const;

    Vector& operator=(const Vector& v);

    /// IO

    void print(int decimal = 2) const;

    void print(const string& format) const;

    void printInt() const;

    void writeIntoFile(ofstream& f_out) const;

    void scan();

    void readFromFile(ifstream& f_in);

    static Vector VectorFromFile(ifstream& f_in);

    /// Scalar Opertion
    Vector add(const Vector_T vt) const;

    Vector sub(const Vector_T vt) const;

    Vector mul(const Vector_T vt) const;

    Vector div(const Vector_T vt) const;


    /// Vector Operation
    Vector vecAdd(const Vector& v) const;

    Vector vecSub(const Vector& v) const;

    Vector vecMul(const Vector& v) const;

    Vector vecDiv(const Vector& v) const;

    Vector_T innerProduct(const Vector& v) const;

    Matrix outerProduct(const Vector& v) const;


};


#endif //CPP_HEAD_FILES_VECTOR_H
