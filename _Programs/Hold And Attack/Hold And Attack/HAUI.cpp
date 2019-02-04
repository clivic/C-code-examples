//*******************************************************************
//HAUI Class Implementation of the user interface(UI) of the H&A game.
//*******************************************************************
#include "HAUI.h"

void HAUI::UIDisplay()
{
	// Language handling
	Introduction();
	Instruction();
}

void HAUI::Introduction()
{
	switch (haGame.GetLang())
	{
	case ENG:
		IntroductionEng();	break;

	case CNT:
		IntroductionCnt();	break;

	case CNS:
		IntroductionCns();	break;

	default:
		break;
	}
}

void HAUI::Instruction()
{
	switch (haGame.GetLang())
	{
	case ENG:
		InstructionEng();	break;

	case CNT:
		InstructionCnt();	break;

	case CNS:
		InstructionCns();	break;

	default:
		break;
	}
}

void HAUI::SetLanguage()
{
	SetLangPrompt();
	while (DoI_LangChange(GetI('1', '2', '3', '3')));
}

Language HAUI::GetLanguage()
{
	return haGame.GetLang();
}

void HAUI::ChangeMode()
{
	ChangeModePrompt();
	while (DoI_ModeChange(GetI('1', '2', '2', '2')));
}

void HAUI::SetPnty()
{
	SetPntyPrompt();
	while (DoI_PntyChange(GetI('1', '2', '2', '2')));
}

void HAUI::Quit()
{
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Thank you for playing!\n" << flush;
		break;
	case CNT:
		cout << "�x�x���p!\n" << flush;
		break;
	case CNS:
		cout << "лл����!\n" << flush;
		break;
	}
	cout << "Hold And Attack(C) 2015 CopyrightP Reserved" << endl;
}

void HAUI::SetLangPrompt()
{
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Language Option:\n"
			<< "[1]English            [2]Traditional Chinese\n"
			<< "[3]Simplified Chinese [Q]Cancel\n" << flush; break;
	case CNT:
		cout << "�Z���x��:\n"
			<< "[1]Ӣ�Z      [2]̨�����w\n"
			<< "[3]��ꑺ��w  [Q]ȡ��\n" << flush; break;
	case CNS:
		cout << "����ѡ��:\n"
			<< "[1]Ӣ��      [2]��������\n"
			<< "[3]��������  [Q]ȡ��\n" << flush; break;
	}
}

void HAUI::ChangeModePrompt()
{
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Mode Option:\n"
			<< "[1]Single Player  [2]Double Players\n"
			<< "[Q]Cancel\n" << flush; break;
	case CNT:
		cout << "ģʽ�x��:\n"
			<< "[1]�����[��		  [2]�p�ˌ���\n"
			<< "[Q]ȡ��\n" << flush; break;
	case CNS:
		cout << "����ѡ��:\n"
			<< "[1]������Ϸ       [2]˫�˶�ս\n"
			<< "[Q]ȡ��\n" << flush; break;
	}
}

// original dify function
//void HAUI::SetPntyPrompt()
//{
//	switch (haGame.GetLang())
//	{
//	case ENG:
//		cout << "Personality Option:\n"
//			<< "[1]Easy      [2]Normal\n"
//			<< "[3]Hard      [Q]Cancel\n" << flush; break;
//	case CNT:
//		cout << "�y���x��:\n"
//			<< "[1]����      [2]����\n"
//			<< "[3]���y      [Q]ȡ��\n" << flush; break;
//	case CNS:
//		cout << "�Ѷ�ѡ��:\n"
//			<< "[1]��      [2]����\n"
//			<< "[3]����      [Q]ȡ��\n" << flush; break;
//	}
//}

void HAUI::SetPntyPrompt()
{
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Personality Option:\n"
			<< "[1]Default   [2]Normal\n"
			<< "[Q]Cancel\n" << flush; break;
	case CNT:
		cout << "�����x��:\n"
			<< "[1]�A�O      [2]����\n"
			<< "[Q]ȡ��\n" << flush; break;
	case CNS:
		cout << "����ѡ��:\n"
			<< "[1]Ԥ��      [2]����\n"
			<< "[Q]ȡ��\n" << flush; break;
	}
}

void HAUI::Fight()
{
	haGame.Fight();
}

void HAUI::IntroductionEng()
{
	cout << "Welcome to The game Hold and Attack!\n"
		<< "You can use the the menu and the command to choose to play\n"
		<< "with computer or your pal.\n"
		<< "Here comes the introduction of the game:\n\n"
		<< "Hold and Attack is a puzzle game. Two players can do these three actions: Hold, Defend, and Attack. Hold means gathering energy, and you should gather energy before being able to attack. One \"Hold\" corresponds to one \"Attack\". When tackling \"Attack\", our \"Defend\" discussion can defend against attacks, and if we are \"Holding\", the game is lost. When both are \"Attack\", then they are offset and the game continues. When \"Defend\", it should be at most five times in a row.\n\n"
		<< "The defalut setting is one player(first) vs computer(second),\n"
		<< "and the pesonality is DEFAULT.\n"
		<< "Have fun then!\n" << flush;
}

void HAUI::InstructionEng()
{
	cout << "Command Menu:" << endl
		<< "[M]Set the play-mode.             [L]Set the language." << endl
		<< "[D]��Debug��Set the AI pesonality.[S]Start the game." << endl
		<< "[H]Help for Command Menu." << endl
		<< "[Q]Quit." << endl << endl;
}

void HAUI::IntroductionCnt()
{
	cout << "�gӭ�[�����M���[��\n"
		<< "Ո�������²ˆ΁��M�І����[����c���ь���\n"
		<< "�������[���B��\n\n"
		<< "���M���[����һ����������[��\n"
		<< "��λ��ҿ��������������������M�Ͳ������������⣬������֮����܉򹥓���\n"
		<< "��һ��ֻ�ܹ���һ�¡����������������r���҂����M��Ԓ���ܵ֓�������\n"
		<< "�������҂��@�r�����ǡ�����,��ݔ�ˡ�����߶��ǡ��������t��������������\n"
		<< "�[���^�m�����M���܉�֓�������������B�M���¡�\n\n"
		<< "�����[����A�O���y�Ȟ����y��\n"
		<< "����_��Ŷ:)\n" << flush;
}

void HAUI::InstructionCnt()
{
	cout << "����ָ̨��:" << endl
		<< "[M]�x���[��ģʽ.        [L]�x���Z��." << endl
		<< "[D]���{ԇ���O����X����.[S]�_ʼ���Y." << endl
		<< "[H]�鿴����ָ̨��.      [Q]�x�_�[��." << endl << endl;

}

void HAUI::IntroductionCns()
{
	cout << "��ӭ�������۲���Ϸ��\n"
		<< "��������²˵������е�����Ϸ�������Ѷ�ս��\n"
		<< "��������Ϸ���ܣ�\n\n"
		<< "���۲���Ϸ��һ���������ս��Ϸ��\n"
		<< "��λ��ҿ��������������������ۺͲ���������������������֮����ܹ�������\n"
		<< "��һ��ֻ�ܹ���һ�¡����Է���������ʱ�����ǳ��۵Ļ����ֵܵ�������\n"
		<< "������������ʱ�����ǡ�����,�����ˡ������߶��ǡ����������������������\n"
		<< "��Ϸ���������ۡ��ܹ��ֵ�������������������¡�\n\n"
		<< "������Ϸ��Ĭ���������Ѷ�Ϊ���ѡ�\n"
		<< "��ÿ���Ŷ:)\n" << flush;

}

void HAUI::InstructionCns()
{
	cout << "�˵�:" << endl
		<< "[M]ѡ��ģʽ.            [L]ѡ������." << endl
		<< "[D]�����ԣ�ѡ����Ը���.[S]��ʼս��." << endl
		<< "[H]�鿴�˵�.            [Q]�˳���Ϸ." << endl << endl;

}

char HAUI::GetI(char op1, char op2, char op3, char op4)
{
	char ch;		//command
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Please input the option you wanna choose: ";	break;
	case CNT:
		cout << "Ոݔ���x��: ";	break;
	case CNS:
		cout << "������ѡ��: "; break;
	}

	cin >> ch;
	ch = tolower(ch);
	while (ch != op1 && ch != op2 && ch != op3 && ch != op4
		&& ch != 'h' && ch != 'q')
	{
		switch (haGame.GetLang())
		{
		case ENG:
			cout << "Please enter a valid option, or press [H] for help:" << flush; break;
		case CNT:
			cout << "�x�񲻺Ϸ���Ո�����I���[h]�I���_�����x��: " << flush;	break;
		case CNS:
			cout << "ѡ�񲻺Ϸ��������������[h]���鿴����: " << flush; break;
		}
		cin >> ch;
		ch = tolower(ch);
	}
	return ch;
}

bool HAUI::DoI_ModeChange(char input)
//	Pre:	should provide method to handle input 'h' and 'q'
{
	if (input == '1')
	{
		haGame.SetMode(PVE);
		switch (haGame.GetLang())
		{
		case ENG:
			cout << "Now mode is Single Player.\n" << endl; break;
		case CNT:
			cout << "�ѸĞ�����[��ģʽ.\n" << endl; break;
		case CNS:
			cout << "�Ѹ�Ϊ������Ϸģʽ.\n" << endl; break;
		}
		return false;
	}
	else if (input == '2')
	{
		haGame.SetMode(PVP);
		switch (haGame.GetLang())
		{
		case ENG:
			cout << "Now mode is Double Players.\n" << endl; break;
		case CNT:
			cout << "�ѸĞ��p�ˌ���ģʽ.\n" << endl; break;
		case CNS:
			cout << "�Ѹ�Ϊ˫�˶�սģʽ.\n" << endl; break;
		}
		return false;
	}

	else if (input == 'h')
	{
		ChangeModePrompt();
		return true;
	}
	// if input == 'q', do nothing but exit
	else
		return false;
}

bool HAUI::DoI_LangChange(char input)
//	Pre:	should provide method to handle input 'h' and 'q'
{
	if (input == '1')
	{
		haGame.SetLang(ENG);
		UIDisplay();
		return false;
	}
	else if (input == '2')
	{
		haGame.SetLang(CNT);
		UIDisplay();
		return false;
	}
	else if (input == '3')
	{
		haGame.SetLang(CNS);
		UIDisplay();
		return false;
	}
	else if (input == 'h')
	{
		SetLangPrompt();
		return true;
	}
	// if input == 'q', do nothing but exit
	else
		return false;
}

// original dify function
//bool HAUI::DoI_PntyChange(char input)
//{
//	if (input == '1')
//	{
//		haGame.SetPntyAI(EASY);
//		switch (haGame.GetLang())
//		{
//		case ENG:
//			cout << "Now Personality is Easy.\n" << endl; break;
//		case CNT:
//			cout << "�ѸĞ��y��:����.\n" << endl; break;
//		case CNS:
//			cout << "�Ѹ�Ϊ�Ѷ�:��.\n" << endl; break;
//		}
//		return false;
//	}
//	else if (input == '2')
//	{
//		haGame.SetPntyAI(NORMAL);
//		switch (haGame.GetLang())
//		{
//		case ENG:
//			cout << "Now Personality is Normal.\n" << endl; break;
//		case CNT:
//			cout << "�ѸĞ��y��:����.\n" << endl; break;
//		case CNS:
//			cout << "�Ѹ�Ϊ�Ѷ�:����.\n" << endl; break;
//		}
//		return false;
//	}
//	else if (input == '3')
//	{
//		haGame.SetPntyAI(DEFAULT);
//		switch (haGame.GetLang())
//		{
//		case ENG:
//			cout << "Now Personality is Hard.\n" << endl; break;
//		case CNT:
//			cout << "�ѸĞ��y��:���y.\n" << endl; break;
//		case CNS:
//			cout << "�Ѹ�Ϊ�Ѷ�:����.\n" << endl; break;
//		}
//		return false;
//	}
//	else if (input == 'h')
//	{
//		SetPntyPrompt();
//		return true;
//	}
//	// if input == 'q', do nothing but exit
//	else
//		return false;
//}

bool HAUI::DoI_PntyChange(char input)
{
	if (input == '1')
	{
		haGame.SetPntyAI(DEFAULT);
		switch (haGame.GetLang())
		{
		case ENG:
			cout << "Now Personality is Default.\n" << endl; break;
		case CNT:
			cout << "�ѸĞ邀��:�A�O.\n" << endl; break;
		case CNS:
			cout << "�Ѹ�Ϊ����:Ԥ��.\n" << endl; break;
		}
		return false;
	}
	else if (input == '2')
	{
		haGame.SetPntyAI(NORMAL);
		switch (haGame.GetLang())
		{
		case ENG:
			cout << "Now Personality is Normal.\n" << endl; break;
		case CNT:
			cout << "�ѸĞ邀��:����.\n" << endl; break;
		case CNS:
			cout << "�Ѹ�Ϊ����:����.\n" << endl; break;
		}
		return false;
	}
	
	else if (input == 'h')
	{
		SetPntyPrompt();
		return true;
	}
	// if input == 'q', do nothing but exit
	else
		return false;
}