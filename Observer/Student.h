#pragma once
#include<iostream>
#include"Teacher.h"
using std::string;
using std::cout;

class AbstractTeacher;
class Student
{
protected:
    string name;
    AbstractTeacher* sub;
public:
    Student(string , AbstractTeacher* );
    virtual void update() = 0;
};
//specific Student
class StockStudent :public Student{
public:
    StockStudent(string name, AbstractTeacher* sub) :Student(name, sub){}
    void update();
};