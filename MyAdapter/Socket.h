#pragma once
#include<iostream>
using std::cout;
using std::endl;

class US_Socket{
public:
	virtual ~US_Socket() {};
	std::string US_Input() const;
	std::string US_220V() const;
};

class CN_Socket{
public:
	virtual ~CN_Socket() {};
	std::string CN_Input() const;
	std::string CN_110V() const;
};