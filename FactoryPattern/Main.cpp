#include"Compose.h"
#include<cstdlib>

using std::cin;

int main() {
	cout << "Press key 1 to generate an order by yourserf or key 2 to generate an order by God:" << endl;
	cout<<"1 or 2 :?" << endl;
	int choice = 0;
	cin >> choice;
	switch(choice){
	case 1: {
		int factory_cho, delievery_cho, product=0;
		cout<<"Press key 1 to choose Victorian factory;Press key 2 to choose Modern factory;Press key 3 to choose ArtDeco factory:" << endl;
		cin >> factory_cho;
		cout <<"Press key 1 to choose delievery by truck;Press key 2 to choose delievery by ship;Press key 3 to choose delievery by airplane:" << endl;
		cin >> delievery_cho;
		std::unique_ptr<Compose_Class>Demo(new Compose_Class(factory_cho,delievery_cho));
		cout << "Press key 1 to buy a chair;Press key 2 to buy a sofa;Press key 3 to buy a coffeetable:" << endl;
		cin >> product;
		Demo->ClientCode(product);
		cout << endl;
		break;
	}
	case 2:
		while (cin.get() != ' ') {
			cout << "I guess you want to generate orders like this: " << endl;
			std::unique_ptr<Compose_Class>Demo(new Compose_Class(rand() % 3 + 1, rand() % 3 + 1));
			Demo->ClientCode();
			cout << endl;
			cout << "Are you satisfied ? Press space to exit or other to try again:" << endl;
		}
		break;
	default:
		break;
	}	
	return 0;
}