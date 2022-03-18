#include"teacher.h"

void TeacherA::addStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	cout << "By TeacherA Add Successfully . Hi I'm Student :" << abstractstudent->getNumber() << endl;
	listA.push_back(abstractstudent);
}

void TeacherA::removeStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Delete error !" << endl;
		return;
	}
	listA.remove(abstractstudent);
	cout <<getTName()<<"£ºYou have deleted !" << endl;
}

void TeacherA::punish(string assignmentA){
	string name = "TeacherA";
	this->assignmentA = assignmentA;
	notify(name);
}

void TeacherA::notify(string name){
	cout << "There are " << listA.size() << " students in the list" << endl;
	for (auto it : listA){
		it->getNotify(assignmentA,name);
	}
}

void TeacherB::addStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	listB.push_back(abstractstudent);
	cout << "By TeacherB Add Successfully . Hi I'm Student :" << abstractstudent->getNumber() << endl;
}

void TeacherB::removeStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Delete error !" << endl;
		return;
	}
	listB.remove(abstractstudent);
	cout <<getTName()<<"£ºYou have deleted !" << endl;
}

void TeacherB::punish(string assignmentB){
	string name = "TeacherB";
	this->assignmentB = assignmentB;
	notify(name);
}

void TeacherB::notify(string name){
	cout << "There are " << " " << listB.size() << " students in the list" << endl;
	for (auto it : listB){
		it->getNotify(assignmentB,name);
	}
}


string TeacherA::getTName(){
	return name;
}

string TeacherB::getTName(){
	return name;
}
