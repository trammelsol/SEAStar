#include"ClassDecaler_Furniture.h"

std::string Modern_Chair::MessageChair() const{
	return "A Chair built from Modern Factory";
}

std::string Victorian_Chair::MessageChair() const {
	return "A Chair built from Victorian Factory";
}

std::string ArtDeco_Chair::MessageChair() const {
	return "A Chair built from ArtDeco Factory";
}

std::string Modern_Sofa::MessageSofa() const {
	return "A Sofa built from Modern Factory";
}

std::string Victorian_Sofa::MessageSofa() const {
	return "A Sofa built from Victorian Factory";
}

std::string ArtDeco_Sofa::MessageSofa() const {
	return "A Sofa built from ArtDeco Factory";
}

std::string Modern_CoffeeTable::MessageCoffeeTable() const {
	return "A CoffeeTable built from Modern Factory";
}

std::string Victorian_CoffeeTable::MessageCoffeeTable() const{
	return "A CoffeeTable built from Victorian Factory";
}

std::string ArtDeco_CoffeeTable::MessageCoffeeTable() const {
	return "A CoffeeTable built from ArtDeco Factory";
}

Chair* Factory_ArtDeco::CreateChair() const {
	return new ArtDeco_Chair();
}
Sofa* Factory_ArtDeco::CreateSofa() const {
	return new ArtDeco_Sofa();
}
CoffeeTable* Factory_ArtDeco::CreateCoffeeTable() const {
	return new ArtDeco_CoffeeTable();
}

Chair* Factory_Victorian::CreateChair() const {
	return new Victorian_Chair();
}
Sofa* Factory_Victorian::CreateSofa() const {
	return new Victorian_Sofa();
}
CoffeeTable* Factory_Victorian::CreateCoffeeTable() const {
	return new Victorian_CoffeeTable();
}

Chair* Factory_Modern::CreateChair() const {
	return new Modern_Chair();
}
Sofa* Factory_Modern::CreateSofa() const {
	return new Modern_Sofa();
}
CoffeeTable* Factory_Modern::CreateCoffeeTable() const {
	return new Modern_CoffeeTable();
}