#pragma once
#include<iostream>
#include<list>
#include"Student.h"
using namespace std;
class Student;

class AbstractTeacher{
protected:
    list<Student*> students;
public:
    string action;
    virtual void attach(Student*) = 0;
    virtual void detach(Student*) = 0;
    virtual void notify() = 0;
};

class Teacher :public AbstractTeacher {
    void attach(Student* student);
    void detach(Student* student);
    void notify();
};