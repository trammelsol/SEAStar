#pragma once
#include<iostream>
using namespace std;

class Observer{
public:
	virtual ~Observer() {};
	virtual void getNotify(const string& assignment,const string& teachername)=0 ;
	virtual void removeMe() =0 ;
	virtual string getNumber() const = 0;
};