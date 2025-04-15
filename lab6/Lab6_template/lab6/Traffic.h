#pragma once
#ifndef TRAFFIC_H
#define TRAFFIC_H
#include <iostream>
#include "Student.h"

class Traffic : public Student {
public:
	Traffic(string ID, int score, int money, float background):Student(ID,score,money,background){}
	void ShowSchool() {
		cout << "Student " << ID << " is Traffic student." << endl;
	}
};
#endif // !TRAFFIC_H

