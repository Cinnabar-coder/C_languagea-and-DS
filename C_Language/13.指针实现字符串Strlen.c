#include <stdio.h>
#include<string.h>
/*
	size_t  strlen (const char* str)
使用size_t数据类型：这里返回计算的字符串长度，长度最小值为0，不可能为负数
使用const关键字：这里只是计算字符串的长度，用const修饰，避免将原字符串修改掉

strlen函数：计算的是字符串str的长度，
从字符的首地址开始遍历，以 '\0' 为结束标志，
然后将计算的长度返回，计算的长度并不包含'\0'。

sizeof()--> 计算字符串的真实长度（包含 /0） 
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
//	slrlen 实例一
//	 
//	char str[] = "hello";
//	int num = strlen(str);
//	printf("str的长度是；%d",num); --> 5

//	实例二         "adc" 字符串 'a' 字符 
//	char str[]={'a','b','c','d','f',};  
//	int num = strlen(str);
//	printf("str的长度是；%d",num); 

//	指针实现 strlen 功能
 	 char str[]="HelloWord!";
 	 int num = sizeof(str);
 	 printf("sizeof(str)的长度是；%d\n",num);
 	 printf("strlen_str的长度是：%d",mystrlen(str));

	return 0;
}
