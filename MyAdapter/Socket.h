#pragma once
#include<iostream>
using std::cout;
using std::endl;

class Socket {
public:
	virtual ~Socket() {};
	virtual std::string Input() const=0;
	virtual std::string Vol() const=0;
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