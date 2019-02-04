#include <stdio.h>  
#include <ctype.h>  
#include <string.h>  
#include "getop.h"  
  
//extern NUMBER;  
#define     NUMBER      '0'  
#define     NAME        'n'  
  
int getop(char s[])     //��ȡ��һ��������������  
{  
    int i;  
    int c;  
  
    while((s[0] = c = getch()) == ' ' || c == '/t')  
        ;  
    s[1] = '/0';  
    i = 0;  
    if(c != '-' && !islower(c) && !isdigit(c) && c != '.')  //�ж��Ƿ�����������������粻�ǣ�����ֱ���������������  
        return c;       //���������ʱ�����ش��������ASCIIֵ  
    if(c == '-')  
        if(isdigit(c = getch()) || c == '.')  
            s[++i] = c;  
        else  
        {  
            if(c != EOF)  
                ungetch(c);  
            return '-';  
        }  
    if(islower(c))  
    {  
        while(islower(s[++i] = c = getch()))  
            ;  
        s[i] = '/0';  
        if(c != EOF)  
            ungetch(c);  
        if(strlen(s) > 1)  
            return NAME;  
        else  
            return s[0];   //����return c; ����s = "v "����  
                                             //���ؿո񣬶������Ƿ���v   
    }  
    if(isdigit(c))  
        while(isdigit(s[++i] = c = getch()))    //�ռ���������  
            ;  
    if(c == '.')  
        while(isdigit(s[++i] = c = getch()))    //�ռ�С������  
            ;  
    s[i] = '/0';  
    if(c != EOF)  
        ungetch(c);  
  
    return NUMBER;      //���ǲ�����ʱ������NUMBER����ʶ�������  
}  
  
#define     BUFSIZE     100     //����������󳤶�  
  
//int buf[BUFSIZE];             //����������ȷ����ѹ��EOF(-1)�������κθ��������  
char buf[BUFSIZE];              //����ungetch�����Ļ�����  
int bufp = 0;                   //buf����һ������λ��  
  
int getch()                     //ȡһ���ַ�(������Ҫѹ�ص��ַ�)  
{  
    return (bufp > 0) ? buf[--bufp] : getchar();  
}  
  
void ungetch(int c)             //���ַ�ѹ�ص�����(������)��  
{  
    if(bufp >= BUFSIZE)  
        printf("ungetch: too many characters/n");  
    else  
        buf[bufp++] = c;  
}