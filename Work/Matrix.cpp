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
	cout << "def constr " << this << "    v " << v << endl << endl;
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

bool Matrix::FillMatrix()				     // Заполнить матрицу
{
	cout << "FillMatrix" << endl << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = i + j + 1;
	return true;
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

void CheckMatrix()
{
	/*Matrix m1(3, 4);
	Matrix m2(3, 4);
	m1.FillMatrix();
	m2.FillMatrix();
	PrintMatrix(m1);
	m2.PrintMatrix();*/

	/*Matrix m3 = m1;
	PrintMatrix(m3);*/


	//Matrix m4 = m1.AddMatrix(m2);
	//PrintMatrix(m4);

	/*cout << m4[0][1] << endl;
	m4[0][0] = 3;
	PrintMatrix(m4);*/

	/*cout << m2[1][1] << " " << m2(1, 1) << endl;
	m2(1, 1) = 10;
	PrintMatrix(m2);*/


	Matrix m5(3,3);
	m5.InitializeUnitary();
	PrintMatrix(m5);

	//Matrix m6 = m1*m2*m1;
	//m6.PrintMatrix();


	cin.get();
	cin.get();
}

