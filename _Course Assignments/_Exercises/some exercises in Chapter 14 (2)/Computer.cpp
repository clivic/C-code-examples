//*********************************************************
//Computer class implementation
//*********************************************************
#include "Computer.h"
#include <string>
#include <iostream>			//for output
#include <iomanip>			//for write format

using namespace std;

Computer::Computer()
{
	name = "newName";
	brand = "newBrand";
	model = "newModel";
	speed = 0;
	serialNumber = "newSerial";
	inventoryNumber = 0;
}

Computer::Computer(
	/* in */ std::string newName,
	/* in */ std::string newBrand,
	/* in */ std::string newModel,
	/* in */ int		 newSpeed,
	/* in */ std::string newSerial,
	/* in */ int		 newNumber)
{
	name = newName;
	brand = newBrand;
	model = newModel;
	speed = newSpeed;
	serialNumber = newSerial;
	inventoryNumber = newNumber;
}

std::string Computer::GetName() const
{
	return name;
}

std::string Computer::GetBrand() const
{
	return brand;
}

std::string Computer::GetSerial() const
{
	return serialNumber;
}

std::string Computer::GetModel() const
{
	return model;
}

int Computer::GetNumber() const
{
	return inventoryNumber;
}

int Computer::GetSpeed() const
{
	return speed;
}

void Computer::Write() const
{
	cout << "For this computer:" << endl
		 << left << setw(8) << "Name:" << name << endl
		 << setw(8) << "Brand:" << brand << endl
		 << setw(8) << "Model:" << model << endl
		 << setw(8) << "Speed:" << speed << endl
		 << setw(8) << "Serial number:" << serialNumber << endl
		 << setw(8) << "Inventory number:" << inventoryNumber << endl << endl;
	
}