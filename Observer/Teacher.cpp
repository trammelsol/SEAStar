#include"teacher.h"

Teacher::Teacher(string name) {
	this->name = name;
}

void Teacher::addStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	int size = listA.size();
	for (auto it : listA) {
		if (it->getNumber() == abstractstudent->getNumber()) {
			cout << "You have Added the student and no need to add !" << endl;
			return;
		}
		size--;
	}
	listA.push_back(abstractstudent);
	cout << "Add By Teacher Successfully . Hi I'm Student :" << abstractstudent->getNumber() << endl;
}

void Teacher::removeStduent(Observer* abstractstudent){
	if (abstractstudent == nullptr){
		cout << "Delete error !" << endl;
		return;
	}
	listA.remove(abstractstudent);
	cout <<getTName()<<"£ºYou have deleted !" << endl;
}

void Teacher::punish(string assignmentA){
	this->assignmentA.insert(assignmentA);
	notify(getTName());
}

void Teacher::notify(string name){
	cout << "There are " << listA.size() << " students in the list" << endl;
	for (auto it : listA){
		for (auto it_ = assignmentA.cbegin(); it_ != assignmentA.cend(); it_++) {
			it->getNotify(*it_, name);
		}
	}
}

string Teacher::getTName(){
	return name;
}
