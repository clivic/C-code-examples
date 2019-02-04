#include "HAUI.h"

// main function
bool DoOperation(char command, HAUI &ui);
char GetCommand(HAUI &ui);

int main()
//	The Hold'n'Attack game
//	Uses:	The class HAStruct
//			together with function DoOperation, GetCommand.
{
	HAUI ui;
	ui.UIDisplay();
	while (DoOperation(GetCommand(ui), ui));

	//// Random number test
	//Random random(false);
	//random.RandomInt(1, 100);
	//int resNum = random.RandomInt(1, 100); cout << resNum << endl;
	//for (int i = 0; i < 100; i++)
	//{
	//	resNum = random.RandomInt(1, 100); cout << resNum << endl;
	//}
	//return 0;
}

char GetCommand(HAUI &ui)
//	Pre:	difficulty should be in 1 ~ 9.
//	Post:	if not valid, continue prompting user to input
//			else return the command.
{
	char ch;		//command
	
	switch (ui.GetLanguage())
	{
	case ENG:
		cout << "Select command and press <Enter>: " << flush;	break;
	case CNT:
		cout << "請輸入指令並按<Enter>鍵: ";	break;
	case CNS:
		cout << "请输入指令并按<Enter>键: "; break;
	}
	cin >> ch;
	ch = tolower(ch);
	while (ch != 'm' && ch != 'l' && ch != 'd' && ch != 's'
		&& ch != 'h' && ch != 'q')
	{
		switch (ui.GetLanguage())
		{
		case ENG:
			cout << "Please enter a valid option, or press [H] for help:" << flush; break;
		case CNT:
			cout << "選擇不合法，請重新鍵入或按[h]鍵打開幫助選單: " << flush;	break;
		case CNS:
			cout << "选择不合法，请重新输入或按[h]键查看帮助: " << flush; break;
		}
		cin >> ch;
		ch = tolower(ch);
	}
	return ch;
}

bool DoOperation
(char command, HAUI &ui)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	
	switch (command)
	{
	case 'm':
		ui.ChangeMode();
		break;

	case'l':
		ui.SetLanguage();
		break;

	case'd':
		ui.SetDify();
		break;

	case's':
		ui.Fight();
		break;

	case'h':
		ui.UIDisplay();
		break;

	case 'q':
		ui.Quit();
		return false;
	}
	return true;
}
