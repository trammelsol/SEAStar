#include"Teacher.h"

void Teacher::attach(Student* student) {
    students.push_back(student);
}

void Teacher::detach(Student* student) {
    list<Student*>::iterator iter = students.begin();
    while (iter != students.end()){
        if ((*iter) == student){
            students.erase(iter);
        }
        ++iter;
    }
}

void Teacher::notify(){
    list<Student*>::iterator iter = students.begin();
    while (iter != students.end()){
        (*iter)->update();
        ++iter;
    }
}