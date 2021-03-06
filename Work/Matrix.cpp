// Program 7_11_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
	n = 0;
	m = 0;
	v = NULL;
	cout << "def constrM " << this << "    v " << v << endl << endl;
}

Matrix::Matrix(int n, int m)
{
	if (n > 0 && m > 0)
	{
		this->n = n;
		this->m = m;
		v = new double*[n];
		for (int i = 0; i < n; i++)
			v[i] = new double[m];
	}
	else
	{
		this->n = 0;
		this->m = 0;
		v = NULL;
	}
	cout << "param constr " << this << "    v " << v << endl << endl;
}

Matrix::Matrix(const Matrix& matr)
{
	if (matr.n > 0 && matr.m > 0)
	{
		n = matr.n;
		m = matr.m;
		if (matr.v == NULL)
			v = NULL;
		else
		{
			v = new double*[n];
			for (int i = 0; i < n; i++)
				v[i] = new double[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				v[i][j] = matr.v[i][j];
	}
	else
	{
		n = 0;
		m = 0;
		v = NULL;
	}
	cout << "copy constr " << this << "    v " << v << endl << endl;
}

Matrix::~Matrix()
{
	cout << "destructor " << this << "  v " << v << endl << endl;
	if (n != 0 && m != 0 && v != NULL)
	{
		for (int i = 0; i < n; i++)
			delete v[i];
		delete v;
	}
}

double Matrix::Get(int i, int j)
{
	if (i < n && i >= 0 && j < m && j >= 0)
		return v[i][j];
	return 0;
}

void Matrix::Set(int i, int j, double d)
{
	if (i < n && i >= 0 && j < m && j >= 0)
		v[i][j] = d;
	else return;
}

bool Matrix::InitializeUnitary()
{
	if (n != m) return false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = 0;
		}
		v[i][i] = 1;
	}
	//res.PrintMatrix();
	return true;
}

Matrix& Matrix::TriangleMatrix()
{
	int K = n >= m ? m : n;
	for (int k = 0; k < K - 1; k++)
	{
		double X = v[k][k];
		for (int i = k + 1; i < n; i++)
		{
			double Y = v[i][k];
			double koef = Y / X;

			for (int j = k; j < m; j++)
			{
				v[i][j] -= koef*v[k][j];
			}
		}
	}
	return *this;
}

double Matrix::Determinant()
{
	if (n != m || n == 0 || m == 0) return NAN;
	Matrix Triangl = this->TriangleMatrix();
	double det = 1;
	for (int i = 0; i < n; i++)
		det *= Triangl.v[i][i];
	return det;
}

Matrix Matrix::Transpose()
{
	Matrix res(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res.v[i][j] = v[j][i];
	return res;
}

Matrix& Matrix::FillMatrix()				     // Заполнить матрицу
{
	cout << "FillMatrix" << endl << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = i + j + 3;
	return *this;
}

Matrix Matrix::AddMatrix(const Matrix &matr)
{
	if (n != matr.n || m != matr.m || v == NULL || matr.v == NULL)
	{
		Matrix res;
		return res;
	}
	else
	{
		Matrix res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.v[i][j] = v[i][j] + matr.v[i][j];
		return res;
	}
}

Matrix Matrix:: operator+(const Matrix &matr)
{
	//Matrix res = AddMatrix(matr);
	Matrix res(n, m);
	if (matr.n == n && matr.m == m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.v[i][j] = v[i][j] + matr.v[i][j];
	}
	else
	{
		Matrix res();
	}
	return res;
}

Matrix Matrix:: operator-(const Matrix &matr)
{
	Matrix res(n, m);
	if (matr.n == n && matr.m == m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.v[i][j] = v[i][j] - matr.v[i][j];
	}
	else
	{
		Matrix res();
	}
	return res;
}

Matrix Matrix::MulMatrix(const Matrix &matr)
{
	if (m != matr.n || v == NULL || matr.v == NULL)
	{
		Matrix res;
		return res;
	}
	else
	{
		Matrix	  res(n, matr.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < matr.m; j++)
			{
				res.v[i][j] = 0;
				for (int k = 0; k < m; k++)
				{
					res.v[i][j] += v[i][k] * matr.v[k][j];
				}
			}
		return res;
	}
}

Matrix Matrix:: operator*(const Matrix &matr)
{
	Matrix res = MulMatrix(matr);
	return res;
}

Matrix Matrix:: operator+(const double chislo)
{
	Matrix res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.v[i][j] = v[i][j] + chislo;
	return res;
}

Matrix& Matrix:: operator-()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = -v[i][j];
	return *this;
}

Matrix& Matrix:: operator++()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			++v[i][j];
	return *this;
}

Matrix Matrix:: operator++(int)		 // Постфиксный
{
	Matrix matr(*this);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			++v[i][j];
	return matr;
}

Matrix& Matrix:: operator--()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = v[i][j] - 1;
	return *this;
}

Matrix Matrix:: operator--(int)		  // Постфиксный
{
	Matrix matr(*this);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			--v[i][j];
	return matr;
}

void Matrix::PrintMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << v[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

Matrix& Matrix:: operator=(const Matrix &matr)
{
	cout << "operator '='  " << this << "   v " << v << endl << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			v[i][j] = matr.v[i][j];
		}
	return *this;
}

void PrintMatrix(const Matrix &matr)
{
	for (int i = 0; i < matr.n; i++)
	{
		for (int j = 0; j < matr.m; j++)
			cout << matr.v[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

EMatrix:: EMatrix()
{
	cout << "def constrE " << this << endl << endl;
}

EMatrix:: EMatrix(int n) :Matrix(n, n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i][j] = i == j ? 1 : 0;
	cout << "param constrE " << this << endl << endl;
}

EMatrix:: ~EMatrix()
{
	cout << "destructor E " << this << endl << endl;
}

void CheckMatrix()
{
	//Matrix m1(3, 3);
	//	Matrix m2(3, 4);
//	m1.FillMatrix();
	//	m2.FillMatrix();
//	PrintMatrix(m1);
	//	m2.PrintMatrix();

	/*m1(2, 2) = 0;
	PrintMatrix(m1);*/
	

	//Matrix Mtr = m1.TriangleMatrix();
	//PrintMatrix(Mtr);
	////	PrintMatrix(m1);
	//cout << "Det=" << m1.Determinant() << endl;

	///*Matrix m3 = m1;
	//PrintMatrix(m3);*/


	//Matrix m4 = m1.AddMatrix(m2);
	//PrintMatrix(m4);

	//cout << m4[0][1] << endl;
	//m4[0][0] = 3;
	//PrintMatrix(m4);

	//Matrix m6 = m1*m2*m1;
	//m6.PrintMatrix();

	//Matrix m(2, 7);
	//m.FillMatrix();
	//PrintMatrix(m);
	//Matrix m7 = m.Transpose();
	//PrintMatrix(m7);

	//EMatrix em(5);
	//PrintMatrix(em);
	//


	//cin.get();
	//cin.get();
}

