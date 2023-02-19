// 字符串排序 
/*编写一个程序，对输入的一个全为小写字母的字符串，进行从a-z的顺序排序。
输入样例：
bartd 
输出样例：
abdrt
*/ 

#include<stdio.h>
#include<string.h>
char Bubblesort(char* p,int length)
{
	int i;
	int j;
	for(i=0;i<length-1;i++) // 冒泡法排序 
	{
		for(j=0;j<length-1-i;j++)
		{
			int temp;
			if(*(p+j)>*(p+j+1)) // p是指向首地址 char类型 ：1B 
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	
}

void put(char* str ,int L)
{
	int i;
	for(i=0;i<L;i++)
	{
		printf("%c ",str[i]);
	}
}
int main()
{
	 char a[100];
	 gets(a);
	 int len = strlen(a); //获取字符串的长度 数据类型char strlen不带 \0 
	Bubblesort(a,len);	  
	
	put(a,len);
	return 0;
}
