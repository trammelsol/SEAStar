#include"Socket.h"
#include"Adapter.h"
using std::cout;
using std::endl;

int main() {
	while (true) {
		string US_CN;
		cout << "Choose Which Socket You Have : US or CN ? " << endl;
		cout << "OR Press Q to EXIT" << endl;
		cin>>US_CN;
		if (US_CN == "US") {
			std::unique_ptr<US_Socket> usa(new US_Socket());
			cout << usa->Input() << endl;
			cout << usa->Vol() << endl;
			cout << "--------------------------------------" << endl;
			std::shared_ptr <Adapter> adapter(new Adapter(usa.get()));
			cout << "Choose Which Plug You Want to Poll : US or CN ?" << endl;
			cin >> US_CN;
			adapter->Socket_Plug(US_CN);
		}
		else if (US_CN == "CN") {
			std::unique_ptr<CN_Socket> cn(new CN_Socket());
			cout << cn->Input() << endl;
			cout << cn->Vol() << endl;
			cout << "--------------------------------------" << endl;
			std::shared_ptr <Adapter> adapter(new Adapter(cn.get()));
			cout << "Choose Which Plug You Want to Poll : US or CN ?" << endl;
			cin >> US_CN;
			adapter->Socket_Plug(US_CN);
		}
		else {
			cout << "Input Finish System Quit !" << endl;
			break;
		}
	}
	return 0;
}