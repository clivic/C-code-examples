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
		cout << "謝謝玩賞!\n" << flush;
		break;
	case CNS:
		cout << "谢谢玩赏!\n" << flush;
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
		cout << "語言選擇:\n"
			<< "[1]英語      [2]台灣正體\n"
			<< "[3]大陸簡體  [Q]取消\n" << flush; break;
	case CNS:
		cout << "语言选项:\n"
			<< "[1]英语      [2]繁体中文\n"
			<< "[3]简体中文  [Q]取消\n" << flush; break;
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
		cout << "模式選擇:\n"
			<< "[1]單人遊玩		  [2]雙人對戰\n"
			<< "[Q]取消\n" << flush; break;
	case CNS:
		cout << "语言选项:\n"
			<< "[1]单人游戏       [2]双人对战\n"
			<< "[Q]取消\n" << flush; break;
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
//		cout << "難度選擇:\n"
//			<< "[1]簡單      [2]正常\n"
//			<< "[3]困難      [Q]取消\n" << flush; break;
//	case CNS:
//		cout << "难度选项:\n"
//			<< "[1]简单      [2]正常\n"
//			<< "[3]困难      [Q]取消\n" << flush; break;
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
		cout << "個性選擇:\n"
			<< "[1]預設      [2]正常\n"
			<< "[Q]取消\n" << flush; break;
	case CNS:
		cout << "个性选项:\n"
			<< "[1]预设      [2]正常\n"
			<< "[Q]取消\n" << flush; break;
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
		<< "[D]（Debug）Set the AI pesonality.[S]Start the game." << endl
		<< "[H]Help for Command Menu." << endl
		<< "[Q]Quit." << endl << endl;
}

void HAUI::IntroductionCnt()
{
	cout << "歡迎遊玩屏鏜波遊戲！\n"
		<< "請參照以下菜單來進行單人遊戲或與好友對戰。\n"
		<< "以下是遊戲介紹：\n\n"
		<< "屏鏜波遊戲是一個益智類對戰遊戲。\n"
		<< "兩位玩家可以做三個動作：屏、鏜和波。屏就是屏氣，屏氣了之後才能夠攻擊。\n"
		<< "屏一下只能攻擊一下。當對方出“波”時，我們出鏜的話就能抵擋攻擊，\n"
		<< "而若是我們這時出的是“屏”,就輸了。若兩者都是“波”，則抵消掉“波，”\n"
		<< "遊戲繼續。“鏜”能夠抵擋攻擊，但最多連鏜五下。\n\n"
		<< "單人遊戲的預設是難度為困難。\n"
		<< "玩得開心哦:)\n" << flush;
}

void HAUI::InstructionCnt()
{
	cout << "控制台指令:" << endl
		<< "[M]選擇遊玩模式.        [L]選擇語言." << endl
		<< "[D]（調試）設定電腦個性.[S]開始戰鬥." << endl
		<< "[H]查看控制台指令.      [Q]離開遊戲." << endl << endl;

}

void HAUI::IntroductionCns()
{
	cout << "欢迎游玩屏镗波游戏！\n"
		<< "请参照以下菜单来进行单人游戏或与朋友对战。\n"
		<< "以下是游戏介绍：\n\n"
		<< "屏镗波游戏是一个益智类对战游戏。\n"
		<< "两位玩家可以做三个动作：屏、镗和波。屏就是屏气，屏气了之后才能够攻击。\n"
		<< "屏一下只能攻击一下。当对方出“波”时，我们出镗的话就能抵挡攻击，\n"
		<< "而若是我们这时出的是“屏”,就输了。若两者都是“波”，则抵消掉“波，”\n"
		<< "游戏继续。“镗”能够抵挡攻击，但最多连镗五下。\n\n"
		<< "单人游戏的默认设置是难度为困难。\n"
		<< "玩得开心哦:)\n" << flush;

}

void HAUI::InstructionCns()
{
	cout << "菜单:" << endl
		<< "[M]选择模式.            [L]选择语言." << endl
		<< "[D]（调试）选择电脑个性.[S]开始战斗." << endl
		<< "[H]查看菜单.            [Q]退出游戏." << endl << endl;

}

char HAUI::GetI(char op1, char op2, char op3, char op4)
{
	char ch;		//command
	switch (haGame.GetLang())
	{
	case ENG:
		cout << "Please input the option you wanna choose: ";	break;
	case CNT:
		cout << "請輸入選擇: ";	break;
	case CNS:
		cout << "请输入选择: "; break;
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
			cout << "選擇不合法，請重新鍵入或按[h]鍵打開幫助選單: " << flush;	break;
		case CNS:
			cout << "选择不合法，请重新输入或按[h]键查看帮助: " << flush; break;
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
			cout << "已改為單人遊玩模式.\n" << endl; break;
		case CNS:
			cout << "已改为单人游戏模式.\n" << endl; break;
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
			cout << "已改為雙人對戰模式.\n" << endl; break;
		case CNS:
			cout << "已改为双人对战模式.\n" << endl; break;
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
//			cout << "已改為難度:簡單.\n" << endl; break;
//		case CNS:
//			cout << "已改为难度:简单.\n" << endl; break;
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
//			cout << "已改為難度:正常.\n" << endl; break;
//		case CNS:
//			cout << "已改为难度:正常.\n" << endl; break;
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
//			cout << "已改為難度:困難.\n" << endl; break;
//		case CNS:
//			cout << "已改为难度:困难.\n" << endl; break;
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
			cout << "已改為個性:預設.\n" << endl; break;
		case CNS:
			cout << "已改为个性:预设.\n" << endl; break;
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
			cout << "已改為個性:正常.\n" << endl; break;
		case CNS:
			cout << "已改为个性:正常.\n" << endl; break;
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