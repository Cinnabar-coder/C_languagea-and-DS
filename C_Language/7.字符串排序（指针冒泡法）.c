// �ַ������� 
/*��дһ�����򣬶������һ��ȫΪСд��ĸ���ַ��������д�a-z��˳������
����������
bartd 
���������
abdrt
*/ 

#include<stdio.h>
#include<string.h>
char Bubblesort(char* p,int length)
{
	int i;
	int j;
	for(i=0;i<length-1;i++) // ð�ݷ����� 
	{
		for(j=0;j<length-1-i;j++)
		{
			int temp;
			if(*(p+j)>*(p+j+1)) // p��ָ���׵�ַ char���� ��1B 
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	
}

void put(char* str ,int L)
{
	int i;
	for(i=0;i<L;i++)
	{
		printf("%c ",str[i]);
	}
}
int main()
{
	 char a[100];
	 gets(a);
	 int len = strlen(a); //��ȡ�ַ����ĳ��� ��������char strlen���� \0 
	Bubblesort(a,len);	  
	
	put(a,len);
	return 0;
}
