#include"Adapter.h"
using std::cout;
using std::endl;

Adapter::Adapter(US_Socket* usasocket){
	if (usasocket == nullptr){
		cout << "please poll in" <<endl;
	}
	target = "US";
} 

Adapter::Adapter(CN_Socket* cnsocket){
	if (cnsocket == nullptr){
		cout << "please poll in" <<endl;
	}
	target = "CN";
}

void Adapter::Socket_Plug(const string& plug)const {
	if (plug == target) {
		cout << "Poll In Directly No Need to Change !" << endl;
		cout << "--------------------------------------" << endl;
		return;
	}
	else if (plug == "US") {
		cout << US_Socket::Input() << endl;
		cout << US_Socket::Vol() << endl;
		cout<<"--------------------------------------" << endl;
		return;
	}
	else if (plug == "CN") {
		cout << CN_Socket::Input() << endl;
		cout << CN_Socket::Vol() << endl;
		cout << "--------------------------------------" << endl;
		return;
	}
	else
		cout<<"Wrong Input !" << endl;
}