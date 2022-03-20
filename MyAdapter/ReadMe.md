# seastar---Adapter

## 介绍
Adapter适配器模式  
作用：将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。  
分为类适配器模式和对象适配器模式。  
系统的数据和行为都正确，但接口不符时，我们应该考虑使用适配器，目的是使控制范围之外的一个原有对象与某个接口匹配。适配器模式主要应用于希望复用一些现存的类，但是接口又与复用环境要求不一致的情况。  
想使用一个已经存在的类，但如果它的接口，也就是它的方法和你的要求不相同时，就应该考虑用适配器模式。  
比如购买的第三方开发组件，该组件接口与我们自己系统的接口不相同，或者由于某种原因无法直接调用该组件，可以考虑适配器。  
![alt Observer](https://gitee.com/trammelsol/seastar/raw/master/MyAdapter/Adapter.png "Class SketchMap")  

###advantage:  
. 单一职责原则  
. 开闭原则  
. 将目标类和适配者类解耦，解决了目标类和适配者类接口不一致的问题  
  
###disadvantage  
. 对象适配器的缺点：与类适配器模式相比，要想置换适配者类的方法就不容易。  

##task  
>电源双向适配器  
> 参照课程中电源适配器例子，实现一个可双向转换的适配器； 
>设计需求:  
>• 功能1： 美标插头转换国标插头  
>• 功能2： 国标插头转换美标插头  
>• 功能3： 支持双向转换，二合一  
>加分项  
>• 拓展电源适配器功能，比如：电压转换  

## 软件架构
```C++
#class US_Socket and CN_Socket inherit from Class Socket  
class Socket {
public:
	virtual ~Socket() {};
	virtual std::string Input() const=0;//to rule the Input Type
	virtual std::string Vol() const=0;to rule the Input Voltage Type
};
class US_Socket :public Socket{
public:
	std::string Input() const override;
	std::string Vol() const override;
};

class CN_Socket :public Socket{
public:
	std::string Input() const override;
	std::string Vol() const override;
};
#class Adapter to achieve US_to_CN or CN_to_US
class Adapter : public US_Socket, public CN_Socket{
private:
	string target;//to mark the Ipnut type
public:
	Adapter(US_Socket* usasocket);
	Adapter(CN_Socket* cnsocket);
	void Socket_Plug(const string& plug)const;//to choose no need to change or need to change
};

```
## 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

## 使用说明
```C++
1.  std::unique_ptr<US_Socket> usa(new US_Socket());        //use auto_ptr to create an US_Socket::object  
2.  std::unique_ptr<CN_Socket> cn(new CN_Socket());      //use auto_ptr to create an CN_Socket::object  
3.  cout << usa->Input() << endl;  //to show Input Type  
4.  cout << usa->Vol() << endl;  //to show Input Voltage Type  
5.  adapter->Socket_Plug(object); //by compare the class of input object to choose how to change Adapter Type
```
## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


## 特技