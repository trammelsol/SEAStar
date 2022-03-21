#include"Socket.h"

std::string US_Socket::Input() const{
	return "Input USA Standard Socket.";
}

std::string US_Socket::Vol()const {
	return "Voltage : 110V";
}

std::string CN_Socket::Input() const{
	return "Input CN Standard Socket.";
}

std::string CN_Socket::Vol() const{
	return "Voltage : 220V";
}