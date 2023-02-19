#include <stdio.h>
#include<stdlib.h> 
int main() {
	int n;
	int *a;
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int)); // c99:a[n] vs:error
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=n-1;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
}
