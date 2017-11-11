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
	cout << "def constr " << this << endl;
	cout << "def constr, v " << v << endl;
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
	cout << "param constr " << this << endl;
	cout << "param constr, v " << v << endl;
}

Matrix::Matrix(const Matrix& matrix)
{
	if (n > 0, m > 0)
	{
		n = matrix.n;
		m = matrix.m;
		if (matrix.v == NULL)
			v = NULL;
		else
		{
			v = new double*[n];
			for (int i = 0; i < n; i++)
				v[i] = new double[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				v[i][j] = matrix.v[i][j];
		{

		}
	}
	else
	{
		n = 0;
		m = 0;
		v = NULL;
	}
	cout << "copy constr " << this << endl;
	cout << "copy constr, v " << v << endl;
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

double Matrix::Get(int i, int j)
{
	if (i < n && i>=0 && j < m && j>=0)
		return v[i][j];
	return 0;
}

void Matrix::Set(int i, int j, double d)
{
	if (i < n && i>=0 && j < m && j>=0)
		v[i][j] = d;
	else return;
}

bool Matrix::FillMatrix()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = i + j;
	return true;
}

Matrix* Matrix::AddMatrix(const Matrix &matr)
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

Matrix* Matrix::MulMatrix(const Matrix &matr)
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
//	cout << "this=" << this << endl;
//	cout << "v=" << v << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << v[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void Fun(const Matrix m)
{
	m.PrintMatrix();
}

void CheckMatrix()
{/*
	Matrix *ptm = new Matrix(3, 4);
	double d = 0;
	for (int i = 0; i < ptm->GetN(); i++)
		for (int j = 0; j < ptm->GetM(); j++)
		{
			cin >> d;
			ptm->Set(i, j, d);
		}

	ptm->PrintMatrix();*/

	    Matrix m1(3, 3);
		Matrix m2(3, 3);
		m1.FillMatrix();
		m2.FillMatrix();
		m1.PrintMatrix();

		Matrix* m3 = m1.AddMatrix(m2);
		m3->PrintMatrix();

		Matrix* m4 = m1.MulMatrix(*m3);
		m4->PrintMatrix();

		delete m3;
		delete m4;


	cin.get();
	cin.get();
}

