#include"students.h"
#include"teacher.h"

int main(){
	std::unique_ptr<Abstractteacher>Teacher_Mao(new Teacher("Mao"));
	std::unique_ptr<Abstractteacher>Teacher_Niu(new Teacher("Niu"));
	std::unique_ptr<AbstractStudent>Student_A(new Student("SA1"));
	std::unique_ptr<AbstractStudent>Student_B(new Student("SB1"));
	//add teacher on the subscribe list  
	Student_A->addTeacher(Teacher_Mao.get());
	Student_A->addTeacher(Teacher_Niu.get());
	Student_B->addTeacher(Teacher_Niu.get());
	cout << "----------------------------" << endl;
	//to push message
	Teacher_Mao->punish("I'm Thacher_Mao");
	cout << "----------------------------" << endl;
	Teacher_Mao->punish("Thacher_Mao push the second message");
	cout << "----------------------------" << endl;
	Teacher_Niu->punish("I'm Thacher_Niu");
	cout << "----------------------------" << endl;
	Teacher_Niu->punish("Thacher_Niu push the second message");
	cout << "----------------------------" << endl;
	//to remove teacher the only teacher you can delete is B
	cout << "Tips:The Next Input is 'Niu'" << endl;
	cout << "----------------------------" << endl;
	Student_B->removeMe();
	cout<<"After delete :" << endl;
	Teacher_Niu->punish("I'm Thacher_Niu");
}