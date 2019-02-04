#include <stdio.h>  
#include <ctype.h>  
#include <string.h>  
#include "getop.h"  
  
//extern NUMBER;  
#define     NUMBER      '0'  
#define     NAME        'n'  
  
int getop(char s[])     //获取下一个运算符或操作数  
{  
    int i;  
    int c;  
  
    while((s[0] = c = getch()) == ' ' || c == '/t')  
        ;  
    s[1] = '/0';  
    i = 0;  
    if(c != '-' && !islower(c) && !isdigit(c) && c != '.')  //判断是否属于这四种情况，如不是，下面分别对这四种情况处理  
        return c;       //当是运算符时，返回此运算符的ASCII值  
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
            return s[0];   //错误：return c; 例：s = "v "，则  
                                             //返回空格，而本意是返回v   
    }  
    if(isdigit(c))  
        while(isdigit(s[++i] = c = getch()))    //收集整数部分  
            ;  
    if(c == '.')  
        while(isdigit(s[++i] = c = getch()))    //收集小数部分  
            ;  
    s[i] = '/0';  
    if(c != EOF)  
        ungetch(c);  
  
    return NUMBER;      //当是操作数时，返回NUMBER，标识这种情况  
}  
  
#define     BUFSIZE     100     //缓冲区的最大长度  
  
//int buf[BUFSIZE];             //这样可以正确处理压回EOF(-1)及其他任何负数的情况  
char buf[BUFSIZE];              //用于ungetch函数的缓冲区  
int bufp = 0;                   //buf中下一个空闲位置  
  
int getch()                     //取一个字符(可能是要压回的字符)  
{  
    return (bufp > 0) ? buf[--bufp] : getchar();  
}  
  
void ungetch(int c)             //把字符压回到输入(缓冲区)中  
{  
    if(bufp >= BUFSIZE)  
        printf("ungetch: too many characters/n");  
    else  
        buf[bufp++] = c;  
}