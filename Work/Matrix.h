#ifndef _MATRIX_H
#define	_MATRIX_H

class Matrix
{
protected:	
	int n;
	int m;
	double **v;
public:
	Matrix();
	Matrix(int n, int m);
	Matrix(const Matrix& matr);
	~Matrix();
	int GetN() { return n; };
	int GetM() { return m; };
	double Get(int i, int j);
	void Set(int i, int j, double d);
	bool InitializeUnitary();
	Matrix& TriangleMatrix();					 // �������� � ������������ ����
	Matrix Transpose();							 // ���������������
	double Determinant();						 // �����������
	Matrix& FillMatrix();						 // ��������� ������� ��������
	Matrix AddMatrix(const Matrix &matr);
	Matrix MulMatrix(const Matrix &matr);
	void PrintMatrix();
	Matrix operator+(const double chislo);
	Matrix operator+(const Matrix &matr);
	Matrix& operator-();
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	Matrix operator-(const Matrix &matr);
	Matrix operator*(const Matrix &matr);
	Matrix& operator=(const Matrix &matr);
	friend void PrintMatrix(const Matrix &matr);
	double* operator[](int i) { if (i < n) return v[i]; };
	double& operator()(int i, int j) { return v[i][j]; };

private:

};

class EMatrix: public Matrix
{

public:
	EMatrix();
	EMatrix(int n);
	~EMatrix();

private:

};

void CheckMatrix();

#endif
