#include"Adapter.h"
using std::cout;
using std::endl;

Adapter::Adapter(US_Socket* usasocket){
	if (usasocket == nullptr){
		cout << "please poll in" <<endl;
	}
     this->us_socket_ = usasocket;
} 

Adapter::Adapter(CN_Socket* cnsocket){
	if (cnsocket == nullptr){
		cout << "please poll in" <<endl;
	}
	this->cn_socket_ = cnsocket;
}

std::string Adapter::US_Input() const{
	return this->cn_socket_->CN_Input();
}

std::string Adapter::CN_Input() const{
	return this->us_socket_->US_Input();
}

std::string Adapter::CN_110V() const{
	return this->us_socket_->US_220V();
}

std::string Adapter::US_220V() const{
	return this->cn_socket_->CN_110V();
}