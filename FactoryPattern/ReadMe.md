# seastar-Factory

#### 介绍
##简单工厂模式 SimpleFactory Pattern  
###简单工厂模式并不是一个真正意义上的设计模式，它更像是一个变成的习惯用法。  
#![alt SimpleFactory](https://gitee.com/trammelsol/seastar/raw/master/FactoryPattern/SimpleFactory.png "简单工厂模式")  
```C++

class Transport;
class Ship : public Transport;
class Truck : public Transport;
//add class SimpleFactory to create specific transport
class SimpleFactory{
    public:
        Transport *CreateTransport(std::string type){
            Transport * transport;
            if(type == "sea"){
                transport = new Ship();
            }else if(type == "road"){
                transport = new Truck();
            }
            return transport;
        }
}

```  


##工厂方法模式 Factory Method Pattern  
###工厂方法模式是一种创建型设计模式。其在父类中提供一个创建对象的方法，允许子类决定实例化对象的类型  
#![alt FactoryMethod](https://gitee.com/trammelsol/seastar/raw/master/FactoryPattern/FactoryMethod.png "工厂方法模式")  
```C++
class Transport {
public:
	virtual ~Transport() {};
	virtual std::string Deliever() const = 0;
};

class Ship : public Transport {
public:
	std::string Deliever() const override;
};

class Truck : public Transport {
public:
	std::string Deliever() const override;
};

class Airplane : public Transport {
public:
	std::string Deliever() const override;
};

class Logistics {
public:
	virtual ~Logistics() {};
	virtual Transport* CreateTransport() const = 0;
	std::string PlanDeliever() const;
};

class SeaLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};

class RoadLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};

class AirLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};
```

##抽象工厂模式 Abstract Factory Pattern  
###抽象工厂模式是一种创建型设计模式它能创建一系列相关的对象， 而无需指定其具体类。  
#![alt AbstractFactory](https://gitee.com/trammelsol/seastar/raw/master/FactoryPattern/AbstractFactory.png "抽象工厂模式")  
```C++
class Factory {
public:
	virtual Chair *CreateChair() const = 0;
	virtual Sofa *CreateSofa() const = 0;
	virtual CoffeeTable *CreateCoffeeTable() const = 0;
};

class Factory_ArtDeco : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
CoffeeTable* CreateCoffeeTable() const override;
};

class Factory_Victorian : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
	CoffeeTable* CreateCoffeeTable() const override;
};

class Factory_Modern : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
	CoffeeTable* CreateCoffeeTable() const override;
};

```  
  


>家具工厂、物流合并
>使用场景：
>• 将本课中示例物流工厂、家具工厂进行合并，提供家具生产物流一条龙系统。
>设计需求：
>• 选用工厂设计模式，在兼容原有家具工厂方法的同时合并物流功能。

#### 软件架构
```C++
//to combine class Delievery and class Factory
#include"ClassDecaler_Furniture.h"
#include"ClassDecaler_Delievry.h"

class Compose_Class {
private:
	Factory* factory;
	Logistics* delievery;
public:
	virtual ~Compose_Class();
	Compose_Class(int , int );
	void ClientCode();
	void ClientCode(int );

};
```

#### 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

#### 使用说明

1.  std::unique_ptr<Compose_Class>Demo(new Compose_Class(factory_cho,delievery_cho));// to create an object with ability to create furniture and delievery
2.  object->ClientCode(product);//to product a set of furniture or specific chair/sofa/coffee_table
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技