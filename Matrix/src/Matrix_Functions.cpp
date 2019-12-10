//
// Created by zxz on 2019/12/5.
//
#include "Matrix.h"

// reducedRow = reducedRow - multiple * MinusRow
void MatrixRow_sub(Matrix& m, int reducedRow, int MinusRow, double multiple)
{
    for(int i = 0; i < m.getCol(); ++i)
    {
        m[reducedRow][i] -= multiple * m[MinusRow][i];
    }
}

void rowOrder_recover(Matrix& m, int* order)
{
    Matrix row_exchange(m.getRow(), m.getCol());
    for(int i = 0; i < m.getRow(); ++i)
    {
        row_exchange.setRowVector(i, m.getRowVector(order[i]));
    }
    m = row_exchange;
}


void printArray(int* a, int n)
{
    printf("\n---Array---\n");
    for(int i = 0; i < n; ++i)
    {
        printf(" %d", a[i]);
    }
}

void swapRowIndex(int* rowIndex, int i, int j)
{
    int tmp = rowIndex[i];
    rowIndex[i] = rowIndex[j];
    rowIndex[j] = tmp;
}

Matrix Matrix::inverse(const class Matrix& m)
{
    return m.inverse();
}

/*
 * Gauss-Jordan partial pivoting
 */


Matrix Matrix::inverse() const
{
    assert(r != 0 && r == c);
    Matrix m = copy();
    Matrix I = Matrix::identity(r);
    int rowIndex[r];
    // 行变换数组
    for(int i = 0; i < r; ++i)
    {
        rowIndex[i] = i;
    }
    // i - 列序号
    for(int i = 0; i < r - 1; ++i)
    {
        // 寻找部分主元(rowIndex[j], i)
        Matrix_T row_maxValue = 0.0;
        int cur_row;
        int maxj;
        for(int j = i; j < r; ++j)
        {
            cur_row = rowIndex[j];
            if(abs(m._Matrix[cur_row][i]) > row_maxValue)
            {
                row_maxValue = m._Matrix[cur_row][i];
                maxj = j;
            }
            // 主元项不能为0
            assert(row_maxValue != 0.0);
        }
        // 交换行(逻辑上)
        swapRowIndex(rowIndex, i, maxj);
        // 消原
        cur_row = rowIndex[i];
        int row;
        /*
         * 从i+1行开始消元， cur_row为当前的行，row为逻辑上的i+1行
         */
        for(int j = i + 1; j < r; ++j)
        {
            row = rowIndex[j];
            double a = m._Matrix[row][i] / row_maxValue;
            MatrixRow_sub(m, row, cur_row, a);
            MatrixRow_sub(I, row, cur_row, a);
        }
        m.rowDiv(cur_row, row_maxValue);
        I.rowDiv(cur_row, row_maxValue);
    }

    Matrix_T last_pivot = m._Matrix[rowIndex[r - 1]][c - 1];
    assert(last_pivot != 0.0);
    I.rowDiv(rowIndex[r - 1], last_pivot);
    m.rowDiv(rowIndex[r - 1], last_pivot);
    // 继续化简
    // i-列 row-行
    for(int i = c - 1; i >= 0; --i)
    {
        int row;
        double a;
        for(int j = i - 1; j >= 0; --j)
        {
            row = rowIndex[j];
            a = m._Matrix[row][i];
            MatrixRow_sub(m, row, rowIndex[i], a);
            MatrixRow_sub(I, row, rowIndex[i], a);
        }
    }
    rowOrder_recover(I, rowIndex);
    return I;
}


Matrix_T Matrix::determinant(const class Matrix & m)
{
    return m.determinant();
}

double Matrix::determinant() const
{
    Matrix m = copy();
    Matrix_T det = 1;
    for(int i = 0; i < c; ++i)
    {
        double pivot = m._Matrix[i][i];
        det *= pivot;
        assert(pivot != 0.0);
        for(int j = i + 1; j < r; ++j)
        {
            double a = m._Matrix[j][i] / pivot;
            MatrixRow_sub(m, j, i, a);
        }
    }
    return det;
}

Vector Matrix::solveLinearEquation(class Matrix & A,Vector b)
{
    return A.solveLinearEquation(b);
}

Vector Matrix::solveLinearEquation(Vector b) const
{
    return NULL;
}
