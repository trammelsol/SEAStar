#pragma once
#include<iostream>
using std::cout;
using std::endl;

class Transport {
public:
	virtual ~Transport() {};
	virtual std::string Deliever() const = 0;
};

class Ship : public Transport {
public:
	std::string Deliever() const override;
};

class Truck : public Transport {
public:
	std::string Deliever() const override;
};

class Airplane : public Transport {
public:
	std::string Deliever() const override;
};

class Logistics {
public:
	virtual ~Logistics() {};
	virtual Transport* CreateTransport() const = 0;
	std::string PlanDeliever() const;
};

class SeaLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};

class RoadLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};

class AirLogistics : public Logistics {
public:
	Transport* CreateTransport() const override;
};