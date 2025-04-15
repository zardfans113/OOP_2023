#pragma once
#include<algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<vector>
#include <sstream>
#include<cstdlib>
using namespace std;

class DateComparator {
private:
	int year1, year2;
	int month1, month2;
	int day1, day2;
	int difference;
	ifstream in;

	//You can add any variable if you need.
public:
	DateComparator();
	void readFile(const char *filename);
	void setOrder();
	void setDifference();
	bool isLeapYear(int year_);
	void print();
	//You can add any function if you need.
};
