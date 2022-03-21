#pragma once
#include"Socket.h"
#include<iostream>
using namespace std;
class Adapter : public US_Socket, public CN_Socket{
private:
	string target;
public:
	Adapter(US_Socket* usasocket);
	Adapter(CN_Socket* cnsocket);
	void Socket_Plug(const string& plug)const;
};