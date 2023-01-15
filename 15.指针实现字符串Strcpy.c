#include <stdio.h>
#include<string.h>
/*
 strcpy()函数：是将一个字符串复制到另一块空间地址中 的函数，‘\0’是停止拷贝的终止条件，同时也会将 '\0' 也复制到目标空间。下面是库中的strcpy()函数声明：

char* strcpy(char* destination,const char* source);
char* destination---------目标字符串的首地址
const char* source------源地址：被复制的字符串的首地址，用const修饰，避免修改掉被拷贝的字符串

char*：返回的是目标字符串的首地址 
*/

char* Mystrcmp(char* des,const char* src ){
	char* ret =des;	 
	while(*des++ = *src++){ // '\0'=0   
	
	
	
	 }
	 //*des++  先做赋值运算 然后再做判断 '\0' 已经附上了 
	return ret; // 不能返回 des des地址已经++到后面去了 要返回的是目标字符的首地址 
}

int main() {
	// Strcmp 的用法 
//	char str[]="abc";
//	char str2[]="hello";
//	printf("%s\n",strcpy(str,str2)); // 把 str2 的字符串复制到 str 上 

	// 指针实现Strcmp
	char str1[]="abcdefg";
	char str2[]="Hell";
	
	printf("%s\n",Mystrcmp(str1,str2));

	return 0;
}                  
