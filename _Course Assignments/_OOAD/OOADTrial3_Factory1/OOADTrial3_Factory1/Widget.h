#ifndef WIDGET
#define WIDGET

#include <iostream>

using namespace std;

class Widget
{
public :
	virtual void Draw();
};

class MotifButton : public Widget
{
public:
	void Draw();
};

class WindowsButton : public Widget
{
public:
	void Draw();
};

#endif