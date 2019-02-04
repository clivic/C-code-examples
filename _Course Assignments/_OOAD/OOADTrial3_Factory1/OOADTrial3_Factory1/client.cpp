#include "Factory.h"
#include "Widget.h"

#define MOTIF

void main()
{
	Factory* factory;  //面向接口编程  
#ifdef MOTIF //通过配置，灵活创建
	factory = new MotifFactory; //具体工厂
#else // WINDOWS
	factory = new WindowsFactory;
#endif  
	// w 是抽象产品指针，可以指向任意具体产
	//品。由具体工厂去产生 具体产品
	Widget* w = factory->CreateBtn();
	w->Draw();
}