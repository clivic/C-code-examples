#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:  

	Computer(
		/* in */ string newName,
		/* in */ string newBrand,
		/* in */ string newModel,
		/* in */ int	newSpeed,
		/* in */ string newMaterial,
		/* in */ int	newNumber);
	
	string GetName() const;
	string GetBrand() const;
	string GetModel() const;
	int	   GetSpeed() const;
	string GetMaterial() const;
	int	   GetNumber() const;
	void Write() const;

private:
	string name;
	string brand;
	string model;
	int speed;
	string serialNumber;
	int inventoryNumber;
};

class InstallRecord : public Computer
{
private:
	string location;
	SimpleDate date;
	
public:
	InstallRecord(
		/* in */ string newLocation
		/* in */ SimpleDate newDate);
	void GetLocation() const;
	void GetDate() const;
	void Write() const;
};

//*************************************************************************************************

//Computer class implementation
InstallRecord::Computer(	
	/* in */ string newName,
	/* in */ string newBrand,
	/* in */ string newModel,
	/* in */ int	newSpeed,
	/* in */ string newMaterial,
	/* in */ int	newNumber)
{
	name = newName;
	brand = newBrand;
	newModel;
	newSpeed;
	newMaterial;
}





