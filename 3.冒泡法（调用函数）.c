#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> //使用malloc 需要用到这个库函数

void bubble_sort(int *a,int n)
{
	int j;
	int i;
	for (j = 0; j < n-1; j++)//8个数只要排7次
	{
		for (i=0;i<(n-1)-j;i++) //（n-1）数组越界问题
				{			   // -j：排好的不需要再排序了
					if (a[i]>a[i+1])
					{
						int temp;
						temp = a[i];
						a[i] = a[i+1];
						a[i + 1] = temp;
					}
				}
	}
		
}
int main()
{
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(n* sizeof(int));//==a[n]
	int i;
	for ( i = 0; i < n; i++)
	{						  // int x;
		 scanf("%d", &a[i]); //error: a[i]=scanf("%d", &x); 结果输入的数组值全为 1
	}

	bubble_sort(a , n);//数组名就是a[0]的地址

	for (i = 0; i < n; i++)
	{
	printf("%d ",a[i]);
	}

}
	

	
