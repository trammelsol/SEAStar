# seastar---Observer

## 介绍
观察者模式通常的叫法叫做订阅-发布模式，类似于报刊杂志的订阅，观察者和被观察者就是读者和邮局的关系，读者先要在邮局订阅想要的报刊，当报刊发行时，邮局会将报刊邮寄到读者家里。  
观察者（Observer）和被观察者（Listener）也是这种关系，Observer将自己attach到Listener中，当Listener触发时Notify所有Observer.
在观察者模式中，被观察者维护观察者对象的集合，当被观察者对象变化时，它会通知观察者。观察者模式主要是用于解决对象之间一对多的关系。
![lt text](https://images2015.cnblogs.com/blog/765168/201608/765168-20160814144941875-41772080.png "Class SketchMap")  

####advantage:
. 开闭原则  
. 依赖倒置原则  
. 运行时建立对象之间的联系  

###disadvantage  
. 目标与观察者之间的依赖关系并没有完全解除而且有可能出现循环引用  
. 当观察者对象很多时，通知的发布会花费很多时间，影响程序的效率  
. 订阅者的通知顺序可能是随机的  

##task  
>根据课件观察者模式系统类图，实现学生订阅多个老师，获取老师所发布作业的作业通知系统。  
>设计需求：  
>• 选用观察者模式实现；  
>• 该系统支持多同学订阅多老师的能力；  
>• 使用 C++ 编码完成  

## 软件架构
```C++
#class Observer  
class Observer{  
public:  
	virtual ~Observer() {};  
	virtual void getNotify(const string& assignment,const string& teachername)=0 ;  
	virtual void removeMe() =0 ;  
	virtual string getNumber() const = 0;  
};      //abstrat this class to resolve cross reference  


#class Student  
class AbstractStudent :public Observer{  
public:  
	virtual ~AbstractStudent() {};  
	virtual void getNotify(const string& assignment, const string& teachername) {};  
	virtual void removeMe() {};  
	virtual string getNumber()const = 0;  
	virtual void addTeacher(Abstractteacher* teacher) {};  
};  

class Student :public AbstractStudent{  
private:  
	Abstractteacher* teacher_;  
	list<Abstractteacher*> ListSA;//to store the teacher subscribe  
	string number_ = "A1";      //student's name  
public:  
	Student(string number);  
	void getNotify(const string& assignment, const string& teachername) override;       //to get notify  
	void removeMe() ;       //to cancel subscribe  
	string getNumber() const override;      //to get stduent's name  
	void addTeacher(Abstractteacher* teacher) override;     //add Teacher to subscribe list  
};  

#class Teacher  
class Teacher :public Abstractteacher{  
private:  
	list<Observer*> listA;  
	set<string>assignmentA;     //to solve repitition subscribe  
	string name = "A";      //Teacher's name  
public:  
	Teacher(string name);  
	void addStduent(Observer* abstractstudent) override;        //add student to subscribe list  
	void removeStduent(Observer* abstractstudent) override;     //remove stduent on the subscribe list  
	void punish(string assignmentA ) override;      //to punish message  
	void notify(string name) override;      //to notify student  
	string getTName() ;     //to get teacher's name  
};
```
## 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

## 使用说明
```C++
1.  std::unique_ptr<Abstractteacher>Teacher_Mao(new Teacher("Mao"));        //use auto_ptr to create an Teacher::object  
2.  std::unique_ptr<AbstractStudent>Student_A(new Student("SA1"));      //use auto_ptr to create an Student::object  
3.  Teacher::object use addStduent() to add student to subscribe list while Student::object use addTeacher()  
4.  Teacher::object use punish() to punish message and the student get it  
5.  Teacher::object use removeStduent() to remove stduent while Student::object use removeMe() to cancel subscribe  
```
## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


## 特技