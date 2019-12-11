//
// Created by zxz on 2019/12/9.
//
#include "Vector.h"

void Vector::print(int decimal) const
{
    assert(decimal >= 0);
    string formatStr;
    if(decimal == 2)
    {
        formatStr = "%.2f";
    }
    else
    {
        formatStr = "%." + to_string(decimal) + "f";
    }
    printf(formatStr.c_str(), _Vector[0]);
    formatStr = " " + formatStr;
    for(int i = 1; i < length; i++)
    {
        printf(formatStr.c_str(), _Vector[i]);
    }
}

void Vector::print(const std::__1::string& format) const
{
    printf(format.c_str(), _Vector[0]);
    for(int i = 1; i < length; i++)
    {
        printf(" ");
        printf(format.c_str(), _Vector[i]);
    }
}

void Vector::printInt() const
{
    printf("%d", int(_Vector[0]));
    for(int i = 1; i < length; i++)
    {
        printf(" %d", int(_Vector[i]));
    }
}

void Vector::writeIntoFile(ofstream& f_out) const
{
    f_out << std::setprecision(2) << _Vector[0];
    for(int j = 1; j < length; ++j)
    {
        f_out << "  " << std::setprecision(2) << _Vector[j];
    }
}

void Vector::scan()
{
    printf("Request %d item:", length);
    for(int i = 0; i < length; i++)
    {
        scanf("%lf", &_Vector[i]);
    }
}

void Vector::readFromFile(ifstream& f_in)
{
    for(int i = 0; i < length; i++)
    {
        f_in >> _Vector[i];
    }
}

Vector Vector::VectorFromFile(ifstream& f_in)
{
    int length=0;
    f_in >> length;
    Vector v(length);
    v.readFromFile(f_in);
    return v;
}