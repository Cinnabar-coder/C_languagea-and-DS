#include <stdio.h>
void swap(int* pa,int* pb) { // pa����a�ĵ�ַ *paָ��a �õ�a��ַ�ϵ�ֵ
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main() {
	int a =5;
	int b = 6;
	printf("%d %d",a,b);
	printf("\n");
	swap(&a,&b); //����ַ
	printf("%d %d",a,b);
	return 0;
}
