//��ʽ���� 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node; 

typedef struct queue{
	Node * front;
	Node * rear;
	int length;
}LinkQueue;

//�������� 
LinkQueue* createLinkQueue(){
	LinkQueue * queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->length = 0;
	return queue;
}

//�ж��Ƿ�Ϊ�� 
int isEmpty(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue");
		return;
	}
	if(queue->length==0 ){
		return 1;
	}
	return 0;
}

//��ȡ���� 
int getLength(LinkQueue * queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		return queue->length; 
	}
	return 0;
}


//�����
int pushQueue(LinkQueue *queue,int data){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	 
	 
	if(!isEmpty(queue)){
		queue->rear->next = newNode;
		queue->rear = newNode;
		queue->length++;
	}else{
		queue->front = newNode;
		queue->rear = newNode;
		queue->length++;
	}
	return 1;
} 
//������
Node * outQueue(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		Node * node = queue->front;
		queue->front = queue->front->next;
		queue->length--;
		return node;
	}else{
		printf("queue is null!");
		return;
	}
} 

//��ȡ��ͷ 
Node *  getHead(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		return queue->front;
	}else{
		printf("queue is null!");
		return;
	}
}

//��ն���
int clearQueue(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		queue->front = NULL;
		queue->rear = NULL;
		queue->length = 0;
	}
	return 1;
} 

//���ٶ��� 
int destoryQueue(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	free(queue);
	return 1; 
} 

//��ӡ
void print(LinkQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	printf("��ͷ-----------��β\n"); 
	int i;
	if(!isEmpty(queue)){
		Node *curNode = queue->front; 
		for(i=0;i<queue->length;i++){
			printf("%d ",curNode->data); 
			curNode = curNode->next;
		}
	}
	printf("     length = %d",getLength(queue));
	printf("\n");
} 

int main(){
	printf("Create Link Queue��\n"); 
	LinkQueue * queue = createLinkQueue();
	printf("%d\n\n",queue);
	 
	printf("Push Link Queue��\n"); 
	int i;
	for(i=0;i<10;i++){
		pushQueue(queue,i);
	}
	print(queue);
	printf("\n");
	
	printf("Out Link Queue��\n"); 
	outQueue(queue);
	print(queue);
	printf("\n");
	
	printf("Get Head from Link Queue��\n"); 
	printf("%d\n",getHead(queue)->data);
	printf("\n");
	
	printf("clear Queue��\n"); 
	clearQueue(queue);
	print(queue);
	
	printf("Destory Queue��\n"); 
	int flag = destoryQueue(queue);
	if(flag){
		printf("Destory Success!\n");
	}
	return 0;
}
