#include <stdio.h>
void swap(int* pa,int* pb) { // pa保存a的地址 *pa指向a 得到a地址上的值
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main() {
	int a =5;
	int b = 6;
	printf("%d %d",a,b);
	printf("\n");
	swap(&a,&b); //传地址
	printf("%d %d",a,b);
	return 0;
}
