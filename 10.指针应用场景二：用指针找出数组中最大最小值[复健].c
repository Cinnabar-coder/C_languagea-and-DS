#include <stdio.h>
void findmaxandmin(int a[],int len,int *pmax,int *pmin) {
	*pmax=a[0];
	*pmin=a[0];
	for(int i=0;i<len;i++)
	{
		if(a[i]>*pmax)
		{
			*pmax = a[i];
		}
		else if(a[i]<*pmin)
		{
			*pmin = a[i];
		}
	}
}
int main() {
//用指针找出数组中最大最小值
	int a[]= {6,5,9,0,10,2,55,12,76,89,21,-1,1,3,110};
	int length = sizeof(a)/sizeof(a[0]);
	int max;
	int min;

	findmaxandmin(a,length,&max,&min);
	printf("max=%d min=%d",max,min);
	return 0;
}
