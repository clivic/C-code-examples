#include "Factory.h"

Widget* Factory::CreateBtn()
{
	return NULL;
}

Widget* MotifFactory::CreateBtn()
{
	cout << "Created an MotifFactory button." << endl;
	Widget *w; w = new MotifButton();
	return w;
}

Widget* WindowsFactory::CreateBtn()
{
	cout << "Created an WindowsFactory button." << endl;
	Widget* w; w = new WindowsButton();
	return w;
}