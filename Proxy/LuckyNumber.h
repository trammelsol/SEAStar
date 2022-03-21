#pragma once
#include <iostream>
#include <map>

class Number {
public:
    virtual int generate(std::string animal) = 0;
};

class LuckyNumber : public Number {
public:
    int generate(std::string animal) override; 
};