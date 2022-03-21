#pragma once
#include<iostream>
#include<map>
using namespace std;

struct ListNode{
	std::string m_key;//name
	int m_value;//number
	ListNode* pPre;
	ListNode* pNext;
	ListNode(std::string key, int value){
		m_key = key;
		m_value = value;
		pPre = nullptr;
		pNext = nullptr;
	}
};

class LRUCache{
private:
	int m_capacity;    //Cache capacity
	ListNode* pHead;   //Head Node
	ListNode* pTail;   //Tail Node
	map<std::string , ListNode*>  mp;   //mp use to store data
public:
	LRUCache(int size);
	~LRUCache();
	void Remove(ListNode* pNode);
	void SetHead(ListNode* pNode);
	void Set(std::string key, int value);
	int Get(std::string key);
	int GetSize();
};