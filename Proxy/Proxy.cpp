#include"Proxy.h"

bool Proxy::CheckAccess() const{
    cout<<"+++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Enter The Passward :" << endl;
    int psd_cin;
    std::cin >> psd_cin;
    if (psd == psd_cin){
        cout << "Welcome User : Admin !" << endl;
        cout << "***************************************" << endl;
        return true;
    }else{
        cout << "Enter as a Customer !" << endl;
        cout << "---------------------------------------" << endl;
    }
}

Proxy::Proxy(){
    if (nullptr == LRU) {
        LRU = std::make_unique<LRUCache>(5);
    }
    LRU->Set("Rat", 1469);
    LRU->Set("Ox", 2057);
    LRU->Set("Tiger", 1368);
    LRU->Set("Rabbit", 1368);
    LRU->Set("Pig", 1469);
}

int Proxy::Proxy_Generate(std::string animal){
    if (nullptr == luckynumber){
        luckynumber = std::make_unique<LuckyNumber>();
    }
    if (CheckAccess()){
        if (!LRU->Get(animal)){
            int temp = luckynumber->generate(animal);
            LRU->Set(animal, temp);
            cout<<"Get the Number :     ";
            return temp;
        }else{
            std::cout << "Find it on the Cache !" << std::endl;
            cout << "Get the Number :     ";
            return LRU->Get(animal);
        }
    }
}