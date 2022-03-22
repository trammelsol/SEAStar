#include"Mario.h"

int main() {
	std::unique_ptr<Mario> mario(new Mario());
	//SmallMario GotMushroom ->SuperMario GotFireFlower ->FireMario GotFeather ->CapeMario
	mario->GotMushroom();
	mario->ReportCoin();
	mario->GotFireFlower();
	mario->ReportCoin();
	mario->GotFeather();
	mario->ReportCoin();
	return 0;
}