//˫����ʵ����ʽ�洢
 #include <stdio.h>
 #include <stdlib.h>

typedef struct Header{
	int length;
	struct Header * pre;  //Ϊ�˷��㣬��ͷ������һ��pre ����Ȼ�޷�ָ�� Node,��Head������ӽ��ʱ����Ҫ�����жϡ� 
	struct Header * next;
}Head;

typedef struct Node{
	int data;
	struct Node * pre;          
	struct Node * next;
}NodeList;

//���� 
Head * createDouNodeList(){
	Head * pHead = (Head*)malloc(sizeof(Head));
	if(pHead == NULL){
		printf("create failure!\n"); 
	} 
	pHead->length = 0;
	pHead->next = NULL;
	return pHead;
}

// ��ȡ������
int getLength(Head * pHead){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	return pHead->length;
}

//�ж��Ƿ�Ϊ��
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

// ��ӽ�㣬,Ĭ�������ĩβ 
int addDataDou(Head * pHead, int data){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}	
	//������ǰ��㣬��ָ���������һ�����
	NodeList * curNode = pHead; 

	while(curNode->next != NULL){
		curNode = curNode->next;
	}

	//�����½�� 
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data; 
	newNode->next = NULL;
	
	curNode->next = newNode;
	newNode->pre = curNode;
	pHead->length++;
	return 1;
} 

//���� 
int insertDou(Head *pHead,int data,int pos){
	
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	} 
	if(pos<=0||pos>=pHead->length){
		printf("insert positon error!\n");
		return -2;		
	}
	//�����½��
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data;
	 
	//������ǰ���,��ָ�� ָ��λ��֮ǰ���Ǹ���� 
	NodeList * curNode = pHead;
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	//���� 
	newNode->next = curNode->next;
	curNode->next->pre = newNode;
	newNode->pre = curNode;
	curNode->next = newNode;
	
	pHead->length++;
	
	return 1;
} 

//ɾ�� 
int deleteDataDou(Head * pHead,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos >= pHead->length){
		printf("delete postion error!\n");
		return -2;
	}
	
	//������ǰ���
	NodeList * curNode = pHead;
	
	int i;
	for(i=0;i<pos;i++){
		curNode = curNode->next;	
	}
	
	curNode->next = curNode->next->next;
	
	//Ҫɾ�����һ�����ʱ�ж� 
	if(curNode->next!=NULL){
		curNode->next->pre = curNode; 
	}
	
	pHead->length--;
	return 1;
} 

//��ӡ 
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

//����ĳ��Ԫ�أ��������Ľ�� 
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

