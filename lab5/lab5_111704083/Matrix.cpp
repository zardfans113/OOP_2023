#include "Matrix.h"

//TODO: Implement the constructors.
Matrix::Matrix():x1(0),x2(0),y1(0),y2(0) {}
Matrix::Matrix(float a, float b, float c, float d):x1(a),x2(b),y1(c),y2(d) {}
void Matrix::readFile(const char* fileName) {
	ifstream inputFile;
	inputFile.open(fileName);
	ofstream out;
	out.open("output.txt");
	char op;
	while (inputFile >> op) {
		Matrix a, b;
		inputFile >> a >> b;
		if (op == '+') out << a + b << endl;
		else if(op == '*')out  << a * b << endl;
	}
	//if (out.fail()) cout << "fail to open the file" << endl;
	//cout << "success" << endl;
	//TODO: Read the input file here.
}

void Matrix::reset() {
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	//TODO: reset all the data member.
}

Matrix Matrix::operator +(Matrix b) {
	return Matrix(x1 + b.x1, x2 + b.x2, y1 + b.y1, y2 + b.y2);
}
Matrix Matrix::operator *(Matrix b) {
	Matrix c;
	c.x1 = x1 * b.x1 + x2 * b.y1;
	c.x2 = x1 * b.x2 + x2 * b.y2;
	c.y1 = y1 * b.x1 + y2 * b.y1;
	c.y2 = y1 * b.x2 + y2 * b.y2;
	   return c;
	//TODO: perform * opearion overloading
}

ifstream& operator >> (ifstream& in, Matrix& i) {
	in >> i.x1 >> i.x2 >> i.y1 >> i.y2;
	return in;
	//TODO: perform input overloading
}
ostream& operator << (ostream& out, const Matrix& i) {
	cout << "[";
	cout << fixed << setprecision(2) << setw(7) << i.x1;
	cout << fixed << setprecision(2) << setw(7) << i.x2;
	cout << fixed << setprecision(2) << setw(7) << i.y1;
	cout << fixed << setprecision(2) << setw(7) << i.y2;
	cout	<< "]" << endl;
	return out;
	//TODO: perform output overloading
	//Hint: You can use 'setw()' to set the length of the number.
	//      You can use 'fixed' to make the floating point output displayed in decimal point representation.
	//      You can use 'setprecision()' to set the number of decimal places to be output.
	//      Three functions of above is in iomanip header file.
}
