#include "GMatrix.h"
GMatrix::GMatrix(int r, int c)
{
	int i;
	row = r;
	col = c;
	p = new double*[row];
	for (i = 0; i < row; i++)
		*(p + i) = new double[col];
}


GMatrix::GMatrix(GMatrix &m)
{
	int i, j;
	row = m.row;
	col = m.col;
	p = new double*[row];
	for (i = 0; i < row; i++)
		*(p + i) = new double[col];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(p + i) + j) = *(*(m.p + i) + j);
}


GMatrix::~GMatrix()
{
	int i;
	for (i = 0; i < row; i++)
		delete[] * (p + i);
	delete[]p;
}


void GMatrix::GetValue(void)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> *(*(p + i) + j);
}
void GMatrix::SetTranslationValue(int a, int b)
{
	p[0][0] = 1;
	p[0][1] = 0;
	p[0][2] = 0;

	p[1][0] = 0;
	p[1][1] = 1;
	p[1][2] = 0;

	p[2][0] = a;
	p[2][1] = b;
	p[2][2] = 1;
}
void GMatrix::SetRotateThree(void)
{
	double M_PI = 3.1415926;
	double angle = M_PI / 2.0; // 90度，转换为弧度
	double cosTheta = cos(angle);
	double sinTheta = sin(angle);
	p[0][0] = cosTheta; p[0][1] = -sinTheta; p[0][2] = 0.0;
	p[1][0] = sinTheta; p[1][1] = cosTheta; p[1][2] = 0.0;
	p[2][0] = 0.0; p[2][1] = 0.0; p[2][2] = 1.0;
}
void GMatrix::SetScaleThree(void)
{
	p[0][0] = 0.5;
	p[0][1] = 0;
	p[0][2] = 0;

	p[1][0] = 0;
	p[1][1] = 0.5;
	p[1][2] = 0;

	p[2][0] = 0;
	p[2][1] = 0;
	p[2][2] = 1;
}
void GMatrix::SetoneThree(int a, int b)
{
	p[0][0] = a;
	p[0][1] = b;
	p[0][2] = 1;
}
int  GMatrix::GetX()
{
	return p[0][0];
}
int  GMatrix::GetY()
{
	return p[0][1];
}
GMatrix GMatrix::operator =(const GMatrix &m)
{
	if (this == &m) {
		return *this;
	}
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(p + i) + j) = *(*(m.p + i) + j);
	return(*this);
}
GMatrix GMatrix:: operator +(GMatrix &m)
{
	int i, j;
	GMatrix  a(row, col);
	if (row != m.row || col != m.col)
		throw 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(a.p + i) + j) = *(*(p + i) + j) + *(*(m.p + i) + j);
	return(a);
}


GMatrix GMatrix::operator -(GMatrix &m)
{
	int i, j;
	GMatrix  a(row, col);
	if (row != m.row || col != m.col)
		throw 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(a.p + i) + j) = *(*(p + i) + j) - *(*(m.p + i) + j);
	return(a);
}


GMatrix GMatrix::operator *(GMatrix &m)
{
	if (col != m.row)
		throw 0;
	int i, j, k;
	double  sum;
	GMatrix  a(row, m.col);
	for (i = 0; i < row; i++)
		for (j = 0; j < m.col; j++)
		{
			for (k = 0, sum = 0; k < col; k++)
				sum = sum + *(*(p + i) + k) * *(*(m.p + k) + j);
			*(*(a.p + i) + j) = sum;
		}
	return(a);
}


double GMatrix::operator ()(int x, int y)
{
	if (x > row || y > col)
		throw 0.0;
	return(*(*(p + x - 1) + y - 1));
}


GMatrix GMatrix::rev(void)
{
	int i, j;
	GMatrix  a(col, row);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(a.p + j) + i) = *(*(p + i) + j);
	return(a);
}


ostream & operator <<(ostream & out, GMatrix &m)
{
	int i, j;
	for (i = 0; i < m.row; i++)
	{
		for (j = 0; j < m.col; j++)
			out << *(*(m.p + i) + j) << " ";
		out << endl;
	}
	return(out);
}
