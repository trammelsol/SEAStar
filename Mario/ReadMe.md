#<<<<<<< HEAD
# seastar---State

## 介绍
在GOF的《设计模式:可复用面向对象软件的基础》一书中对状态模式是这样说的：允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类。状态模式的重点在于状态转换，很多时候，对于一个对象的状态，我们都是让这个对象包含一个状态的属性，这个状态属性记录着对象的具体状态，根据状态的不同使用分支结构来执行不同的功能，就像上面的代码那样处理；就像上面说的，类中存在大量的结构类似的分支语句，变得难以维护和理解。状态模式消除了分支语句，就像工厂模式消除了简单工厂模式的分支语句一样，将状态处理分散到各个状态子类中去，每个子类集中处理一种状态，这样就使得状态的处理和转换清晰明确。

## 使用场合
###在以下两种情况下均可使用State模式：

1. 一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为；
2. 一个操作中含有庞大的多分支的条件语句，且这些分支依赖于该对象的状态。这个状态通常用一个或多个枚举常量表示。通常有多个操作包含这一相同的条件结构。State模式将每一个条件分支放入一个独立的类中。这使得你可以根据对象自身的情况将对象的状态作为一个对象，这一对象可以不依赖于其它对象而独立变化。


![alt Mario](https://gitee.com/trammelsol/seastar/raw/master/Mario/Mario.png "Class SketchMap")  

###advantage:  
. 封装了转换规则。
. 枚举可能的状态，在枚举状态之前需要确定状态种类。
. 将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为。
. 允许状态转换逻辑与状态对象合成一体，而不是某一个巨大的条件语句块。

###disadvantage  
. 状态模式的使用必然会增加系统类和对象的个数。
. 状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱。
. 状态模式对“开闭原则”的支持并不太好，对于可以切换状态的状态模式，增加新的状态类需要修改那些负责状态转换的源代码，否则无法切换到新增状态；而且修改某个状态类的行为也需修。


##task  
>参考 Mario for C++实现状态模式  
>需要包含新的事件：  
>• 吃羽毛 GotFeather；  
>需要包含新的状态：  
>• 斗篷马里奥 CapeMario

## 软件架构
```C++

//声名四种马里奥状态 SmallMario、SuperMario、FireMario、CapeMario
template<typename T>
class Singleton{
public:
    static T& GetInstance(){
        static T instance;
        return instance;
    }
    Singleton(T&&) = delete;
    Singleton(const T&) = delete;
    void operator= (const T&) = delete;
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

class  MarioState;

class Mario {
private:
    MarioState* state;
    int coin;
public:
    Mario();
    void SetState(MarioState* state);
    void SetCoin(int numberOfCoins);
    void ReportCoin();
    void GotMushroom();
    void GotFireFlower();
    void GotFeather();
};

class MarioState {
public:
    virtual void GotMushroom(Mario* mario) = 0;
    virtual void GotFireFlower(Mario* mario) = 0;
    virtual void GotFeather(Mario* mario) = 0;
};

class SmallMario : public MarioState, public Singleton<SmallMario> {
public:
    void GotMushroom(Mario* mario);
    void GotFireFlower(Mario* mario);
    void GotFeather(Mario* mario);
};

class SuperMario : public MarioState, public Singleton<SuperMario> {
public:
    void GotMushroom(Mario* mario);
    void GotFireFlower(Mario* mario);
    void GotFeather(Mario* mario);
};

class FireMario : public MarioState, public Singleton<FireMario> {
public:
    void GotMushroom(Mario* mario);
    void GotFireFlower(Mario* mario);
    void GotFeather(Mario* mario);
};

class CapeMario : public MarioState, public Singleton<FireMario> {
public:
    void GotMushroom(Mario* mario);
    void GotFireFlower(Mario* mario);
    void GotFeather(Mario* mario);
};

#Mario.cpp
//根据状态转换图进行状态转换
void CapeMario::GotMushroom(Mario* mario) {
    mario->SetCoin(100);
}

void CapeMario::GotFireFlower(Mario* mario) {
    mario->SetCoin(100);
    mario->SetState(&FireMario::GetInstance());
}

void CapeMario::GotFeather(Mario* mario) {
    mario->SetCoin(100);
}

#animation.h
#pragma once
#include<iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
void Action(void);//借助windows.h实现一个伪动画展示

```
## 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

## 使用说明
```C++
1.  std::unique_ptr<Mario> mario(new Mario());//use auto_ptr to create a Mario::object
2.  mario->SetCoin(20);// to set original coin
3.  Action(); //animation show
```
## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request