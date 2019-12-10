//
// Created by zxz on 2019/12/5.
//

#ifndef CPP_HEAD_FILES_MATRIX_H
#define CPP_HEAD_FILES_MATRIX_H

const double MATRIX_T_ZERO = 1E-6;

typedef double Matrix_T;

#include "../../Vector/src/Vector.h"
#include <ranlib.h>
#include <ctime>
#include<iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

// 相互依赖的两个类文件为了解决依赖冲突需要在其中一个类的头文件中添加另一个类的前置声明
class Vector;

class Matrix
{
private:
    Matrix_T** _Matrix;
    int r, c;

    void deleteMatrix()
    {
        for(int i = 0; i < r; i++)
        {
            delete _Matrix[i];
        }
        delete _Matrix;
    }

    void newMatrix(int row, int col)
    {
        this->deleteMatrix();
        this->r = row;
        this->c = col;
        this->c = col;
        this->_Matrix = new Matrix_T* [row];
        for(int i = 0; i < row; ++i)
        {
            this->_Matrix[i] = new Matrix_T[col];
        }
    }

public:
    /// Constructor or Destructor
    Matrix(int row, int col);

    Matrix(int row, int col, Matrix_T init);

    Matrix(int n, Matrix_T init);

    explicit Matrix(int n);

    ~Matrix();

    /// Property
    Matrix copy() const;

    int getRow();

    int getCol();

    static int Matrix_T_to_int(Matrix_T t);

    Vector getRowVector(int row);

    Vector getColVector(int col);

    static Matrix getMatrixByArray(int row, int col, const double* array);

    static Matrix getMatrixByArray(int n, const double* array);

    Vector getArrayByColOrder();

    Vector getArrayByRowOrder();

    Matrix getReshapeByRow(int row, int col);

    Matrix getReshapeByCol(int row, int col);


    void setRowVector(int row, Vector rowVector);

    void setColVector(int col, Vector colVector);

    /// IO
    void printFormatRow(int row, const string& format) const;

    void printFormat(const string& format) const;

    void printRow(int row, int decimal = 2) const;

    void print(int decimal = 2) const;

    void printIntRow(int row) const;

    void printInt() const;

    void writeIntoFile(ofstream& f_out) const;

    void scan();

    void scanRow(int row);

    void readFromFile(ifstream& f_in);

    static Matrix matrixFromFile(ifstream& f_in);

    /// Override Operator

    Matrix_T* operator[](int row) const;

    Matrix& operator=(const Matrix& m);

    Matrix operator+(const Matrix& m) const;

    Matrix operator-(const Matrix& m) const;

    Matrix operator*(const Matrix& m) const;

    Matrix operator/(const Matrix& m) const;

    Matrix operator^(int n) const;


    /// Scale,  Vector Operations
    void add(Matrix_T d);

    void rowAdd(int row, Matrix_T d);

    void sub(Matrix_T d);

    void rowSub(int row, Matrix_T d);

    void mul(Matrix_T d);

    void rowMul(int row, Matrix_T d);

    void div(Matrix_T d);

    void rowDiv(int row, Matrix_T d);

    void rowExchange(int i, int j);

    void colExchange(int i, int j);
    /// Matrix Operations

    static Matrix matAdd(const Matrix& m1, const Matrix& m2);

    static Matrix matSub(const Matrix& m1, const Matrix& m2);

    static Matrix matMul(const Matrix& m1, const Matrix& m2);

    static Matrix matDiv(const Matrix& m1, const Matrix& m2);

    static Matrix transpose(const Matrix& m);

    Matrix matAdd(const Matrix& m2) const;  // 由于静态函数中调用的参数m1为const型，故在
    /// 该函数中要将该函数标为const
    Matrix matSub(const Matrix& m2) const;

    Matrix matMul(const Matrix& m2) const;

    Matrix matDiv(const Matrix& m2) const;

    Matrix transpose() const;

    /// Matrix Functions

    static Matrix inverse(const Matrix& m);

    Matrix inverse() const;

    static Matrix_T determinant(const Matrix& m);

    Matrix_T determinant() const;

    static Vector solveLinearEquation(Matrix& A, Vector b);

    Vector solveLinearEquation(Vector b) const ;

    /// Some Matrix
    static Matrix identity(int n);

    //(0, 1]
    static Matrix random(int n);

    static Matrix random(int r, int c);

    static Matrix randMatrix_T(int n, Matrix_T begin, Matrix_T end);

    static Matrix randMatrix_T(int r, int c, Matrix_T begin, Matrix_T end);

    // [begin, end]
    static Matrix randInt(int n, int begin, int end);

    static Matrix randInt(int r, int c, int begin, int end);
};


#endif //CPP_HEAD_FILES_MATRIX_H
