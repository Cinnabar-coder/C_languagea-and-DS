#include <stdio.h>
// ָ�뷵�ؽ��  ��������״̬
// @��������ɹ����� 1�����򷵻�0��
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
