#include"LuckyNumber.h"
#include"Proxy.h"

int main(){
	//auto proxy = std::make_unique<Proxy>();
	std::unique_ptr<Proxy>proxy(new Proxy());
	int a = proxy->ProxyGenerate("Pig");//1469
	std::cout << a << endl;
	int b = proxy->ProxyGenerate("Dog");//2057
	std::cout << b << endl;
	int c = proxy->ProxyGenerate("Dog");//2057
	std::cout << c << endl;
	int d = proxy->ProxyGenerate("Tiger");//1368
	std::cout << d << endl;
    return 0;
}