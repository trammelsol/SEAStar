#include"LuckyNumber.h"
#include"Proxy.h"

int main(){
	//auto proxy = std::make_unique<Proxy>();
	std::unique_ptr<Proxy>proxy(new Proxy());
	int pig = proxy->ProxyGenerate("Pig");//1469
	std::cout << pig << endl;
	int dog = proxy->ProxyGenerate("Dog");//2057
	std::cout << dog << endl;
	int DogAdd = proxy->ProxyGenerate("Dog");//2057
	std::cout << DogAdd << endl;
	int tiger = proxy->ProxyGenerate("Tiger");//1368
	std::cout << tiger << endl;
    return 0;
}