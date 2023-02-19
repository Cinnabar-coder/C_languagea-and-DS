/*
假定有一整形数组 a[100] = {1, 2, 3, 4, 5, 6}，编写程序能够实现元素的插入：键盘输入数组的需要插入元素的位置x以及要插入的值v，输出插入值后的数组a。
输入样例：
X = 3， v = 55 
输出样例：
1,2,55,3,4,5,6
*/
#include<stdio.h>
#define OK 1
#define error -1
#define overflow -2
int listinsert(int*a,int* length,int position,int value)
{
	if(position<1||position>*length+1)return error; // 判断数组越界或不纯在条件 
	if(*length==100) return overflow; // 判断数组已满的情况 
	int i;
	for(i=*length-1;i>=position-1;i--) // 顺序表的插入元素 
	{
		a[i+1]=a[i];
	}
	a[position-1]=value;
	(*length)++; // 插入元素表长加 1 
	return OK;
	
}
int main()
{
	int a[100]={1,2,3,4,5,6,};
	int x;
	printf("插入元素的位置X: \n");
	scanf("%d",&x); 
	int v;
	printf("插入的值V：\n");
	scanf("%d",&v);
	
	int L=0;
	int i;
	for(i=0;i<100;i++) //判断数组的长度 
	{	
		if(a[i]==NULL)
		{
			break;
		}
		L++;
	}
	int status = listinsert(a,&L,x,v); // status 接收函数的状况 
	if(status<0)
	{
		printf("ERROR!");
	}
	else
	{	
		for(i=0;i<L;i++)
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}

