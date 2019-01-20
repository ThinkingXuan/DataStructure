//顺序表实现队列
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXSIZE 1024 

typedef struct Queue{
	int front;      //队头指针 
	int rear;		//队尾指针 
	int data[MAXSIZE]; 
}SeqQueue;

//创建队列 
SeqQueue* createSeqQueue(){
	SeqQueue * queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	queue->front = queue->rear = -1;
	memset(queue->data,0,MAXSIZE*sizeof(int));
	return queue;
}

//判断是否为空 
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

//获取长度 
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


//入队列
int pushQueue(SeqQueue *queue,int data){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	//已满 
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
//出队列
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

//获取队头 
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

//清空队列
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

//销毁队列 
int destoryQueue(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	free(queue);
	return 1;
} 

//打印
void print(SeqQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	printf("队头-----------队尾\n"); 
	int i;
	for(i=queue->front;i<queue->rear;i++){
		printf("%d ",queue->data[i]); 
	} 
	printf("     length = %d",getLength(queue));
	printf("\n");
} 

int main(){
	printf("Create Seq Queue：\n"); 
	SeqQueue * queue = createSeqQueue();
	printf("%d\n\n",queue);
	 
	printf("Push Seq Queue：\n"); 
	int i;
	for(i=0;i<10;i++){
		pushQueue(queue,i);
	}
	print(queue);
	printf("\n");
	
	printf("Out Seq Queue：\n"); 
	outQueue(queue);
	print(queue);
	printf("\n");
	
	printf("Get Head from Queue：\n"); 
	printf("%d\n",getHead(queue));
	printf("\n");
	
	printf("clear Queue：\n"); 
	clearQueue(queue);
	print(queue);
	
	printf("Destory Queue：\n"); 
	int flag = destoryQueue(queue);
	if(flag){
		printf("Destory Success!\n");
	}
	return 0;
}
