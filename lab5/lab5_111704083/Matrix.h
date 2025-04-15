#ifndef Matrix_H
#define Matrix_H 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Matrix
{
	/*
	Matrix format:
		[ x1 x2
		  y1 y2 ]
	*/

private:
	float x1, x2, y1, y2;
public:
	//constructor
	Matrix();	//default constructor
	Matrix(float a, float b, float c, float d);

	//read the data from the file
	void readFile(const char* fileName);

	//clear the data member
	void reset();

	//overload 
	Matrix operator +(Matrix b);
	Matrix operator *(Matrix b);

	//input and output overload
	friend ifstream& operator >> (ifstream& in, Matrix& i);
	friend ostream& operator << (ostream& out, const Matrix& i);
};
#endif