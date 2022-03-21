#include"LuckyNumber.h"
#include"Proxy.h"

int main(){
	std::unique_ptr<Proxy>proxy(new Proxy());
	auto a = proxy->Proxy_Generate("Dog");
	std::cout << a << std::endl;
	auto b = proxy->Proxy_Generate("Dog");
	std::cout << b << std::endl;
    return 0;
}