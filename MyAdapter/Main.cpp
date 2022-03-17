#include"Socket.h"
#include"Adapter.h"
using std::cout;
using std::endl;

void UseUSAPlug(US_Socket* ussocket){
	cout<< ussocket->US_Input()<<endl;
}

void UseCNPlug(CN_Socket* cnsocket){
	cout<< cnsocket->CN_Input()<<endl;
}

void UseUSA220V(US_Socket* usasocket){
	cout << usasocket->US_220V()<<endl;
}

void UseCN110V(CN_Socket* cnsocket){
	cout << cnsocket->CN_110V()<<endl;
}

int main() {
	std::unique_ptr<US_Socket> usa(new US_Socket());
	cout << usa->US_Input() << endl;
	std::shared_ptr <Adapter> adapter(new Adapter(usa.get()));
	UseCNPlug(adapter.get());
	UseCN110V(adapter.get());
	cout << "-------------------------------------" <<endl;
	std::unique_ptr <CN_Socket> cn (new CN_Socket());
	cout << cn->CN_Input() << endl;
	std::unique_ptr <Adapter>adapter2(new Adapter(cn.get()));
	UseUSAPlug(adapter2.get());
	UseUSA220V(adapter2.get());
	cout << "-------------------------------------" << endl;
	return 0;

}