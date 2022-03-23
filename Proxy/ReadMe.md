<<<<<<< HEAD
# seastar---Proxy

## 介绍  
在某些情况下，客户不能或者不想直接访问一个对象时，可以通过寻找一个中介来帮他完成访问对象的任务。例如自己不愿意去上课时，可以找一个人A代替你去上课，A就扮演了代理者的角色。在软件设计中，代理模式的使用也是为了完成这样的一种机制。  
由于某些原因需要给某对象提供一个代理以控制对该对象的访问。这时，访问对象不适合或者不能直接引用目标对象，代理对象作为访问对象和目标对象之间的中介。  
#1.远程代理，也就是为一个对象在不同的地址空间提供局部代表。这样可以隐藏一个对象存在于不同地址空间的事实。  
#2.虚拟代理，是根据需要创建开销很大的对象。通过他来存放实例化需要很长时间的真实对象。  
#3.安全代理，用来控制真实对象访问时的权限。  
#4.智能指引，是指当调用真实的对象时，代理处理另外一些事。  
![alt Proxy](https://github.com/trammelsol/SEAStar/blob/master/Proxy/Proxy.png "Class SketchMap")  

###advantage:    
. 代理模式在客户端与目标对象之间起到一个中介作用和保护目标对象的作用  
. 代理对象可以扩展目标对象的功能  
. 代理模式能将客户端与目标对象分离，在一定程度上降低了系统的耦合度；  

###disadvantage    
. 在客户端和目标对象之间增加一个代理对象，会造成请求处理速度变慢  
. 增加了系统的复杂度  

##task    
>使用LUckyNumber for C++实现代理模式  
>需要包含如下实现细节：  
>• 使用智能指针管理对象；  
>• 包含代理模式应用场景；  
>• 延迟初始化  
>• 数据缓存  
>• 权限控制（对某些输入参数做一些判断等等）  
>• 不允许使用第三方库，可以使用STL  

## 软件架构  
```C++
//代理类，包含一个LuckyNumber 对象指针，和一个用LRU算法实现的缓存对象指针
#Proxy.h
class Proxy {
private:
	int psd = 123;//对输入用户权限进行判断的预置管理员密码
	std::unique_ptr<LRUCache> LRU = nullptr;//缓存
	std::unique_ptr<LuckyNumber> luckynumber = nullptr;//LuckyNumber
public:
	Proxy();//对LRU延迟初始化
	bool CheckAccess() const;//权限判断
	int ProxyGenerate(std::string animal);//对LuckyNumber初始化，并在LRU缓存中查找对象，没有的话去LuckyNumber中找并插入本地缓存
};

#Proxy.cpp
Proxy::Proxy(){
    if (nullptr == LRU) {
        LRU = std::make_unique<LRUCache>(10);//对LRU延迟初始化
    }
    LRU->Set("Rat", 1469);//本地LRU缓存中预置5个map 键值对
    LRU->Set("Ox", 2057);
    LRU->Set("Tiger", 1368);
    LRU->Set("Rabbit", 1368);
    LRU->Set("Pig", 1469);
}

int Proxy::ProxyGenerate(std::string animal){
    if (nullptr == luckynumber){
        luckynumber = std::make_unique<LuckyNumber>();//对LuckyNumber初始化
    }
    if (CheckAccess()){//权限判断
        int TempLRU = LRU->Get(animal);//在LRU缓存中查找对象
        if (TempLRU == -1){
            int TempLuck = luckynumber->generate(animal);//本地LRU缓存没有改键值对，去LuckyNumber中找并插入本地缓存
            LRU->Set(animal, TempLuck);
            cout << "Find it on the LuckyNumber !" << endl;
            cout<<"Get the Number :     ";
            return TempLuck;
        }else{//在本地LRU缓存中找到
            cout << "Find it on the Cache !" << endl;
            cout << "Get the Number :     ";
            return TempLRU;
        }
    }
}

#Cache.h
struct ListNode{
	std::string key;//name
	int value;//number
	ListNode* pPre;
	ListNode* pNext;
	ListNode(std::string key, int value) : key(key), value(value), pPre(nullptr), pNext(nullptr) {}
    /*{key = key;value = value;pPre = nullptr;pNext = nullptr}
    遇到的坑：使用该方法初始化会失败*/
};//双向链表作为LRU缓存的存储结构

//最近最少使用算法。它会将最近不常用的缓存数据淘汰掉，是一种Cache替换算法。
//unordered_map存储数据(考虑到map的键为string 用unordered_map) ，实现查找效率O(1)，双向链表实现算法逻辑
/*
算法逻辑： 1.新数据会插入到链表头部
          2.当缓存数据被访问，将该缓存数据移到链表头部
          3.当新数据插入时达到缓存上限了，将尾部数据删除掉（也就是最近最少使用的），新数据放在头部。
*/
class LRUCache{
private:
	int capacity;    //Cache capacity
	ListNode* pHead;   //Head Node
	ListNode* pTail;   //Tail Node
	unordered_map<std::string , ListNode*>  mp;   //mp use to store data
public:
	LRUCache(int size);
	~LRUCache();//析构链表
	void Remove(ListNode* pNode);//移除节点
	void SetHead(ListNode* pNode);//把常访问节点放置到链表头部
	void Set(std::string key, int value);//节点初始化以及赋值
	int Get(std::string key);//按键查找
	int GetSize();//获取map的容量
};

#Cache.cpp
LRUCache::~LRUCache(){
    //** map释放内存时，先释放内部new的内存，在释放map的内存
	unordered_map<std::string, ListNode*>::iterator it = mp.begin();
	for (; it != mp.end();){
		delete it->second;
		it->second = nullptr;
		mp.erase(it++); //**it++ 放在其他任何一个地方都会导致其迭代器失效
	}
	delete pHead;
	pHead = nullptr;
	delete pTail;
	pTail = nullptr;
}
//** 这里只是移除，并不删除节点
void LRUCache::Remove(ListNode* pNode){
    // 如果是头节点
	if (pNode->pPre == nullptr){
		pHead = pNode->pNext;
		pHead->pPre = nullptr;
	}
    // 如果是尾节点
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
//  将节点放到头部，最近用过的数据要放在队头。
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
// * 插入数据，如果存在就只更新数据
void LRUCache::Set(std::string key, int value){
	unordered_map<std::string, ListNode*>::iterator it = mp.find(key);
	if (it != mp.end()){
		ListNode* Node = it->second;
		Node->value = value;
		Remove(Node);
		SetHead(Node);
	}else{
		ListNode* NewNode = new ListNode(key, value);
		if (int(mp.size()) >= capacity){        //存储空间满了以后移除尾结点并删除，再把新节点放到链表头
			unordered_map<std::string, ListNode*>::iterator it = mp.find(pTail->key);
			Remove(pTail);
			delete it->second;
			mp.erase(it);
		}
		SetHead(NewNode);
		mp[key] = NewNode;
	}
	cout<<"#####	Add new item to the Cache	#####" << endl;
}
//获取缓存里的数据
int LRUCache::Get(std::string key){
	unordered_map<std::string , ListNode*>::iterator it = mp.find(key);
	if (it != mp.end()){//缓存中有该数据，将该数据放到链表头部
		ListNode* Node = it->second;
		Remove(Node);
		SetHead(Node);
		return Node->value;
	}else{//缓存中没有该数据
		return -1;
	}
}

```
## 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

## 使用说明
```C++
1.  auto proxy = std::make_unique<Proxy>(); or  std::unique_ptr<Proxy>proxy(new Proxy());        //use auto_ptr to create an Proxy::object  
2.  auto(int) object = proxy->ProxyGenerate(string Key);  std::cout << object << endl;      //to find the item based on key 
3.  first find in the LRUCache , if find failed , go to LuckyNumber find 
```
## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request
