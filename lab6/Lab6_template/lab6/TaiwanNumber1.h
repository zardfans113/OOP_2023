#pragma once
#ifndef TAIWANNUMBER1_H
#define TAIWANNUMBER1_H
#include<iostream>
#include"Student.h"

using namespace std;;
class TaiwanNumber1 : public Student {
public:
	TaiwanNumber1(string ID, int score, int money, float background):Student(ID,score,money,background){}
	void ShowSchool() {
		cout << "Student " << ID << " is TaiwanNumber1 student." << endl;
	}
};
#endif // !TAIWANNUMBER1_H
