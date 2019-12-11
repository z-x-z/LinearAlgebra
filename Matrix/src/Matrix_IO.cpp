//
// Created by zxz on 2019/12/5.
//
#include "Matrix.h"

void Matrix::printFormatRow(int row, const std::__1::string& format) const
{
    printf(format.c_str(), _Matrix[row][0]);
    for(int i = 1; i < c; i++)
    {
        printf(" ");
        printf(format.c_str(), _Matrix[row][i]);
    }
}

void Matrix::printFormat(const std::__1::string& format) const
{
    printFormatRow(0, format);
    for(int i = 1; i < r; i++)
    {
        printf("\n");
        printFormatRow(i, format);
    }
}

void Matrix::printRow(int row, int decimal) const
{
    assert(row < r && decimal >= 0);
    string formatStr;
    if(decimal == 2)
    {
        formatStr = "%.2f";
    }
    else
    {
        formatStr = "%." + to_string(decimal) + "f";
    }
    printf(formatStr.c_str(), _Matrix[row][0]);
    formatStr = " " + formatStr;
    for(int i = 1; i < c; i++)
    {
        printf(formatStr.c_str(), _Matrix[row][i]);
    }

}

void Matrix::print(int decimal) const
{
    printRow(0, decimal);
    for(int i = 1; i < r; i++)
    {
        printf("\n");
        printRow(i, decimal);
    }
}


void Matrix::printIntRow(int row) const
{
    printf("%d", Matrix_T_to_int(_Matrix[row][0]));
    for(int i = 1; i < c; i++)
    {
        printf(" %d", Matrix_T_to_int(_Matrix[row][i]));
    }
}

void Matrix::printInt() const
{
    printIntRow(0);
    for(int i = 1; i < r; i++)
    {
        printf("\n");
        printIntRow(i);
    }
}


void Matrix::writeIntoFile(ofstream& f_out) const
{
    f_out << std::setprecision(2) << _Matrix[0][0];
    for(int j = 1; j < c; ++j)
    {
        f_out << "  " << std::setprecision(2) << _Matrix[0][j];
    }

    for(int i = 1; i < r; ++i)
    {
        f_out << endl;
        f_out << std::setprecision(2) << _Matrix[i][0];
        for(int j = 1; j < c; ++j)
        {
            f_out << "  " << std::setprecision(2) << _Matrix[i][j];
        }
    }
}

void Matrix::scanRow(int row)
{
    printf("Request %d columns:", c);
    for(int i = 0; i < c; i++)
    {
        scanf("%lf", &_Matrix[row][i]);
    }
}

void Matrix::scan()
{
    printf("Request %d rows\n", r);
    for(int i = 0; i < r; i++)
    {
        scanRow(i);
    }

}

// 由于IO对象不可复制，流对象在函数应该传递引用类型
void Matrix::readFromFile(ifstream& f_in)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; ++j)
        {
            f_in >> _Matrix[i][j];
        }
    }
}

Matrix Matrix::matrixFromFile(ifstream& f_in)
{
    int r=0, c=0;
    f_in >> r >> c;
    Matrix m(r, c);
    m.readFromFile(f_in);
    return m;
}
