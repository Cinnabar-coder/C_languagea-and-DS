#include <stdio.h>
#include<string.h>
/*
	size_t  strlen (const char* str)
ʹ��size_t�������ͣ����ﷵ�ؼ�����ַ������ȣ�������СֵΪ0��������Ϊ����
ʹ��const�ؼ��֣�����ֻ�Ǽ����ַ����ĳ��ȣ���const���Σ����⽫ԭ�ַ����޸ĵ�

strlen��������������ַ���str�ĳ��ȣ�
���ַ����׵�ַ��ʼ�������� '\0' Ϊ������־��
Ȼ�󽫼���ĳ��ȷ��أ�����ĳ��Ȳ�������'\0'��

sizeof()--> �����ַ�������ʵ���ȣ����� /0�� 
*/
size_t mystrlen(const char* string){
	size_t cnt = 0;
	while(*string!='\0')
	{
		cnt++;
		string++;
	}
	return cnt;
}
int main() {
//	slrlen ʵ��һ
//	 
//	char str[] = "hello";
//	int num = strlen(str);
//	printf("str�ĳ����ǣ�%d",num); --> 5

//	ʵ����         "adc" �ַ��� 'a' �ַ� 
//	char str[]={'a','b','c','d','f',};  
//	int num = strlen(str);
//	printf("str�ĳ����ǣ�%d",num); 

//	ָ��ʵ�� strlen ����
 	 char str[]="HelloWord!";
 	 int num = sizeof(str);
 	 printf("sizeof(str)�ĳ����ǣ�%d\n",num);
 	 printf("strlen_str�ĳ����ǣ�%d",mystrlen(str));

	return 0;
}
