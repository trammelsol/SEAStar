#include"Student.h"

Student::Student(string name, AbstractTeacher* sub){
    this->name = name;
    this->sub = sub;
}

void StockStudent::update(){
    cout << name << " Receive Message: " << sub->action << endl;
    if (sub->action == "assign schoolwork"){
        cout << "   answer : I will finish the schoolwork on time !" << endl;
    }
    else if (sub->action == "finish class") {
        cout << "   answer : Goodbye teacher,Thank you for your teaching !" << endl;
    }
}