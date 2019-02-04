#include "Factory.h"
#include "Widget.h"

#define MOTIF

void main()
{
	Factory* factory;  //����ӿڱ��  
#ifdef MOTIF //ͨ�����ã�����
	factory = new MotifFactory; //���幤��
#else // WINDOWS
	factory = new WindowsFactory;
#endif  
	// w �ǳ����Ʒָ�룬����ָ����������
	//Ʒ���ɾ��幤��ȥ���� �����Ʒ
	Widget* w = factory->CreateBtn();
	w->Draw();
}