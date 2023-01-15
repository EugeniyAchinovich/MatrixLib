#include <iostream>
#include "../MatrixLib/MatrixLib.h"


int main()
{
    int** arr = new int* [3];
    for (int i = 0; i < 3; i++)
        arr[i] = new int[3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)          // Инициализация массива
            arr[i][j] = i + 1;


    Matrix M(2, 5);                          // Создание пустой матрицы 2x5


    std::cout << "Matrix M:" << std::endl;
    PrintMatrix(M);                         // Вывод на экран пустой матрицы


    Matrix A(3, 3, arr);                     // Создание матрицы A 3x3, заполненной значениями массива
    std::cout << "\nMatrix A:" << std::endl;
    PrintMatrix(A);                               // Вывод матрицы A


    A = A.Transpose();                       // Транспонирование матрицы A
    std::cout << "\nTransposed Matrix A:" << std::endl;
    PrintMatrix(A);                               // Вывод матрицы транспонированной матрицы A


    Matrix B(3, 3, arr);                     // Создание второй матрицы B 3x3, заполненной значениями массива
    Matrix C = A + B;                        // Сложение матриц A и B. Результат (сумма) - матрица C

    std::cout << "\nC = A + B =" << std::endl;
    PrintMatrix(C);                               // Вывод полученной матрицы C


    C = C * -3;                              // Умножение матрицы С на скаляр
    std::cout << "\nC * -3 =" << std::endl;
    PrintMatrix(C);                               // Вывод умноженной матрицы C

    int d = B.GetDeterminant();              // Вычисление определителя матрицы B и вывод его на экран
    std::cout << "\nDet B = " << d;

    d = M.GetDeterminant();                  // Попытка вычислить определитель неквадратной матрицы M.
    // Результат - вывод сообщения о невозможности вычисления определителя.

    return 0;
}


