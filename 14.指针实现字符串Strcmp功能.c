#include <stdio.h>
#include<string.h>
/*
	int strcmp(const char* str1 , const char* str2);
strcmp�Ƚ������ַ����Ĵ�С��һ���ַ�һ���ַ��Ƚϣ���ASCLL��Ƚ�
��׼�涨��
��һ���ַ������ڵڶ����ַ������򷵻�0				str1 == str2 --> 0
��һ���ַ������ڵڶ����ַ������򷵻ش���0������   	str1  > str2 --> 1
��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������		str1  < str2 --> -1

*/
int mystrcmp(const char* str1,const char* str2){
	while(*str1==*str2 && *str1!='\0')
	{
		str1++;
		str2++;	
	}
	return *str1 - *str2;
}
int main() {
//	strcmp ʵ���� 
//	char str1[] = "abcde";
//	char str2[] = "abcde";
//	char str3[] = "abcd";
//	char str4[] = "wasd";
//	
//	printf("%d\n", strcmp(str1,str2 )); --> 0
//	printf("%d\n", strcmp(str1,str3 )); --> 1
//	printf("%d\n", strcmp(str3,str4 )); -->-1

	// ָ��ʵ�� strcmp
	char str1[] = "abcd";
	char str2[] = "abcde";
	printf("str1��str2�Ĵ�С�ǣ�%d",mystrcmp(str1,str2));
	return 0;
}
