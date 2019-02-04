#ifndef FACTORY
#define FACTORY

#include <iostream>
#include "Widget.h"

class Factory
{
public :
	virtual Widget* CreateBtn();

};

class MotifFactory : public Factory
{
public :
	Widget* CreateBtn();
};

class WindowsFactory : public Factory
{
public:
	Widget* CreateBtn();
};

#endif