#ifndef _GMATRIX_H
#define _GMATRIX_H
#include <iostream>
#include <cmath>
using namespace std;
class GMatrix
{
public:
	GMatrix(int r = 2, int c = 2);
	GMatrix(GMatrix &m);
	~GMatrix();
	void GetValue(void);
	void SetTranslationValue(int a,int b);
	void SetRotateThree(void);
	void SetScaleThree(void);
	void SetoneThree(int a, int b);
	int GetX();
	int GetY();
	GMatrix operator =(const GMatrix &m);
	GMatrix operator +(GMatrix &m);
	GMatrix operator -(GMatrix &m);
	GMatrix operator *(GMatrix &m);
	double operator ()(int x, int y);
	GMatrix rev(void);
	friend ostream & operator <<(ostream & out, GMatrix &m);
private:
	int row;
	int col;
	double  **p;
};
#endif // !


