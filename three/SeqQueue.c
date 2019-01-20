//˳���ʵ�ֶ���
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXSIZE 1024 

typedef struct Queue{
	int front;      //��ͷָ�� 
	int rear;		//��βָ�� 
	int data[MAXSIZE]; 
}SeqQueue;

//�������� 
SeqQueue* createSeqQueue(){
	SeqQueue * queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	queue->front = queue->rear = -1;
	memset(queue->data,0,MAXSIZE*sizeof(int));
	return queue;
}

//�ж��Ƿ�Ϊ�� 
int isEmpty(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue");
		return;
	}
	if(queue->front == queue->rear){
		return 1;
	}
	return 0;
}

//��ȡ���� 
int getLength(SeqQueue * queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		return queue->rear - queue->front; 
	}
	return 0;
}


//�����
int pushQueue(SeqQueue *queue,int data){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	//���� 
	if(queue->rear == MAXSIZE -1){
		printf("the queue already full ,not push!\n");
		return;
	}
	if(!isEmpty(queue)){
		queue->data[queue->rear] = data;
		queue->rear++;
	}else{
		queue->front = queue->rear = 0;
		queue->data[queue->rear] = data;
		queue->rear++;
	}
	return 1;
} 
//������
int outQueue(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		int temp = queue->data[queue->front];
		queue->front++;
		return temp;
	}else{
		printf("queue is null!");
		return;
	}
} 

//��ȡ��ͷ 
int getHead(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		return queue->data[queue->front];
	}else{
		printf("queue is null!");
		return;
	}
}

//��ն���
int clearQueue(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		queue->front = queue->rear = -1;
	}
	return 1;
} 

//���ٶ��� 
int destoryQueue(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	free(queue);
	return 1;
} 

//��ӡ
void print(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	printf("��ͷ-----------��β\n"); 
	int i;
	for(i=queue->front;i<queue->rear;i++){
		printf("%d ",queue->data[i]); 
	} 
	printf("     length = %d",getLength(queue));
	printf("\n");
} 

int main(){
	printf("Create Seq Queue��\n"); 
	SeqQueue * queue = createSeqQueue();
	printf("%d\n\n",queue);
	 
	printf("Push Seq Queue��\n"); 
	int i;
	for(i=0;i<10;i++){
		pushQueue(queue,i);
	}
	print(queue);
	printf("\n");
	
	printf("Out Seq Queue��\n"); 
	outQueue(queue);
	print(queue);
	printf("\n");
	
	printf("Get Head from Queue��\n"); 
	printf("%d\n",getHead(queue));
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
