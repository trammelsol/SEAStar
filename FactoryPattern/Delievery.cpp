#include"ClassDecaler_Delievry.h"

std::string Ship::Deliever() const {
	std::string result = "SeaTransport : Transport by Ship";
	return result;
}

std::string Truck::Deliever() const {
	std::string result = "RoadTransport : Transport by Truck";
	return result;
}

std::string Airplane::Deliever() const {
	std::string result = "AirTransport : Transport by Airplane";
	return result;
}

std::string Logistics::PlanDeliever() const {
	Transport* transport = this->CreateTransport();
	std::string result = "Logistics:Deliever goods by" + transport->Deliever();
	delete transport;
	return result;
}

Transport* SeaLogistics::CreateTransport() const {
	return new Ship();
}

Transport* RoadLogistics::CreateTransport() const {
	return new Truck();
}

Transport* AirLogistics::CreateTransport() const {
	return new Airplane();
}