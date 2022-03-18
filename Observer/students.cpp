#include"students.h"
Student::Student(string number){
	this->number_ = number;
}

void Student::getNotify(const string& assignment, const string& teachername){
	cout <<"Student have received Teacher :"<<teachername<< " publish to Student"<<getNumber() << "---->" << assignment << endl;
}

void Student::removeMe(){
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

string Student::getNumber()const {
	return this->number_;
}

void Student::addTeacher(Abstractteacher* teacher) {
	if (teacher == nullptr){
		cout << "Add error !" << endl;
		return;
	}
	int size = ListSA.size();
	for (auto it : ListSA) {
		if (it->getTName() == teacher->getTName()) {
			cout << "You have added the teacher and no need to add !" << endl;
			return;
		}
		size--;
	}
	this->teacher_ = teacher;
	this->ListSA.push_back(teacher);
	this->teacher_->addStduent(this);
}