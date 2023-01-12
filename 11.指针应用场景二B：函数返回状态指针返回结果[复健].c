#include <stdio.h>
// 指针返回结果  函数返回状态
// @如果除法成功返回 1；否则返回0；
int chufa(int a,int b,int *p)
{
	int ret = 0;
	if(a%b!=0)
	{
		return ret; 
		}
		else{
			ret = 1;
			*p = a/b;
			return ret;
		}	
}

int main() {
	int a=5;
	int b=2;
	int c; 
	
	int d = chufa(a,b,&c);
	if(d==1){
			printf("a=%d b=%d c=%d ret=%d",a,b,c,d);
	}
	else
	printf(" ret=%d",d);



	return 0;
}
