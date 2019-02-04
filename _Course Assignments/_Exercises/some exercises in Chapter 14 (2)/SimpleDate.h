//*************************************************************************************************
//this is the simpledate class specification, it represents a date fomat of YYYY/MM/DD
//*************************************************************************************************

#ifndef SD_H
#define SD_H

class SimpleDate
{
private:
	int year;
	int month;
	int day;
public:
	SimpleDate();
	SimpleDate(
		/* in */ int usingYear,
		/* in */ int usingMonth,
		/* in */ int usingDay);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	void Set(
		/* in */ int usingYear,
		/* in */ int usingMonth,
		/* in */ int usingDay);
	void FormalWrite() const;
	void Write() const;
};

#endif