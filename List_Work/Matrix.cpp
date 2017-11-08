// Program 7_11_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
	cout << "def constr " << this << endl;
	n = 0;
	m = 0;
	v = NULL;
}

Matrix::Matrix(int n, int m)
{
	cout << "param constr " << this << endl;
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
}

Matrix::~Matrix()
{
	cout << "destructor " << this << endl;
	if (n != 0 && m != 0 && v != NULL)
	{
		for (int i = 0; i < n; i++)
			delete v[i];
		delete v;
	}
}

bool Matrix::FillMatrix()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = i + j;
	return true;
}

Matrix* Matrix::AddMatrix(Matrix &matr)
{
	if (n != matr.n || m != matr.m || v == NULL || matr.v == NULL)
	{
		return NULL;
	}
	else
	{
		Matrix*	  ptm;
		ptm = new Matrix(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ptm->v[i][j] = v[i][j] + matr.v[i][j];
		return ptm;
	}
}

Matrix* Matrix::MulMatrix(Matrix &matr)
{
	if (n != matr.m || v == NULL || matr.v == NULL)
	{
		return NULL;
	}
	else
	{
		Matrix*	  ptm;
		ptm = new Matrix(m, matr.n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < matr.m; j++)
			{
				ptm->v[i][j] = { 0 };
				for (int k = 0; k < n; k++)
				{
					ptm->v[i][j] += v[i][k] * matr.v[k][j];
				}
			}
		return ptm;
	}
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

void CheckMatrix()
{
	Matrix m1(3, 4);
	Matrix m2(3, 4);
	m1.FillMatrix();
	m2.FillMatrix();

	Matrix* m3 = m1.AddMatrix(m2);

	m1.PrintMatrix();
	m3->PrintMatrix();
		  	
	delete m3;


	cin.get();
	cin.get();
}

