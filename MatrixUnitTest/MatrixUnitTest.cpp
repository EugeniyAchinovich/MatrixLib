#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixLib/MatrixLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest
{
	TEST_CLASS(MatrixUnitTest)
	{
	public:
		// переопределённых операторов = и [][]
		TEST_METHOD(TestOperatorEqual)
		{
			int** arr = new int* [2];
			for (int i = 0; i < 2; i++)
				arr[i] = new int[2];

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;

			Matrix A(2, 2);

			Matrix B = A;

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					Assert::AreEqual(A[i][j], B[i][j]);

			int** arr2 = new int* [3];
			for (int i = 0; i < 3; i++)
				arr2[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr2[i][j] = i + j;

			Matrix C(3, 3);

			Matrix D = C;

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					Assert::AreEqual(C[i][j], D[i][j]);

			Matrix E(5, 5);

			Matrix F = E;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					Assert::AreEqual(E[i][j], F[i][j]);
		}
		// тесты конструктора, который создаёт пустые матрицы
		TEST_METHOD(TestConstructorWithoutValues)
		{
			Matrix m1(1, 1);
			Matrix m2(2, 2);
			Matrix m3(3, 3);
			Matrix m4(4, 4);
			Matrix m5(5, 5);
			Matrix m6(2, 8);

			for (int i = 0; i < m1.GetRows(); i++)
				for (int j = 0; j < m1.GetColumns(); j++)
					Assert::AreEqual(m1[i][j], 0, L"Matrix 1x1: Assert " + i * 3 + j + 1);

			for (int i = 0; i < m2.GetRows(); i++)
				for (int j = 0; j < m2.GetColumns(); j++)
					Assert::AreEqual(m2[i][j], 0, L"Matrix 2x2: Assert " + i * 3 + j + 1);

			for (int i = 0; i < m3.GetRows(); i++)
				for (int j = 0; j < m3.GetColumns(); j++)
					Assert::AreEqual(m3[i][j], 0, L"Matrix 3x3: Assert " + i * 3 + j + 1);

			for (int i = 0; i < m4.GetRows(); i++)
				for (int j = 0; j < m4.GetColumns(); j++)
					Assert::AreEqual(m4[i][j], 0, L"Matrix 4x4: Assert " + i * 3 + j + 1);

			for (int i = 0; i < m5.GetRows(); i++)
				for (int j = 0; j < m5.GetColumns(); j++)
					Assert::AreEqual(m5[i][j], 0, L"Matrix 5x5: Assert " + i * 3 + j + 1);

			for (int i = 0; i < m6.GetRows(); i++)
				for (int j = 0; j < m6.GetColumns(); j++)
					Assert::AreEqual(m6[i][j], 0, L"Matrix 2x8: Assert " + i * 3 + j + 1);

		}

		// тесты конструктора, который создаёт матрицы, заполненные значениями из 2D массива
		TEST_METHOD(TestConstructorWithValues)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++)
				arr[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr[i][j] = i * 3 + j + 1;

			Matrix m1(3, 3, arr);

			Assert::AreEqual(m1[0][0], 1, L"Matrix m1: Assert 1");
			Assert::AreEqual(m1[0][1], 2, L"Matrix m1: Assert 2");
			Assert::AreEqual(m1[0][2], 3, L"Matrix m1: Assert 3");
			Assert::AreEqual(m1[1][0], 4, L"Matrix m1: Assert 4");
			Assert::AreEqual(m1[1][1], 5, L"Matrix m1: Assert 5");
			Assert::AreEqual(m1[1][2], 6, L"Matrix m1: Assert 6");
			Assert::AreEqual(m1[2][0], 7, L"Matrix m1: Assert 7");
			Assert::AreEqual(m1[2][1], 8, L"Matrix m1: Assert 8");
			Assert::AreEqual(m1[2][2], 9, L"Matrix m1: Assert 9");


			int** arr2 = new int* [2];
			for (int i = 0; i < 2; i++)
				arr2[i] = new int[2];

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					arr2[i][j] = i;

			Matrix m2(2, 2, arr2);

			Assert::AreEqual(m2[0][0], 0, L"Matrix m2: Assert 1");
			Assert::AreEqual(m2[0][1], 0, L"Matrix m2: Assert 2");
			Assert::AreEqual(m2[1][0], 1, L"Matrix m2: Assert 3");
			Assert::AreEqual(m2[1][1], 1, L"Matrix m2: Assert 4");
		}

		// тесты функции транспонирования матрицы
		TEST_METHOD(TestFunctionTranspose)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++)
				arr[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr[i][j] = i * 3 + j + 1;

			Matrix A(3, 3, arr);
			Matrix B = A.Transpose();

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(A[i][j], B[j][i]);
		}

		// тесты функции нахождения определителя матрицы
		TEST_METHOD(TestFunctionDeterminant)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++)
				arr[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr[i][j] = i * 3 + j + 1;

			Matrix A(3, 3, arr);
	
			Assert::AreEqual(A.GetDeterminant(), -6);

			Matrix B(2, 5);

			Assert::AreEqual(B.GetDeterminant(), -1);

			int** arr2 = new int* [4];
			for (int i = 0; i < 4; i++)
				arr2[i] = new int[4];

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					arr2[i][j] = i + j;

			Matrix C(4, 4, arr2);

			Assert::AreEqual(C.GetDeterminant(), 2);

			Assert::AreNotEqual(C.GetDeterminant(), 0);
			Assert::AreNotEqual(C.GetDeterminant(), -1);
		}

		// тесты функции сложения матриц через перегрузку бинарного оператора +
		TEST_METHOD(TestOperatorPlus)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++)
				arr[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr[i][j] = i * 3 + j + 1;

			Matrix A(3, 3, arr);
			Matrix B(3, 3, arr);
			
			Matrix C = A + B;

			Assert::AreEqual(C[0][0], 2, L"Matrix C: Assert 1");
			Assert::AreEqual(C[0][1], 4, L"Matrix C: Assert 2");
			Assert::AreEqual(C[0][2], 6, L"Matrix C: Assert 3");
			Assert::AreEqual(C[1][0], 8, L"Matrix C: Assert 4");
			Assert::AreEqual(C[1][1], 10, L"Matrix C: Assert 5");
			Assert::AreEqual(C[1][2], 12, L"Matrix C: Assert 6");
			Assert::AreEqual(C[2][0], 14, L"Matrix C: Assert 7");
			Assert::AreEqual(C[2][1], 16, L"Matrix C: Assert 8");
			Assert::AreEqual(C[2][2], 18, L"Matrix C: Assert 9");
		}

		// тесты функции умножения матриц на скаляр через перегрузку бинарного оператора *
		TEST_METHOD(TestOperatorMultiply)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++)
				arr[i] = new int[3];

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					arr[i][j] = i * 3 + j + 1;

			Matrix A(3, 3, arr);

			Matrix B = A * 3;
			Matrix C = A * -2;
			Matrix D = A * 0;

			Assert::AreEqual(B[0][0], 3, L"Matrix B: Assert 1");
			Assert::AreEqual(B[0][1], 6, L"Matrix B: Assert 2");
			Assert::AreEqual(B[0][2], 9, L"Matrix B: Assert 3");
			Assert::AreEqual(B[1][0], 12, L"Matrix B: Assert 4");
			Assert::AreEqual(B[1][1], 15, L"Matrix B: Assert 5");
			Assert::AreEqual(B[1][2], 18, L"Matrix B: Assert 6");
			Assert::AreEqual(B[2][0], 21, L"Matrix B: Assert 7");
			Assert::AreEqual(B[2][1], 24, L"Matrix B: Assert 8");
			Assert::AreEqual(B[2][2], 27, L"Matrix B: Assert 9");

			Assert::AreEqual(C[0][0], -2, L"Matrix C: Assert 1");
			Assert::AreEqual(C[0][1], -4, L"Matrix C: Assert 2");
			Assert::AreEqual(C[0][2], -6, L"Matrix C: Assert 3");
			Assert::AreEqual(C[1][0], -8, L"Matrix C: Assert 4");
			Assert::AreEqual(C[1][1], -10, L"Matrix C: Assert 5");
			Assert::AreEqual(C[1][2], -12, L"Matrix C: Assert 6");
			Assert::AreEqual(C[2][0], -14, L"Matrix C: Assert 7");
			Assert::AreEqual(C[2][1], -16, L"Matrix C: Assert 8");
			Assert::AreEqual(C[2][2], -18, L"Matrix C: Assert 9");

			Assert::AreEqual(D[0][0], 0, L"Matrix D: Assert 1");
			Assert::AreEqual(D[0][1], 0, L"Matrix D: Assert 2");
			Assert::AreEqual(D[0][2], 0, L"Matrix D: Assert 3");
			Assert::AreEqual(D[1][0], 0, L"Matrix D: Assert 4");
			Assert::AreEqual(D[1][1], 0, L"Matrix D: Assert 5");
			Assert::AreEqual(D[1][2], 0, L"Matrix D: Assert 6");
			Assert::AreEqual(D[2][0], 0, L"Matrix D: Assert 7");
			Assert::AreEqual(D[2][1], 0, L"Matrix D: Assert 8");
			Assert::AreEqual(D[2][2], 0, L"Matrix D: Assert 9");
		}
	};
}
