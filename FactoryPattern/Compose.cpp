#include"Compose.h"

void Compose_Class::ClientCode() {
	std::unique_ptr< Chair>p_chair(std::move(factory->CreateChair()));
	std::unique_ptr< Sofa>p_sofa(std::move(factory->CreateSofa()));
	std::unique_ptr< CoffeeTable>p_coffeetable(std::move(factory->CreateCoffeeTable()));
	cout << p_chair->MessageChair() << endl;
	cout << p_sofa->MessageSofa() << endl;
	cout << p_coffeetable->MessageCoffeeTable() << endl;
	cout << delievery->PlanDeliever() << endl;
}

void Compose_Class::ClientCode(int product_cho) {
	switch (product_cho) {
	case 1:{
		std::unique_ptr< Chair>p_chair(std::move(factory->CreateChair()));
		cout << p_chair->MessageChair() << endl;
		cout << delievery->PlanDeliever() << endl;
		break;
	}
	case 2:{
		std::unique_ptr< Sofa>p_chair(std::move(factory->CreateSofa()));
		cout << p_chair->MessageSofa() << endl;
		cout << delievery->PlanDeliever() << endl;
		break;
	}
	case 3:{
		std::unique_ptr< CoffeeTable>p_chair(std::move(factory->CreateCoffeeTable()));
		cout << p_chair->MessageCoffeeTable() << endl;
		cout << delievery->PlanDeliever() << endl;
		break;
	}
	default:{
		std::unique_ptr< CoffeeTable>p_chair(std::move(factory->CreateCoffeeTable()));
		cout << p_chair->MessageCoffeeTable() << endl;
		cout << delievery->PlanDeliever() << endl;
	}
			}
}

Compose_Class::~Compose_Class() {
	delete factory;
	delete delievery;
	cout <<endl<< "The object has been distoried , program exit normally" << endl;
}

Compose_Class::Compose_Class(int factory_cho, int delievery_cho) {
	switch (factory_cho) {
	case 1:
		factory = new Factory_Victorian();
		break;
	case 2:
		factory = new Factory_Modern();
		break;
	case 3:
		factory = new Factory_ArtDeco();
		break;
	default:
		factory = new Factory_Modern();
	}

	switch (delievery_cho) {
	case 1:
		delievery = new RoadLogistics();
		break;
	case 2:
		delievery = new SeaLogistics();
		break;
	case 3:
		delievery = new AirLogistics();
		break;
	default:
		delievery = new RoadLogistics();
	}
}