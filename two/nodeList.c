//线性表的链式存储

#include<stdio.h>
#include<stdlib.h>

//创建头结点，length存储链表的长度 next指向下一个结点 
typedef struct Header{
	int length;
	struct Header * next;
}Head;

//创建一个结点，data存放数据，next指向下一个结点 
typedef struct Node{
	int data;
	struct Node *next; 
}ListNode;

//创建一个链表，返回头结点 
Head * createList(){
	Head *phead = (Head*)malloc(sizeof(Head));
	phead->length = 0;
	phead->next = NULL;
	return phead;
}

// 获取链表长度
int getLength(Head * phead){
	if(phead==NULL){
		printf("not init headnode!\n");
		return -1;
	}
	return phead->length;
} 

// 添加数据，,默认添加在末尾 
int addData(Head * phead, int data){
	if(phead==NULL){
		printf("not init head node!\n");
		return -1;
	}	
	
	//创建当前结点，并指向链表最后一个结点
	ListNode * curNode = phead;
	while(curNode->next!=NULL){
		curNode = curNode->next;
	}
	
	//创建新结点 
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	
	curNode->next = newNode;
	phead->length++;
	return 1;		
} 

// 插入数据 
int insertData(Head * pHead, int data, int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos > pHead->length){
		printf("insert postion error!\n");
		return -2;
	}
	
	//创建新结点 
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	
	//创建当前结点
	ListNode * curNode = pHead;
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	newNode->next = curNode->next;
	curNode->next = newNode;	

	
	pHead->length++;
	
	return 1; 
}

// 删除数据 
int deleteData(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("delete postion error!\n");
		return -2;
	}
	
	//创建当前结点
	ListNode * curNode = pHead;
	
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	curNode->next = curNode->next->next;
	pHead->length--;
	return 1;
} 

//获取数据 
int getData(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("postion error!\n");
		return -2;
	}
	
	//创建当前结点
	ListNode * curNode = pHead;
	int i;
	for(i=0;i<=pos;i++){
		curNode = curNode->next;	
	}
	return curNode->data;
} 


//打印 
void print(Head * phead){
	if(phead==NULL){
		printf("not init headnode!\n");
		return 0;
	}

	ListNode * node = phead->next;
	while(node->next!=NULL){
		printf("%d->",node->data);
		node = node->next;
	}
	printf("%d  length=%d\n",node->data,phead->length);
}

int main(){
	int i;
	printf("create ListNode:\n");
	Head* pHead = createList();
	printf("length=%d\n\n",pHead->length);
	
	printf("add data:\n");
	for(i=0;i<10;i++){
		addData(pHead,i);
	}
	print(pHead) ;
	printf("\n");
	
	printf("insert data:\n");
	insertData(pHead,100,3);
	print(pHead);
	printf("\n");
	
	printf("delete data:\n");
	deleteData(pHead,3);
	print(pHead);
	printf("\n");
	
	printf("get data:\n");
	printf("%d\n",getData(pHead,5));
	printf("\n");
	
	return 0;
}


