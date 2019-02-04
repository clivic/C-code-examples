#include <string>
#include "Computer.h"
#include "SimpleDate.h"
#ifndef IR_H
#define IR_H

class InstallRecord : public Computer
{
private:
	std::string location;
	SimpleDate date;

public:
	InstallRecord(
		/* in */ std::string newName,
		/* in */ std::string newBrand,
		/* in */ std::string newModel,
		/* in */ int		 newSpeed,
		/* in */ std::string newSerial,
		/* in */ int		 newNumber,
		/* in */ std::string newLocation,
		/* in */ SimpleDate newDate);
	std::string GetLocation() const;
	SimpleDate  GetDate() const;
	void Write() const;
};

#endif