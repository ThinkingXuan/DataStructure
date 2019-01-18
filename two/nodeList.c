//���Ա����ʽ�洢

#include<stdio.h>
#include<stdlib.h>

//����ͷ��㣬length�洢����ĳ��� nextָ����һ����� 
typedef struct Header{
	int length;
	struct Header * next;
}Head;

//����һ����㣬data������ݣ�nextָ����һ����� 
typedef struct Node{
	int data;
	struct Node *next; 
}ListNode;

//����һ����������ͷ��� 
Head * createList(){
	Head *phead = (Head*)malloc(sizeof(Head));
	phead->length = 0;
	phead->next = NULL;
	return phead;
}

// ��ȡ������
int getLength(Head * phead){
	if(phead==NULL){
		printf("not init headnode!\n");
		return -1;
	}
	return phead->length;
} 

// ������ݣ�,Ĭ�������ĩβ 
int addData(Head * phead, int data){
	if(phead==NULL){
		printf("not init head node!\n");
		return -1;
	}	
	
	//������ǰ��㣬��ָ���������һ�����
	ListNode * curNode = phead;
	while(curNode->next!=NULL){
		curNode = curNode->next;
	}
	
	//�����½�� 
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	
	curNode->next = newNode;
	phead->length++;
	return 1;		
} 

// �������� 
int insertData(Head * pHead, int data, int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos > pHead->length){
		printf("insert postion error!\n");
		return -2;
	}
	
	//�����½�� 
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	
	//������ǰ���
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

// ɾ������ 
int deleteData(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("delete postion error!\n");
		return -2;
	}
	
	//������ǰ���
	ListNode * curNode = pHead;
	
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	curNode->next = curNode->next->next;
	pHead->length--;
	return 1;
} 

//��ȡ���� 
int getData(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("postion error!\n");
		return -2;
	}
	
	//������ǰ���
	ListNode * curNode = pHead;
	int i;
	for(i=0;i<=pos;i++){
		curNode = curNode->next;	
	}
	return curNode->data;
} 


//��ӡ 
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


