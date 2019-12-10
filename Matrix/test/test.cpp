//
// Created by zxz on 2019/12/5.
//
#include <random>
#include "test.h"

void test_IO()
{
    ifstream file_in;
    ofstream file_out;
    string file_path = "../rsc/text/Matrix_data1";
    string file_path_out = "../rsc/text/Matrix_dataout";
    file_in.open(file_path);
    file_out.open(file_path_out);
    if(file_in.is_open()&&file_out.is_open())
    {
        cout<<"Reading from file"<<endl;
        Matrix m= Matrix::matrixFromFile(file_in);
        m.print();
        cout<<"\nWriting to file"<<endl;
        m.writeIntoFile(file_out);
    }
    file_in.close();
    file_out.close();
    int r, c;

}

void test_MatrixOperation()
{
    double array1[] = {1, 2, 3, 4, 5, 6};
    Matrix m1 = Matrix::getMatrixByArray(2, 3, array1);
    Vector array2 = m1.getArrayByColOrder();
    Vector array3 = m1.getArrayByRowOrder();
    for(int i = 0; i < 6; ++i)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 6; ++i)
    {
        cout<<array3[i]<<" ";
    }
}

void test_GaussElimination1()
{
    double array1[] = {1, 2, 3, 1, 2, 3, 7, 8, 10};
    Matrix m1 = Matrix::getMatrixByArray(3, 3, array1);
    m1.print();
    printf("\n");
    double det = m1.determinant();
    printf("det: %.2lf", det);
}

/*
 *  -0.67 3.67 -2.00
    1.00 -2.00 1.00
    -0.67 -1.33 1.00
 */
void test_GaussElimination2()
{
    double array1[] = {1, 3, 5, 4, 5, 6, 7, 8, 12, 10, 13, 15, 17, 19, 20, 13};
//    double array1[] = {1,2,3,4};
    Matrix m = Matrix::getMatrixByArray(2, 2, array1);
    Matrix inverse_m = m.inverse();
    m.print();
    printf("\n-----\n");
    inverse_m.print();
    Matrix I = m.matMul(inverse_m);
    printf("\n-----\n");
    I.print();

}

void test_Operator()
{
    double array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    Matrix m = Matrix::getMatrixByArray(3, 3, array1);
    Matrix m1 = Matrix(2,2,0);
    m1.print();
    printf("\n");
    m1 = m;
    m1.print();
}

void test_det()
{
    double array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    Matrix m = Matrix::getMatrixByArray(3, 3, array1);
    m.determinant();
}

void test_random()
{
    auto rand1=  Matrix::random(5);
    printf("\nMatrix::random(5):\n");
    rand1.printFormat("%5.3f");
    auto rand2=  Matrix::randInt(5, 0, 10);
    printf("\nMatrix::randInt(5, 0, 10):\n");
    rand2.printInt();
    auto rand3=  Matrix::randMatrix_T(5, 0.0, 10.0);
    printf("\nrandMatrix_T(5, 0.0, 10.0):\n");
    rand3.print();
}

void test_algorithm()
{
    auto rand1 = Matrix::randMatrix_T(15, 0, 10);
    printf("\n---Original---\n");
    rand1.print();
    printf("\n---det---\n");
    cout<<rand1.determinant();
    auto inverse = rand1.inverse();
    printf("\n---inverse---\n");
    inverse.print();
    printf("\n---Mat * Inverse---\n");
    Matrix I = rand1.matMul(inverse);
    I.print();
    printf("\n-----\n");
    I.printInt();

}

/*
 * test c++ double transfer to int:
 *
    double a = 0+1E-5;
    double b = 0-1E-5;
    cout<<Matrix::Matrix_T_to_int(a)<<endl;
    cout<<Matrix::Matrix_T_to_int(b)<<endl;
 */
void Matrix_test()
{
    test_algorithm();
}

