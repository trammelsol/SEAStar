#include"Mario.h"

Mario::Mario() {
    coin = 0;
    this->state = &SmallMario::GetInstance();
}

void Mario::SetState(MarioState* state) {
    this->state = state;
}

void Mario::SetCoin(int numberOfCoins) {
    std::cout << "Got Coins: " << numberOfCoins << std::endl;
    coin += numberOfCoins;
}

void Mario::ReportCoin() {
    std::cout << "Total Coin: " << coin << std::endl;
}

void Mario::GotMushroom() {
    this->state->GotMushroom(this);
};

void Mario::GotFireFlower() {
    this->state->GotFireFlower(this);
};

void Mario::GotFeather() {
    this->state->GotFeather(this);
};

void SmallMario::GotMushroom(Mario* mario) {
    mario->SetCoin(100);
    mario->SetState(&SuperMario::GetInstance());
}

void SmallMario::GotFireFlower(Mario* mario) {
    mario->SetCoin(200);
    mario->SetState(&FireMario::GetInstance());
}

void SmallMario::GotFeather(Mario* mario) {
    mario->SetCoin(300);
    mario->SetState(&CapeMario::GetInstance());
}

void SuperMario::GotMushroom(Mario* mario) {
    mario->SetCoin(50);
}

void SuperMario::GotFireFlower(Mario* mario) {
    mario->SetCoin(300);
    mario->SetState(&FireMario::GetInstance());
}

void SuperMario::GotFeather(Mario* mario) {
    mario->SetCoin(400);
    mario->SetState(&CapeMario::GetInstance());
}

void FireMario::GotMushroom(Mario* mario) {
    mario->SetCoin(100);
}

void FireMario::GotFireFlower(Mario* mario) {
    mario->SetCoin(100);
}

void FireMario::GotFeather(Mario* mario) {
    mario->SetCoin(500);
    mario->SetState(&CapeMario::GetInstance());
}

void CapeMario::GotMushroom(Mario* mario) {
    mario->SetCoin(100);
}

void CapeMario::GotFireFlower(Mario* mario) {
    mario->SetCoin(100);
    mario->SetState(&FireMario::GetInstance());
}

void CapeMario::GotFeather(Mario* mario) {
    mario->SetCoin(100);
}