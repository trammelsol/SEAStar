#pragma once

#include<iostream>
using std::cout;
using std::endl;

class Chair {
public:
	virtual ~Chair() {};
	virtual std::string MessageChair() const = 0;
};

class Modern_Chair : public Chair {
public:
	std::string MessageChair() const override;
};

class Victorian_Chair : public Chair {
	std::string MessageChair() const override;
};

class ArtDeco_Chair : public Chair {
	std::string MessageChair() const override;
};

class Sofa {
public:
	virtual ~Sofa() {};
	virtual std::string MessageSofa() const = 0;
};

class Modern_Sofa : public Sofa {
public:
	std::string MessageSofa() const override;
};

class Victorian_Sofa : public Sofa {
public:
	std::string MessageSofa() const override;
};

class ArtDeco_Sofa : public Sofa {
public:
	std::string MessageSofa() const override;
};

class CoffeeTable {
public:
	virtual ~CoffeeTable() {};
	virtual std::string MessageCoffeeTable() const = 0;
};

class Modern_CoffeeTable : public CoffeeTable {
public:
	std::string MessageCoffeeTable() const override;
};

class Victorian_CoffeeTable : public CoffeeTable {
public:
	std::string MessageCoffeeTable() const override;
};

class ArtDeco_CoffeeTable : public CoffeeTable {
public:
	std::string MessageCoffeeTable() const override;
};

class Factory {
public:
	virtual Chair *CreateChair() const = 0;
	virtual Sofa *CreateSofa() const = 0;
	virtual CoffeeTable *CreateCoffeeTable() const = 0;
};

class Factory_ArtDeco : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
CoffeeTable* CreateCoffeeTable() const override;
};

class Factory_Victorian : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
	CoffeeTable* CreateCoffeeTable() const override;
};

class Factory_Modern : public Factory {
public:
	Chair* CreateChair() const override;
	Sofa* CreateSofa() const override;
	CoffeeTable* CreateCoffeeTable() const override;
};
