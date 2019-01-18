//双链表实现链式存储
 #include <stdio.h>
 #include <stdlib.h>

typedef struct Header{
	int length;
	struct Header * pre;  //为了方便，在头结点添加一个pre ，不然无法指向 Node,在Head后面添加结点时就需要单独判断。 
	struct Header * next;
}Head;

typedef struct Node{
	int data;
	struct Node * pre;          
	struct Node * next;
}NodeList;

//创建 
Head * createDouNodeList(){
	Head * pHead = (Head*)malloc(sizeof(Head));
	if(pHead == NULL){
		printf("create failure!\n"); 
	} 
	pHead->length = 0;
	pHead->next = NULL;
	return pHead;
}

// 获取链表长度
int getLength(Head * pHead){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	return pHead->length;
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

// 添加结点，,默认添加在末尾 
int addDataDou(Head * pHead, int data){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}	
	//创建当前结点，并指向链表最后一个结点
	NodeList * curNode = pHead; 

	while(curNode->next != NULL){
		curNode = curNode->next;
	}

	//创建新结点 
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data; 
	newNode->next = NULL;
	
	curNode->next = newNode;
	newNode->pre = curNode;
	pHead->length++;
	return 1;
} 

//插入 
int insertDou(Head *pHead,int data,int pos){
	
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	} 
	if(pos<=0||pos>=pHead->length){
		printf("insert positon error!\n");
		return -2;		
	}
	//创建新结点
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data;
	 
	//创建当前结点,并指向 指定位置之前的那个结点 
	NodeList * curNode = pHead;
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	//连接 
	newNode->next = curNode->next;
	curNode->next->pre = newNode;
	newNode->pre = curNode;
	curNode->next = newNode;
	
	pHead->length++;
	
	return 1;
} 

//删除 
int deleteDataDou(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("delete postion error!\n");
		return -2;
	}
	
	//创建当前结点
	NodeList * curNode = pHead;
	
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	curNode->next = curNode->next->next;
	
	//要删除最后一个结点时判断 
	if(curNode->next!=NULL){
		curNode->next->pre = curNode; 
	}
	
	pHead->length--;
	return 1;
} 

//打印 
void print(Head * pHead){
	if(pHead==NULL){
		printf("not init head node!\n");
		return 0;
	}
	NodeList * node = pHead->next;
	while(node->next!=NULL){
		printf("%d<->",node->data);
		node = node->next;
	}
	printf("%d  length=%d\n",node->data,pHead->length);
}

//查找某个元素，返回它的结点 
NodeList * findNodeDou(Head *pHead,int val){
	if(pHead==NULL){
		printf("not init head node!\n");
		return 0;
	}
	NodeList *curNode = pHead->next;
	do{
		if(curNode->data == val){
			return curNode;
		}
		curNode = curNode->next;
		
	}while(curNode->next!=NULL);
	return NULL;
} 
 
int main(){
	int i;
	
	printf("Create Double Node List: \n"); 
	Head  *pHead =  createDouNodeList();
	printf("length = %d\n",pHead->length);
	printf("\n");
	
	printf("Add Data: \n");
	for(i=0;i<10;i++){
		addDataDou(pHead,i); 
	}
	print(pHead);
	printf("\n");	
	
	printf("Insert Data: \n");
	insertDou(pHead,100,3);
	print(pHead);
	printf("\n");	
	
	printf("delete Data: \n");
	deleteDataDou(pHead,3);
	print(pHead);
	printf("\n");
	
	printf("find Node: \n");
	NodeList * node = findNodeDou(pHead,3);
	printf("node is %d\n",node);
	printf("\n");
	
	return 0;
} 

