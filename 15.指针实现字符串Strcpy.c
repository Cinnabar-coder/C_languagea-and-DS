#include <stdio.h>
#include<string.h>
/*
 strcpy()�������ǽ�һ���ַ������Ƶ���һ��ռ��ַ�� �ĺ�������\0����ֹͣ��������ֹ������ͬʱҲ�Ὣ '\0' Ҳ���Ƶ�Ŀ��ռ䡣�����ǿ��е�strcpy()����������

char* strcpy(char* destination,const char* source);
char* destination---------Ŀ���ַ������׵�ַ
const char* source------Դ��ַ�������Ƶ��ַ������׵�ַ����const���Σ������޸ĵ����������ַ���

char*�����ص���Ŀ���ַ������׵�ַ 
*/

char* Mystrcmp(char* des,const char* src ){
	char* ret =des;	 
	while(*des++ = *src++){ // '\0'=0   
	
	
	
	 }
	 //*des++  ������ֵ���� Ȼ�������ж� '\0' �Ѿ������� 
	return ret; // ���ܷ��� des des��ַ�Ѿ�++������ȥ�� Ҫ���ص���Ŀ���ַ����׵�ַ 
}

int main() {
	// Strcmp ���÷� 
//	char str[]="abc";
//	char str2[]="hello";
//	printf("%s\n",strcpy(str,str2)); // �� str2 ���ַ������Ƶ� str �� 

	// ָ��ʵ��Strcmp
	char str1[]="abcdefg";
	char str2[]="Hell";
	
	printf("%s\n",Mystrcmp(str1,str2));

	return 0;
}                  
