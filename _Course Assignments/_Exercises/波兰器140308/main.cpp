#include<stdio.h>  
#include<math.h>  
#define max 100  
char ex[max];        /*�洢������ʽ*/  
  
/*�������ܣ���������ʽת��Ϊ������ʽ*/  
void trans() {  
    char str[max];   /*���ʽ�ַ���*/  
    char stack[max]; /*�����ջ*/  
    char ch;         /*��ǰ�ַ�*/  
    int sum, i, j, t, top = 0; /*sum����ͳ���ַ����ĳ���*/  
                               /*t������ջջ��ָ��*/  
                               /*top������ջջ��ָ��*/  
    printf("����һ����ֵ�ı��ʽ\n");  
    printf("�������ʽ��");  
  
    i = 0;  
    /*���ѭ����䣬��ȡһ���û�����ĺϷ��ı��ʽ*/  
    do {  
        i++;  
        scanf("%c", &str[i]);  
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
void compvalue() { /*�����׺���ʽ��ֵ*/  
    float stack[max], d; /*��Ϊջʹ��*/  
    char ch;  
    int t = 1, top = 0; /*tΪex�±꣬topΪstack�±�*/  
    ch = ex[t];  
    t++;  
    //�����Ҽ���ַ���  
    while (ch != '#') {/*��ȥ#*/  
        switch (ch) {  
        //�������������ջ��������Ԫ�ؽ������㡣  
        case '+':  
            stack[top - 1] = stack[top - 1] + stack[top];  
            top--;  
            break;  
        case '-':  
            stack[top - 1] = stack[top - 1] - stack[top];  
            top--;  
            break;  
        case '*':  
            stack[top - 1] = stack[top - 1] * stack[top];  
            top--;  
            break;  
  
        case '/':  
            if (stack[top] != 0)  
                stack[top - 1] = stack[top - 1] / stack[top];  
            else {  
                printf("\n\t�������!\n");  
                //exit(0);                   /*�쳣�˳�*/  
            }  
            top--;  
            break;  
        default:  
            d = 0;  
            while (ch >= '0' && ch <= '9') {  
                d = 10 * d + ch - '0'; /*�������ַ�ת��Ϊ��Ӧ����ֵ*/  
                ch = ex[t];  
                t++;  
            }  
            top++;  
            stack[top] = d;  
        }  
        ch = ex[t];  
        t++;  
    }  
    printf("\n\t������:%g\n", stack[top]);  
}  
  
int main() {  
    trans();      //ת�����沨��ʽ  
    compvalue();  //����ֵ  
    return 0;  
}  