#pragma once
#include<iostream>
#include <unordered_map>
#include<string>
using namespace std;

struct ListNode{
	std::string key;//name
	int value;//number
	ListNode* pPre;
	ListNode* pNext;
	ListNode(std::string key="null", int value=0) {
		key = key;
		value = value;
		pPre = nullptr;
		pNext = nullptr;
	}
};

class LRUCache{
private:
	int capacity;    //Cache capacity
	ListNode* pHead;   //Head Node
	ListNode* pTail;   //Tail Node
	unordered_map<std::string , ListNode*>  mp;   //mp use to store data
public:
	LRUCache(int size);
	~LRUCache();
	void Remove(ListNode* pNode);
	void SetHead(ListNode* pNode);
	void Set(std::string key, int value);
	int Get(std::string key);
	int GetSize();
};