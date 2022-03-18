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

class StudentA :public AbstractStudent{
private:
	Abstractteacher* teacher_;
	list<Abstractteacher*> ListSA;
	string number_ = "A1";
public:
	StudentA(string number);
	void getNotify(const string& assignment, const string& teachername) override;
	void removeMe() ;
	string getNumber() const override;
	void addTeacher(Abstractteacher* teacher) override;
};

class StudentB :public AbstractStudent{
private:
	Abstractteacher* teacher_;
	list<Abstractteacher*> ListSB;
	string number_;
public:
	StudentB(string number);
	void getNotify(const string& assignment, const string& teachername) override;
	void removeMe() ;
	string getNumber() const override;
	void addTeacher(Abstractteacher* teacher) override;
};