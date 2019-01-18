//循环链表
 
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
}NodeList;

//创建一个链表，返回头结点 
Head * createList(){
	Head *phead = (Head*)malloc(sizeof(Head));
	phead->length = 0;
	phead->next = NULL;
	return phead;
}

//判断是否为空
int isEmpty(Head *pHead){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pHead->length==0){
		return 1;
	}else{
		return 0;
	}
}

int insertCircleList(Head * pHead,int data,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos > pHead->length){
		printf("insert postion error!\n");
		return -2;
	}
	
	//创建新结点 
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data;
	
	//如果是空 
	if(isEmpty(pHead)){
		pHead->next = newNode;   //直接插入到头结点后面
		newNode->next = newNode; //自己指向自己 
	}else{
		
		NodeList *curNode = pHead->next;
		
		//因为pos ==0为涉及到头结点，单独处理 
		if(pos==0){
			
			//curNode指向尾结点
			while(curNode->next!=pHead->next){
				curNode = curNode->next;
			}
			
			newNode->next =pHead->next;
			pHead->next = newNode;
			curNode->next = newNode; 
		}else{
			//使curNode指向插入位置的前一个结点 
			int i;
			for(i=1;i<pos;i++){
				curNode = curNode->next;
			}
			
			newNode->next = curNode->next;
			curNode->next = newNode; 
			
		}
	} 
	
	pHead->length++;
	
	return 1;
}

int deleteCircleNode(Head *pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos > pHead->length){
		printf("insert postion error!\n");
		return -2;
	}
	
	NodeList *curNode = pHead->next;
	
	if(isEmpty(pHead)){
		return -3;
	}else{
		if(pos==0){
			while(curNode->next!=pHead->next){
				curNode = curNode->next;
			} 
			
			curNode->next = curNode ->next->next;
			pHead->next = curNode ->next;
		}else{
			int i;
			for(i=1;i<pos;i++){
				curNode = curNode->next;
			}
			curNode ->next = curNode->next->next;
		}
	}
	
	pHead->length--;
	return 1; 
} 
//打印 
void print(Head *pHead){
	if(pHead==NULL){
		printf("not init headnode!\n");
		return 0;
	}

	NodeList * node = pHead->next;
	do{
		printf("%d->",node->data);
		node = node->next;
	}while(node!=pHead->next);

	printf("   length=%d\n",pHead->length);
}
int main(){
	int i;
	printf("Create Circle Node List: \n");
	Head * pHead = createList();
	printf("length = %d\n",pHead->length);
	printf("\n");
	
	printf("Insert Node: \n");
	for(i=0;i<11;i++){
		insertCircleList(pHead,i,i);
	}
	print(pHead);
	printf("\n");
	
	printf("Delete Node: \n");
	deleteCircleNode(pHead,0);
	print(pHead);
	return 0;
}

