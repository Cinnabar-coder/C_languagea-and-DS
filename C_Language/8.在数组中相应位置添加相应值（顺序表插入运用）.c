/*
�ٶ���һ�������� a[100] = {1, 2, 3, 4, 5, 6}����д�����ܹ�ʵ��Ԫ�صĲ��룺���������������Ҫ����Ԫ�ص�λ��x�Լ�Ҫ�����ֵv���������ֵ�������a��
����������
X = 3�� v = 55 
���������
1,2,55,3,4,5,6
*/
#include<stdio.h>
#define OK 1
#define error -1
#define overflow -2
int listinsert(int*a,int* length,int position,int value)
{
	if(position<1||position>*length+1)return error; // �ж�����Խ��򲻴������� 
	if(*length==100) return overflow; // �ж�������������� 
	int i;
	for(i=*length-1;i>=position-1;i--) // ˳���Ĳ���Ԫ�� 
	{
		a[i+1]=a[i];
	}
	a[position-1]=value;
	(*length)++; // ����Ԫ�ر��� 1 
	return OK;
	
}
int main()
{
	int a[100]={1,2,3,4,5,6,};
	int x;
	printf("����Ԫ�ص�λ��X: \n");
	scanf("%d",&x); 
	int v;
	printf("�����ֵV��\n");
	scanf("%d",&v);
	
	int L=0;
	int i;
	for(i=0;i<100;i++) //�ж�����ĳ��� 
	{	
		if(a[i]==NULL)
		{
			break;
		}
		L++;
	}
	int status = listinsert(a,&L,x,v); // status ���պ�����״�� 
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

