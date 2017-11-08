#ifndef _MATRIX_H
#define	_MATRIX_H

class Matrix
{
	int n;
	int m;
	double **v;
public:
	Matrix();
	Matrix(int n, int m);
	~Matrix();
	bool FillMatrix();
	Matrix* AddMatrix(Matrix &matr);
	Matrix* MulMatrix(Matrix &matr);
	void PrintMatrix();

private:

};

void CheckMatrix();

#endif
