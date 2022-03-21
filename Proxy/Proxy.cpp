#include"Proxy.h"

bool Proxy::CheckAccess() const{
    cout<<"+++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Enter The Passward :" << endl;
    int PsdCin;
    std::cin >> PsdCin;
    if (psd == PsdCin){
        cout << "Welcome User : Admin !" << endl;
        cout << "***************************************" << endl;
        return true;
    }else{
        cout << "Enter as a Customer !" << endl;
        cout << "---------------------------------------" << endl;
    }
    return true;
}

Proxy::Proxy(){
    if (nullptr == LRU) {
        LRU = std::make_unique<LRUCache>(10);
    }
    LRU->Set("Rat", 1469);
    LRU->Set("Ox", 2057);
    LRU->Set("Tiger", 1368);
    LRU->Set("Rabbit", 1368);
    LRU->Set("Pig", 1469);
}

int Proxy::ProxyGenerate(std::string animal){
    if (nullptr == luckynumber){
        luckynumber = std::make_unique<LuckyNumber>();
    }
    if (CheckAccess()){
        int TempLRU = LRU->Get(animal);
        if (TempLRU == -1){
            int TempLuck = luckynumber->generate(animal);
            LRU->Set(animal, TempLuck);
            cout << "Find it on the LuckyNumber !" << endl;
            cout<<"Get the Number :     ";
            return TempLuck;
        }else{
            cout << "Find it on the Cache !" << endl;
            cout << "Get the Number :     ";
            return TempLRU;
        }
    }
}