#pragma once
#include <iostream>
#include <list>
#include "Observer.h"
#include"teacher.h"
using namespace std;

class AbstractStudent :public Observer{
public:
	virtual ~AbstractStudent() {};
	virtual void getNotify(const string& assignment, const string& teachername) {};
	virtual void removeMe() {};
	virtual string getNumber()const = 0;
	virtual void addTeacher(Abstractteacher* teacher) {};
};

class Student :public AbstractStudent{
private:
	Abstractteacher* teacher_;
	list<Abstractteacher*> ListSA;
	string number_ = "A1";
public:
	Student(string number);
	void getNotify(const string& assignment, const string& teachername) override;
	void removeMe() ;
	string getNumber() const override;
	void addTeacher(Abstractteacher* teacher) override;
};