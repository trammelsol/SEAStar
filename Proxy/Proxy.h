#pragma once
#include"LuckyNumber.h"
#include<memory>
#include"Cache.h"
#include"LuckyNumber.h"
using std::cout;
using std::endl;

class Proxy {
private:
	int psd = 123;
	std::unique_ptr<LRUCache> LRU = nullptr;
	std::unique_ptr<LuckyNumber> luckynumber = nullptr;
public:
	Proxy();
	bool CheckAccess() const;
	int ProxyGenerate(std::string animal);
};