#pragma once
#include"Socket.h"
#include<iostream>
class Adapter : public US_Socket, public CN_Socket{
private:
	US_Socket* us_socket_;
	CN_Socket* cn_socket_;
public:
	Adapter(US_Socket* usasocket);
	Adapter(CN_Socket* cnsocket);


	std::string US_Input() const;
	std::string CN_Input() const;
	std::string CN_110V() const;
	std::string US_220V() const;
};