#pragma once
#ifndef PORKBALL_H
#include "Student.h"
#include "Traffic.h"
#include <string>
using namespace std;

class PorkBall {
public:
	PorkBall(string name, float speed) :name(name),speed(speed){}

	bool canRide(Student* student) {
		if (isTraffic(student)) return true;
		else return false;
		// use isTraffic to check whether the student can ride the porkball.
	}

private:
	string name;
	float speed;
	bool isTraffic(Student* student) {
		Traffic* traffic_student = dynamic_cast<Traffic*>(student);
		if (traffic_student) {
			cout << student -> getID() << " can ride porkball ";
			cout << name << ", the speed is " << speed << endl;
			return true;
		}
		else {
			cout << "error bad_cast" << endl;
			return false;
		}
		// use dynamic casting to check whether the student is a Traffic student. 
	}
};
#endif
