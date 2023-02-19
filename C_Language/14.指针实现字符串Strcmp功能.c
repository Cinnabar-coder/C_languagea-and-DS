#include <stdio.h>
#include<string.h>
/*
	int strcmp(const char* str1 , const char* str2);
strcmp比较两个字符串的大小，一个字符一个字符比较，按ASCLL码比较
标准规定：
第一个字符串等于第二个字符串，则返回0				str1 == str2 --> 0
第一个字符串大于第二个字符串，则返回大于0的数字   	str1  > str2 --> 1
第一个字符串小于第二个字符串，则返回小于0的数字		str1  < str2 --> -1

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
//	strcmp 实例： 
//	char str1[] = "abcde";
//	char str2[] = "abcde";
//	char str3[] = "abcd";
//	char str4[] = "wasd";
//	
//	printf("%d\n", strcmp(str1,str2 )); --> 0
//	printf("%d\n", strcmp(str1,str3 )); --> 1
//	printf("%d\n", strcmp(str3,str4 )); -->-1

	// 指针实现 strcmp
	char str1[] = "abcd";
	char str2[] = "abcde";
	printf("str1与str2的大小是；%d",mystrcmp(str1,str2));
	return 0;
}
