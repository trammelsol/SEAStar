#pragma once
#include"ClassDecaler_Furniture.h"
#include"ClassDecaler_Delievry.h"

class Compose_Class {
private:
	Factory* factory;
	Logistics* delievery;
public:
	virtual ~Compose_Class();
	Compose_Class(int , int );
	void ClientCode();
	void ClientCode(int );

};