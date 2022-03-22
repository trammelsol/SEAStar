#pragma once
#include <stdio.h>
#include <iostream>

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