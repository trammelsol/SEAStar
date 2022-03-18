#include"Student.h"
#include"Teacher.h"

int main()
{
    //Create IObserver:Teacher
    AbstractTeacher* Teacher_Ma = new Teacher();
    AbstractTeacher* Teacher_Niu = new Teacher();
    //Create Observer:Student
    Student* Student1 = new StockStudent("June", Teacher_Niu);
    Student* Student2 = new StockStudent("Mary", Teacher_Niu);
    Student* Student3 = new StockStudent("Jack", Teacher_Ma);
    Student* Student4 = new StockStudent("March", Teacher_Ma);
    //Publish message
    Teacher_Niu->attach(Student1);
    Teacher_Niu->attach(Student2);
    Teacher_Niu->action = "assign schoolwork";
    Teacher_Niu->notify();
    cout << endl;
    Teacher_Niu->action = "finish class";
    Teacher_Niu->notify();
    cout << endl;
    Teacher_Ma->attach(Student3);
    Teacher_Ma->attach(Student4);
    Teacher_Ma->action = "assign schoolwork";
    Teacher_Ma->notify();
    cout << endl;
    Teacher_Ma->detach(Student4);
    Teacher_Ma->action = "finish class";
    Teacher_Ma->notify();
    delete Teacher_Ma, Teacher_Niu;
    delete Student1, Student2, Student3, Student4;
    return 0;
}