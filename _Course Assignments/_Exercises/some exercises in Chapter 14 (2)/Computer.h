//*********************************************************
//Computer class specification
//*********************************************************
#include <string>

using namespace std;

class Computer
{
public:
	Computer();
	
	Computer(
		/* in */ std::string newName,
		/* in */ std::string newBrand,
		/* in */ std::string newModel,
		/* in */ int		 newSpeed,
		/* in */ std::string newMaterial,
		/* in */ int	newNumber);

	std::string GetName() const;
	std::string GetBrand() const;
	std::string GetModel() const;
	int			GetSpeed() const;
	std::string GetSerial() const;
	int			GetNumber() const;
	void		Write() const;

private:
	std::string name;
	std::string brand;
	std::string model;
	int			speed;
	std::string serialNumber;
	int			inventoryNumber;
};