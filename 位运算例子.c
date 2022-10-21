#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	// 位运算 输出一个数的二进制
	int number;
	scanf("%d", &number);
	int cnt = 0;
	unsigned mask = 1u<<31;	// 一定是要	unsigned 无符号整数 不然会死循环

	for (; mask; mask >>= 1)
	{
		printf("%d", number & mask ? 1 : 0);
		cnt++;
		if (cnt % 4 == 0 )
		{
			printf(" ");
		}
	}
	return 0;
}