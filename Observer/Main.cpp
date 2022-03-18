#include"students.h"
#include"teacher.h"

int main(){
	std::unique_ptr<Abstractteacher>teacherA(new TeacherA());
	std::unique_ptr<Abstractteacher>teacherB(new TeacherB());
	std::unique_ptr<AbstractStudent>studentA(new StudentA("A1"));
	std::unique_ptr<AbstractStudent>studentB(new StudentB("B1"));
	//add teacher on the subscribe list  
	studentA->addTeacher(teacherA.get());
	studentA->addTeacher(teacherB.get());
	studentB->addTeacher(teacherB.get());
	cout << "----------------------------" << endl;
	//to push message
	teacherA->punish("I'm thacherA");
	cout << "----------------------------" << endl;
	teacherB->punish("I'm thacherB");
	cout << "----------------------------" << endl;
	//to remove teacher the only teacher you can delete is B
	cout << "Tips:The Next Input is 'B'" << endl;
	cout << "----------------------------" << endl;
	studentB->removeMe();
	cout<<"After delete :" << endl;
	teacherB->punish("I'm thacherB");
}