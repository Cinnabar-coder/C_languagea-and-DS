#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100
typedef int status;
typedef char SqElemType;
// �����������-sqlist
typedef struct {
	SqElemType *elem;
	int length;
}Sqlist;


// ˳���ĳ�ʼ�� 
// 1����������ռ� ��ʼλ��ָ�����ַ 
// 2������ǰ������ 0 
// 3���ɹ����� OK 
status InitList(Sqlist *const L){
	L->elem = (SqElemType*)malloc(sizeof(SqElemType)*MAXSIZE);
	if(L->elem == NULL)exit(OVERFLOW); // �쳣ֵ�ж� 
	L->length = 0;
	return OK;
}

// ˳�����Ԫ�صĸ��� 
status ListLength(Sqlist L){
	return L.length;
}

// ˳����ȡֵ
// 1���жϸ�����λ�� position �Ƿ���� ���������� error 
// 2�������� position�ϵ�Ԫ�ظ��� e ��ͨ��e����position�ϵ�Ԫ�� 
// 3���ɹ����� OK 
status GetElem(Sqlist L,int position , SqElemType* e){
	if(position<1||position>L.length+1){
		return ERROR;
	} else{
		*e = L.elem[position-1];
		return OK; 
	}
} 

// ˳���Ĳ���
// 1���ӱ��һ�˿�ʼ������ؼ��ֺ͸���ֵ�ıȽ�
// 2���ҵ����ظ�Ԫ�ص�λ�ã�δ�ҵ����� 0
status LocateElem(Sqlist L ,SqElemType e ){
	for(int i = 0;i<L.length;i++){
		if( e == L.elem[i]){
			return i+1;
		}
	}
	return 0;
}

// ˳���Ĳ��� - ����ǰ��
// 1����������ֵ��˳����Ԫ�أ��Ҳ��ǵ�һ�������� pre_e ������ǰ�����������ʧ�� pre_e �޶��� 
status PriorElem(Sqlist L , int cur_e , SqElemType* const pre_e ){
	if(cur_e!=L.elem[0]){
		for(int i= 1;i<L.length;i++){
		if(cur_e==L.elem[i]){
			return *pre_e = L.elem[i-1]	;	
			} 
		}
	}else{
		return ERROR;
	}
}

// ˳���Ĳ��� - ���Һ�� 
// 1����������ֵ��˳����Ԫ�أ��Ҳ������һ�������� pre_e �������̣��������ʧ�� pre_e �޶��� 
status NextElem(Sqlist L , int cur_e , SqElemType* const next_e ){
	if(cur_e!=L.elem[L.length-1]){
		for(int i= 0;i<L.length-1;i++){
		if(cur_e==L.elem[i]){
			return *next_e = L.elem[i+1]	;	
			} 
		}
	}else{
		return ERROR;
	}
}

// ˳���Ĳ���
// 1���жϲ����λ�� position �Ƿ�Ϸ� �����Ϸ����� error 
// 2���ж�˳���Ĵ洢�ռ��Ƿ����������������� error 
// 3���Ӻ���ǰ���� i Ԫ�ؾ�����ƶ� 1 ��λ�ã��ճ��� i ��λ��
// 4����Ҫ�������Ԫ�� e ����� i ��λ��
// 5������ 1 ������ɹ����� OK
status ListInsert(Sqlist *const L , int position , SqElemType e){
	if(position<1||position>L->length+1) return ERROR;
	if(L->length==MAXSIZE) return ERROR;
	for(int i=L->length-1;i>=position-1;i--){   //length postion ���߼�λ�� i������λ�� �߼�λ��-1=����λ�� 
		L->elem[i+1] = L->elem[i];
	}
		L->elem[position-1] = e	;	// ���� ��7��λ�� ����λ���� elem[6]  position-1 
	L->length++;
	return OK;
} 

// ˳����ɾ��
// 1���ж�ɾ����λ���Ƿ�Ϸ� �����Ϸ����� error
// 2������ i+1 �� ����Ԫ��������ǰ�ƶ�һ��λ��
// 3���� -1 ���ɹ����� OK
status ListDelete(Sqlist *const L ,int position ){
	if(position<1||position>L->length) return ERROR;
	for(int i = position-1;i<L->length;i++){
		L->elem[i] = L->elem[i+1];
	}
	L->length--;
	return OK;
} 
// ˳���ı��� 
status TraverseList(Sqlist L){
	for(int i=0 ; i<L.length;i++){
		printf(" %d",L.elem[i]);
	}
	printf("\n");
} 

// ˳������� 
// 1���� length ������ 0 
status ClearList(Sqlist *const L){
	L->length = 0 ;     // �´�ʹ�����¸� length ��ֵ 
}

// ˳��������
// 1���ͷ��ڴ�ռ�
status DestoryList(Sqlist *const L){
	if(L->elem) free (L->elem);
} 

int main() {
	Sqlist SqL;
	int Posi;
	SqElemType E;
	SqElemType Value; 
	char sta;
 	if(InitList (&SqL)){
 	printf("˳����ʼ���ɹ�!\n"); 
 	}else{
 	printf("˳����ʼ��ʧ�ܣ�\n");
 	}
 	SqL.length=10;
	for(int i=0 ; i<SqL.length;i++){
		SqL.elem[i]=i+1;
	}
	TraverseList(SqL);
	
	// ����Ԫ�ظ������� 
	printf("˳����Ԫ�ظ���Ϊ:%d\n",ListLength(SqL) );
		printf("\n"); 

	// ���Ҹ���λ����Ԫ�ز���
	printf("��˳������ҳ�����λ���ϵ�Ԫ��  "); 
	printf("������һ�������λ�ã� \n");
	scanf("%d",&Posi); 
	if(GetElem(SqL,Posi,&E)){
	printf("˳����ϸ���λ���ϵ�Ԫ��Ϊ%d��\n",E); 	
	} else{
		printf("�ⲻ��һ�������λ�ã�\n");
	}	printf("\n");
	
	// ������ָ��ֵ Value ��ͬԪ�ص�λ��
	printf("��˳������ҳ���ָ��Value��ͬԪ�ص�λ��  "); 
	printf("������һ������ֵ�� \n");
	scanf("%d",&Value); 
	if(LocateElem(SqL,Value)){
		printf("��ָ��ֵ Value ��ͬԪ�ص�λ��%d: \n",LocateElem(SqL,Value));
	}else{
		printf("δ�ҵ���ָ��ֵValue��ͬԪ�ص�λ�ã�\n");
	}	printf("\n");
	
	// ����ָ��λ���ϵ�ǰ�� 
	printf("��ָ��һ��������˳����в���ָ������ǰ��  ");
	printf("������һ��ֵ��\n");
	scanf("%d",&Value);
	if(PriorElem(SqL,Value,&E)){
		printf("ָ��ֵValue��˳����е�ǰ����%d��\n",E);
	}else{
		printf("��ָ��ֵValue�����壡"); 
	}	printf("\n");
	
	// ����ָ��λ���ϵĺ��
	printf("��ָ��һ��������˳����в���ָ�����ĺ��  ");
	printf("������һ��ֵ��\n");
	scanf("%d",&Value);
	if(NextElem(SqL,Value,&E)){
		printf("ָ��ֵValue��˳����еĺ����%d��\n",E);
	}else{
		printf("��ָ��ֵValue�����壡"); 
	}	printf("\n");	 
	
	
	// ������� 
	printf("��˳����ϲ���һ��Ԫ��  "); 
	printf("������һ�������λ�ã� \n");
	scanf("%d",&Posi); 	
	printf("������һ�����ݣ�\n");
	scanf("%d",&E);			// char������Ҳ������ ���溯����ԭ���� ���ᷢ�����Ͳ�ƥ������ 
	if(ListInsert(&SqL,Posi,E)){
		TraverseList(SqL);
		printf("˳����Ԫ�ظ���Ϊ:%d\n",ListLength(SqL) );
	}else{
		printf("�ⲻ��һ�������λ�ã�\n");
	}	printf("\n");	

	// ɾ������
	printf("��˳�����ɾ��һ��Ԫ��  "); 
	printf("������һ�������λ�ã� \n");
	scanf("%d",&Posi); 	
	if(ListDelete(&SqL,Posi)){
		TraverseList(SqL);
		printf("˳����Ԫ�ظ���Ϊ:%d\n",ListLength(SqL) );		
	}else{
		printf("�ⲻ��һ�������λ�ã�\n");
	}	printf("\n");		 
	
	// ���˳���
	printf("�Ƿ����˳���[Y/N]:\n");
	scanf("%s",&sta);
	if(sta=='Y')
	{
		ClearList(&SqL);
		printf("˳�������գ�\n") ;
	} else if(sta=='N'){
		printf("��ȡ������"); 
	}	printf("\n");
	
	// ����˳��� 
	printf("�Ƿ�����˳���[Y/N]:\n");
	scanf("%s",&sta);
	if(sta=='Y')
	{
		DestoryList(&SqL);
		printf("˳��������٣�\n") ;
	} else if(sta=='N'){
		printf("��ȡ������"); 
	}
	
return 0;
}
