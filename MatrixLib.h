#pragma once

#include "pch.h"
#include "framework.h"
#include <iostream>

class Matrix
{
private:
    int n;
    int m;
    int temp;
    int** value;

    int _GetDeterminant(int);

public:
    Matrix(const int, const int);
    Matrix(const int, const int, int**);
    ~Matrix();

    int GetRows();
    int GetColumns();

    int GetDeterminant();
    void Print();
    Matrix Transpose();

    const Matrix operator=(const Matrix&);
    const Matrix operator+(const Matrix&);
    const Matrix operator*(const int);
    const int* operator[](const int);
    const int operator[](const short int);
};

Matrix::Matrix(const int n, const int m, int** array)
{
    this->n = n;
    this->m = m;
    this->value = new int* [this->n + 1];
    this->temp = 0;

    for (int i = 0; i < m; i++)
        this->value[i] = new int[this->m + 1];


    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            this->value[i][j] = array[i][j];
}

Matrix::Matrix(const int n, const int m)
{
    this->n = n;
    this->m = m;
    this->value = new int* [n];
    this->temp = 0;

    for (int i = 0; i < m; i++)
        this->value[i] = new int[n];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            this->value[i][j] = 0;
}

Matrix::~Matrix()
{

}

int Matrix::GetRows()
{
    return n;
}

int Matrix::GetColumns()
{
    return m;
}

const Matrix Matrix::operator=(const Matrix& B)
{
    if (this->n != B.n || this->m != B.m) {
        std::cout << "Error: arrays must have the same size" << std::endl;
        return B;
    }

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            this->value[i][j] = B.value[i][j];
}

const Matrix Matrix::operator+(const Matrix& B)
{
    if (this->n != B.n || this->m != B.m) {
        std::cout << "Error: arrays must have the same size" << std::endl;
        return B;
    }

    Matrix A(this->n, this->m);

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            A.value[i][j] = this->value[i][j] + B.value[i][j];

    return A;
}

const Matrix Matrix::operator*(const int a)
{
    Matrix A(this->n, this->m);

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            A.value[i][j] = this->value[i][j] * a;

    return A;
}

const int* Matrix::operator[](const int index_i)
{
    if (index_i < this->n) {
        temp = index_i;
        int* line = value[index_i];
        return line;
    }
    return 0;
}

const int Matrix::operator[](const short int index_j)
{
    if (index_j < this->m)
        return ((*this)[temp][index_j]);

    return 0;
}

Matrix Matrix::Transpose()
{
    Matrix B(this->m, this->n, this->value);

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            B.value[j][i] = this->value[i][j];

    return B;
}

void Matrix::Print()
{
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cout << this->value[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int Matrix::GetDeterminant()
{
    if (this->n != this->m) {
        std::cout << "\nError: Cannot calculate determinant of non-square matrix" << std::endl;
        return -1;
    }
    _GetDeterminant(this->n);
}

int Matrix::_GetDeterminant(int n)
{
    if (n == 1)
        return this->value[0][0];
    else if (n == 2)
        return this->value[0][0] * this->value[1][1] - this->value[0][1] * this->value[1][0];
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = this->value[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * this->value[0][k] * _GetDeterminant(n - 1);
        }
        return d;
    }
}

void PrintMatrix(Matrix M)
{
    for (int i = 0; i < M.GetRows(); i++) {

        for (int j = 0; j < M.GetColumns(); j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << '\n';
    }
}