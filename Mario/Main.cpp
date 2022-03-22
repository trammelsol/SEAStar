#include"Mario.h"
#include"animation.h"
using namespace std;

int main() {
	std::unique_ptr<Mario> mario(new Mario());
	mario->SetCoin(20);
	//SmallMario GotMushroom ->SuperMario GotFireFlower ->FireMario GotFeather ->CapeMario
	Action();
	mario->GotMushroom();
	mario->ReportCoin();
	Action();
	mario->GotFireFlower();
	mario->ReportCoin();
	Action();
	mario->GotFeather();
	mario->ReportCoin();
	Action();
	mario->GotMushroom();
	mario->ReportCoin();
	return 0;
}