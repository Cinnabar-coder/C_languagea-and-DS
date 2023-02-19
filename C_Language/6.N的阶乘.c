#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int result =1;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		result *=i;
		printf("%d!=%d\n",i,result);
		sum+=result;	
	} 
	printf("sum=%d",sum);
}
/* 法2
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int j;
	int sum=0;
	for(i=0;i<n;i++) //有几个阶乘
	{
		int result =1;
		for(j=i;j<=i;j++) //每个阶乘的和
		{
			result*=j;
		}
		 sum+=result; 
	}	
	printf("sum=%d",sum);
}
*/
/* 法3  不好理解、复杂
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int result =1;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		int j;
		for(j=i;j<=i;j++)
		{
			result*=j;
			sum+=result;
			printf("sum=%d",sum);
		} 
	printf("sum=%d",sum);
}
*/