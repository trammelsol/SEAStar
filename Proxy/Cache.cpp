#include"Cache.h"

LRUCache::LRUCache(int size) {
	m_capacity = size;
	pHead = nullptr;
	pTail = nullptr;
}

LRUCache::~LRUCache(){
	map<std::string, ListNode*>::iterator it = mp.begin();
	for (; it != mp.end();){
		delete it->second;
		it->second = nullptr;
		mp.erase(it++);
	}
	delete pHead;
	pHead = nullptr;
	delete pTail;
	pTail = nullptr;
}

void LRUCache::Remove(ListNode* pNode){
	if (pNode->pPre == nullptr){
		pHead = pNode->pNext;
		pHead->pPre = nullptr;
	}
	else if (pNode->pNext == nullptr){
		pTail = pNode->pPre;
		pTail->pNext = nullptr;
	}else{
		if (pNode->pPre->pNext || pNode->pNext->pPre) {
			pNode->pPre->pNext = pNode->pNext;
			pNode->pNext->pPre = pNode->pPre;
		}
	}
}

void LRUCache::SetHead(ListNode* pNode) {
	pNode->pNext = pHead;
	pNode->pPre = nullptr;
	if (pHead == nullptr){
		pHead = pNode;
	}else{
		pHead->pPre = pNode;
		pHead = pNode;
	}
	if (pTail == nullptr){
		pTail = pHead;
	}
}

void LRUCache::Set(std::string key, int value){
	map<std::string, ListNode*>::iterator it = mp.find(key);
	if (it != mp.end()){
		ListNode* Node = it->second;
		Node->m_value = value;
		Remove(Node);
		SetHead(Node);
	}else{
		ListNode* NewNode = new ListNode(key, value);
		if (int(mp.size()) >= m_capacity){
			map<std::string, ListNode*>::iterator it = mp.find(pTail->m_key);
			Remove(pTail);
			delete it->second;
			mp.erase(it);
		}
		SetHead(NewNode);
		mp[key] = NewNode;
	}
}

int LRUCache::Get(std::string key){
	map<std::string , ListNode*>::iterator it = mp.find(key);
	if (it != mp.end()){
		ListNode* Node = it->second;
		Remove(Node);
		SetHead(Node);
		return Node->m_value;
	}else{
		return -1;
	}
}

int LRUCache::GetSize(){
	return mp.size();
}