#pragma once
#ifndef BIGLEAF_H
#define BIGLEAF_H
#include <iostream>
#include<string>
#include "Student.h"
using namespace std;;

class BigLeaf : public Student{
public:
	BigLeaf(string ID, int score, int money, float background):Student(ID,score,money,background){}
	void ShowSchool(){
		cout << "Student " << ID << " is BigLeaf student." << endl;
	}
};



#endif // !BIGLEAF_H
