#include "Linked_Stack.h"

void Introduction();
void Instruction();
void Transfer();

int main()
{

}

void Transfer()
//	Post:	(Chinese)将中序转化为后序
{
	Stack <double> ;	//numbers
	Stack <char> signs; //运算符栈  
	char ch;			//当前字符  
	int sum, i, j, t, top = 0; /*sum用来统计字符串的长度*/
	/*t是数字栈栈顶指针*/
	/*top是数字栈栈顶指针*/
	cout << "Please input a calculation(<#> to end:\n"
		<< "Note: <#> and the expression sholud be on one line.\n";
	cout << "Expression：";

	i = 0;
	/*这个循环语句，获取一个用户输入的合法的表达式*/
	do {
		i++;
		Cin()
	} while (str[i] != '#' && i != max);

	sum = i;
	t = 1;
	i = 1;
	ch = str[i];
	i++;
	//while循环，当前的字符不是#  
	while (ch != '#') {
		//将该字符与运算符栈顶的运算符的优先关系相比较。  
		//如果该字符优先关系高于此运算符栈顶的运算符，则将该运算符入栈。  
		//括号的运算优先级高。  
		switch (ch) {
		case '(':            /*判定为左括号，入符号栈*/
			top++;           /*栈顶指针+1*/
			stack[top] = ch;
			break;

		case ')': /*判定为右括号*/
			while (stack[top] != '(') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入另一个栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top--;
			break;
		case '+': /*判定为加减号*/
		case '-':
			while (top != 0 && stack[top] != '(') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入数字栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top++;
			stack[top] = ch;       /*不执行那个while循环的话，直接压入符号栈*/
			break;
		case '*': /*判定为乘除号*/
		case '/':
			while (stack[top] == '*' || stack[top] == '/') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入数字栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top++;
			stack[top] = ch;
			break;
		case ' ':/*滤去空格*/
			break;
		default:/*默认直接把数字压入数字栈*/
			while (ch >= '0' && ch <= '9') { /*判定为数字*/
				ex[t] = ch;                  /*把数字压入数字栈*/
				t++;                         /*数字栈栈顶指针+1*/
				/*这边的代码写得很巧妙*/
				ch = str[i];                 /*从字符串中取一个字符*/
				i++;                         /*字符数组下标+1*/
			}
			i--;
			ex[t] = '#';                     /*为每个数字加一个分隔符*/
			t++;
		}
		ch = str[i];
		i++;
	}
	/*把符号栈剩下的元素压进去*/
	while (top != 0) {
		ex[t] = stack[top];
		t++;
		top--;
	}
	ex[t] = '#';
	//printf("\n原来的中序表达式：");  
	//for (j = 1; j < sum; j++)  
	//   printf("%c", str[j]);  
	//printf("\n后缀表达式：");  
	//for (j = 1; j < t; j++)  
	//    printf("%c", ex[j]);  
}