#include "Linked_Stack.h"

void Introduction();
void Instruction();
void Transfer();

int main()
{

}

void Transfer()
//	Post:	(Chinese)������ת��Ϊ����
{
	Stack <double> ;	//numbers
	Stack <char> signs; //�����ջ  
	char ch;			//��ǰ�ַ�  
	int sum, i, j, t, top = 0; /*sum����ͳ���ַ����ĳ���*/
	/*t������ջջ��ָ��*/
	/*top������ջջ��ָ��*/
	cout << "Please input a calculation(<#> to end:\n"
		<< "Note: <#> and the expression sholud be on one line.\n";
	cout << "Expression��";

	i = 0;
	/*���ѭ����䣬��ȡһ���û�����ĺϷ��ı��ʽ*/
	do {
		i++;
		Cin()
	} while (str[i] != '#' && i != max);

	sum = i;
	t = 1;
	i = 1;
	ch = str[i];
	i++;
	//whileѭ������ǰ���ַ�����#  
	while (ch != '#') {
		//�����ַ��������ջ��������������ȹ�ϵ��Ƚϡ�  
		//������ַ����ȹ�ϵ���ڴ������ջ������������򽫸��������ջ��  
		//���ŵ��������ȼ��ߡ�  
		switch (ch) {
		case '(':            /*�ж�Ϊ�����ţ������ջ*/
			top++;           /*ջ��ָ��+1*/
			stack[top] = ch;
			break;

		case ')': /*�ж�Ϊ������*/
			while (stack[top] != '(') {
				ex[t] = stack[top];/*�ѷ���ջ��ջ��Ԫ��ѹ����һ��ջ��*/
				top--;             /*����ջ��ջ��ָ��-1*/
				t++;               /*����ջ��ջ��ָ��+1*/
			}
			top--;
			break;
		case '+': /*�ж�Ϊ�Ӽ���*/
		case '-':
			while (top != 0 && stack[top] != '(') {
				ex[t] = stack[top];/*�ѷ���ջ��ջ��Ԫ��ѹ������ջ��*/
				top--;             /*����ջ��ջ��ָ��-1*/
				t++;               /*����ջ��ջ��ָ��+1*/
			}
			top++;
			stack[top] = ch;       /*��ִ���Ǹ�whileѭ���Ļ���ֱ��ѹ�����ջ*/
			break;
		case '*': /*�ж�Ϊ�˳���*/
		case '/':
			while (stack[top] == '*' || stack[top] == '/') {
				ex[t] = stack[top];/*�ѷ���ջ��ջ��Ԫ��ѹ������ջ��*/
				top--;             /*����ջ��ջ��ָ��-1*/
				t++;               /*����ջ��ջ��ָ��+1*/
			}
			top++;
			stack[top] = ch;
			break;
		case ' ':/*��ȥ�ո�*/
			break;
		default:/*Ĭ��ֱ�Ӱ�����ѹ������ջ*/
			while (ch >= '0' && ch <= '9') { /*�ж�Ϊ����*/
				ex[t] = ch;                  /*������ѹ������ջ*/
				t++;                         /*����ջջ��ָ��+1*/
				/*��ߵĴ���д�ú�����*/
				ch = str[i];                 /*���ַ�����ȡһ���ַ�*/
				i++;                         /*�ַ������±�+1*/
			}
			i--;
			ex[t] = '#';                     /*Ϊÿ�����ּ�һ���ָ���*/
			t++;
		}
		ch = str[i];
		i++;
	}
	/*�ѷ���ջʣ�µ�Ԫ��ѹ��ȥ*/
	while (top != 0) {
		ex[t] = stack[top];
		t++;
		top--;
	}
	ex[t] = '#';
	//printf("\nԭ����������ʽ��");  
	//for (j = 1; j < sum; j++)  
	//   printf("%c", str[j]);  
	//printf("\n��׺���ʽ��");  
	//for (j = 1; j < t; j++)  
	//    printf("%c", ex[j]);  
}