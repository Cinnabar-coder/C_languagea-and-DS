#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//쳲��������У�1��1��2��3��5��8��13��21��34��55��89...
	//�ӵ�3�ʼ��ÿһ�����ǰ����֮��
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	*a = 1;
	*(a + 1) = 1;
	//int a[n] = { 1,1 };
	int i;
	for (i=2;i<n;i++ )
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}






