#pragma once
#include<iostream>
#include<list>
#include "Observer.h"
using namespace std;

class Abstractteacher{
public:
	virtual void addStduent(Observer* abstractstudent) = 0;
	virtual void removeStduent(Observer* abstractstudent) = 0;
	virtual void punish(string assignmentA) = 0;
	virtual void notify(string name) = 0;
	virtual string getTName() = 0;
};

class TeacherA :public Abstractteacher{
private:
	list<Observer*> listA;
	string assignmentA;
	string name = "A";
public:
	void addStduent(Observer* abstractstudent) override;
	void removeStduent(Observer* abstractstudent) override;
	void punish(string assignmentA ) override;
	void notify(string name) override;
	string getTName() ;
};

class TeacherB :public Abstractteacher{
private:
	list<Observer*> listB;
	string assignmentB;
	string name = "B";
public:
	void addStduent(Observer* abstractstudent) override;
	void removeStduent(Observer* abstractstudent) override;
	void punish(string assignmentB ) override;
	void notify(string name) override;
	string getTName();
};