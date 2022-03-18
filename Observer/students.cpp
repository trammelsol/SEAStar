#include"students.h"
StudentA::StudentA(string number){
	this->number_ = number;
}

StudentB::StudentB(string number) {
	this->number_ = number;
}

void StudentA::getNotify(const string& assignment, const string& teachername){
	cout <<"StudentA have received Teacher :"<<teachername<< " publish to StudentA---->" << assignment << endl;
}

void StudentB::getNotify(const string& assignment, const string& teachername){
	cout << "StudentB have received Teacher :" << teachername << " publish to StudentB---->" << assignment << endl;
}

void StudentA::removeMe(){
	cout << "Choose the Teacher you want to delete :" << endl;
	string select;
	cin >> select;
	int size = ListSA.size();
	for (auto it : ListSA){
		if (it->getTName() == select){
			it->removeStduent(this);
			cout << "Delete successfully !" << endl;
			break;
		}
		size--;
	}

	if (size == 0){
		cout << "Teacher don't exist !" << endl;
	}
}

void StudentB::removeMe(){
	cout << "Choose the Teacher you want to delete :" << endl;
	string select;
	cin >> select;
	int size = ListSB.size();
	for (auto it : ListSB){
		if (it->getTName() == select){
			it->removeStduent(this);
			cout << "Delete successfully !" << endl;
			break;
		}
		size--;
	}
	if (size == 0){
		cout << "Teacher don't exist !" << endl;
	}
}

string StudentA::getNumber()const {
	return this->number_;
}

string StudentB::getNumber()const {
	return this->number_;
}

void StudentA::addTeacher(Abstractteacher* teacher) {
	if (teacher == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	this->teacher_ = teacher;
	this->ListSA.push_back(teacher);
	this->teacher_->addStduent(this);
}

void StudentB::addTeacher(Abstractteacher* teacher){
	if (teacher == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	this->teacher_ = teacher;
	this->ListSB.push_back(teacher);
	this->teacher_->addStduent(this);
}