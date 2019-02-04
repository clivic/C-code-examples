//*********************************************************
//InstallRecord class implementation
//*********************************************************
#include "InstallRecord.h"
#include <iostream>			//for output
#include <iomanip>			//for write format

InstallRecord::InstallRecord(
	/* in */ std::string newName,
	/* in */ std::string newBrand,
	/* in */ std::string newModel,
	/* in */ int		 newSpeed,
	/* in */ std::string newSerial,
	/* in */ int		 newNumber,
	/* in */ std::string newLocation,
	/* in */ SimpleDate newDate)
	: Computer(	newName,	 newBrand,
				newModel,	 newSpeed,
				newSerial,	 newNumber)
{
	location = newLocation;
	date = newDate;
}

std::string InstallRecord::GetLocation() const
{
	return location;
}

SimpleDate InstallRecord::GetDate() const
{
	return date;
}

void InstallRecord::Write() const
{
	cout << "For this computer:" << endl
		<< left << setw(8) << "Name:" << GetName() << endl
		<< setw(8) << "Brand:" << GetBrand() << endl
		<< setw(8) << "Model:" << GetModel() << endl
		<< setw(8) << "Speed:" << GetSpeed() << endl
		<< setw(8) << "Serial number:" << GetSerial() << endl
		<< setw(8) << "Inventory number:" << GetNumber() << endl
		<< setw(8) << "Location:" << location << endl
		<< setw(8) << "Date:";
	date.Write();
	cout << endl << endl;
}