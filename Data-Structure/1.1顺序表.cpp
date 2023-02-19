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
// 定义基础类型-sqlist
typedef struct {
	SqElemType *elem;
	int length;
}Sqlist;


// 顺序表的初始化 
// 1、分配数组空间 起始位置指向基地址 
// 2、将表当前长度置 0 
// 3、成功返回 OK 
status InitList(Sqlist *const L){
	L->elem = (SqElemType*)malloc(sizeof(SqElemType)*MAXSIZE);
	if(L->elem == NULL)exit(OVERFLOW); // 异常值判断 
	L->length = 0;
	return OK;
}

// 顺序表中元素的个数 
status ListLength(Sqlist L){
	return L.length;
}

// 顺序表的取值
// 1、判断给定的位置 position 是否合理 若不合理返回 error 
// 2、若合理将 position上的元素赋给 e ，通过e带回position上的元素 
// 3、成功返回 OK 
status GetElem(Sqlist L,int position , SqElemType* e){
	if(position<1||position>L.length+1){
		return ERROR;
	} else{
		*e = L.elem[position-1];
		return OK; 
	}
} 

// 顺序表的查找
// 1、从表的一端开始，逐个关键字和给定值的比较
// 2、找到返回该元素的位置，未找到返回 0
status LocateElem(Sqlist L ,SqElemType e ){
	for(int i = 0;i<L.length;i++){
		if( e == L.elem[i]){
			return i+1;
		}
	}
	return 0;
}

// 顺序表的查找 - 查找前驱
// 1、若给定的值是顺序表的元素，且不是第一个，则用 pre_e 返回其前驱，否则操作失败 pre_e 无定义 
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

// 顺序表的查找 - 查找后继 
// 1、若给定的值是顺序表的元素，且不是最后一个，则用 pre_e 返回其后继，否则操作失败 pre_e 无定义 
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

// 顺序表的插入
// 1、判断插入的位置 position 是否合法 若不合法返回 error 
// 2、判断顺序表的存储空间是否已满，若已满返回 error 
// 3、从后往前至第 i 元素均向后移动 1 个位置，空出第 i 个位置
// 4、将要插入的新元素 e 放入第 i 个位置
// 5、表长加 1 ，插入成功返回 OK
status ListInsert(Sqlist *const L , int position , SqElemType e){
	if(position<1||position>L->length+1) return ERROR;
	if(L->length==MAXSIZE) return ERROR;
	for(int i=L->length-1;i>=position-1;i--){   //length postion 是逻辑位置 i是物理位置 逻辑位置-1=物理位置 
		L->elem[i+1] = L->elem[i];
	}
		L->elem[position-1] = e	;	// 放在 第7个位置 数组位置是 elem[6]  position-1 
	L->length++;
	return OK;
} 

// 顺序表的删除
// 1、判断删除的位置是否合法 若不合法返回 error
// 2、将第 i+1 至 最后的元素依次向前移动一个位置
// 3、表长 -1 若成功返回 OK
status ListDelete(Sqlist *const L ,int position ){
	if(position<1||position>L->length) return ERROR;
	for(int i = position-1;i<L->length;i++){
		L->elem[i] = L->elem[i+1];
	}
	L->length--;
	return OK;
} 
// 顺序表的遍历 
status TraverseList(Sqlist L){
	for(int i=0 ; i<L.length;i++){
		printf(" %d",L.elem[i]);
	}
	printf("\n");
} 

// 顺序表的清除 
// 1、将 length 长度置 0 
status ClearList(Sqlist *const L){
	L->length = 0 ;     // 下次使用重新给 length 赋值 
}

// 顺序表的销毁
// 1、释放内存空间
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
 	printf("顺序表初始化成功!\n"); 
 	}else{
 	printf("顺序表初始化失败！\n");
 	}
 	SqL.length=10;
	for(int i=0 ; i<SqL.length;i++){
		SqL.elem[i]=i+1;
	}
	TraverseList(SqL);
	
	// 查找元素个数操作 
	printf("顺序表的元素个数为:%d\n",ListLength(SqL) );
		printf("\n"); 

	// 查找给定位置上元素操作
	printf("在顺序表上找出给定位置上的元素  "); 
	printf("请输入一个合理的位置： \n");
	scanf("%d",&Posi); 
	if(GetElem(SqL,Posi,&E)){
	printf("顺序表上给定位置上的元素为%d：\n",E); 	
	} else{
		printf("这不是一个合理的位置！\n");
	}	printf("\n");
	
	// 查找与指定值 Value 相同元素的位置
	printf("在顺序表上找出与指定Value相同元素的位置  "); 
	printf("请输入一个任意值： \n");
	scanf("%d",&Value); 
	if(LocateElem(SqL,Value)){
		printf("与指定值 Value 相同元素的位置%d: \n",LocateElem(SqL,Value));
	}else{
		printf("未找到与指定值Value相同元素的位置！\n");
	}	printf("\n");
	
	// 查找指定位置上的前驱 
	printf("请指定一个数，在顺序表中查找指定数的前驱  ");
	printf("请输入一个值：\n");
	scanf("%d",&Value);
	if(PriorElem(SqL,Value,&E)){
		printf("指定值Value在顺序表中的前驱是%d：\n",E);
	}else{
		printf("该指定值Value无意义！"); 
	}	printf("\n");
	
	// 查找指定位置上的后继
	printf("请指定一个数，在顺序表中查找指定数的后继  ");
	printf("请输入一个值：\n");
	scanf("%d",&Value);
	if(NextElem(SqL,Value,&E)){
		printf("指定值Value在顺序表中的后继是%d：\n",E);
	}else{
		printf("该指定值Value无意义！"); 
	}	printf("\n");	 
	
	
	// 插入操作 
	printf("在顺序表上插入一个元素  "); 
	printf("请输入一个合理的位置： \n");
	scanf("%d",&Posi); 	
	printf("请输入一个数据：\n");
	scanf("%d",&E);			// char类型中也有数字 下面函数与原函数 不会发生类型不匹配问题 
	if(ListInsert(&SqL,Posi,E)){
		TraverseList(SqL);
		printf("顺序表的元素个数为:%d\n",ListLength(SqL) );
	}else{
		printf("这不是一个合理的位置！\n");
	}	printf("\n");	

	// 删除操作
	printf("在顺序表上删除一个元素  "); 
	printf("请输入一个合理的位置： \n");
	scanf("%d",&Posi); 	
	if(ListDelete(&SqL,Posi)){
		TraverseList(SqL);
		printf("顺序表的元素个数为:%d\n",ListLength(SqL) );		
	}else{
		printf("这不是一个合理的位置！\n");
	}	printf("\n");		 
	
	// 清空顺序表
	printf("是否清空顺序表？[Y/N]:\n");
	scanf("%s",&sta);
	if(sta=='Y')
	{
		ClearList(&SqL);
		printf("顺序表已清空！\n") ;
	} else if(sta=='N'){
		printf("已取消操作"); 
	}	printf("\n");
	
	// 销毁顺序表 
	printf("是否销毁顺序表？[Y/N]:\n");
	scanf("%s",&sta);
	if(sta=='Y')
	{
		DestoryList(&SqL);
		printf("顺序表已销毁！\n") ;
	} else if(sta=='N'){
		printf("已取消操作"); 
	}
	
return 0;
}
