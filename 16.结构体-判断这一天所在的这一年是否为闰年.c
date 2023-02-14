#include <stdio.h>
#include <stdbool.h>
	struct date{
		int day;
		int month;
		int year;
	};	

bool isleap(struct date t){ // ͬ�� 
	bool leap = false;
	if( (t.year%4==0&&t.year%100!=0) ||t.year%400==0){
		 leap = true;
	}
	return leap;
}

int NumberOfDays(struct date d){ //��������ṹ����� ��Ҫ�ýṹ������ 
	int day;
	const int DayOfperMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
	if(d.month==2&&isleap(d)){
		day = 29; 
	}else{
		day = DayOfperMonth[d.month-1];  // ��������� 1�� day-> DayOfperMonth�� [0] �ϵ�Ԫ�� 31 
	}
	return day;
}


 
int main() {
	struct date today;
	struct date tomorrow;

	printf("Enter today's date(yy,mm,dd)---:\n");
	scanf("%i:%i:%i",&today.year,&today.month,&today.day);
							  
							// today->��������(�ṹ������)  
	if(today.day!=NumberOfDays(today)){  //�жϽ����Ƿ�Ϊ����µ����һ�� 
		tomorrow.day = today.day+1; // error:
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}else if(today.month==12){ // �ж��Ƿ�Ϊ����µ����һ�� 
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year+1;
	}else{
		tomorrow.day = 1;
		tomorrow.month = today.month+1;
		tomorrow.year = today.year;
	}
	
	printf("tomorrow's date(yy,mm,dd)---:\n%i:%i:%i",tomorrow.year,tomorrow.month,tomorrow.day);

return 0;
}
