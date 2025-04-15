#pragma once
#ifndef STUDENT_H
#include<iostream>
#include<string>
using namespace std;;

class Student {
public:
	string ID;
	int score, money;
	float background;
	Student(string ID, int score, int money, float background) :ID(ID), score(score), money(money), background(background) {}
	void printAllInfo() {
		cout << "ID : " << ID << endl;
		cout << "Score : " << score << endl;
		cout << "Money : " << money << endl;
		cout << "Background : " << background << endl;
	};
	virtual void ShowSchool() = 0;
	string getID() { return ID; }
};
#endif

