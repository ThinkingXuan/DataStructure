//ѭ������
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXSIZE 1024 

typedef struct Queue{
	int front;      //��ͷָ�� 
	int rear;		//��βָ�� 
	int data[MAXSIZE]; 
}CircleQueue;

//�������� 
CircleQueue* createCircleQueue(){
	CircleQueue * queue = (CircleQueue*)malloc(sizeof(CircleQueue));
	queue->front = queue->rear = -1;
	memset(queue->data,0,MAXSIZE*sizeof(int));
	return queue;
}

//�ж��Ƿ�Ϊ�� 
int isEmpty(CircleQueue *queue){
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
int getLength(CircleQueue * queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		int front = queue->front;
		int rear = queue->rear;
		return (rear + MAXSIZE - front) % MAXSIZE; 
	}
	return 0;
}


//�����
int pushQueue(CircleQueue *queue,int data){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	
	//���� 
	int rear = queue->rear;
	int front  = queue->front;
	if((rear+1) % MAXSIZE == front){
		printf("the queue already full ,not push!\n");
		return;
	}
	if(!isEmpty(queue)){
		queue->data[queue->rear] = data;
		queue->rear = (queue->rear+1) % MAXSIZE;
	}else{
		queue->front = queue->rear = 0;
		queue->data[queue->rear] = data;
		queue->rear++;
	}
	return 1;
} 
//������
int outQueue(CircleQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	if(!isEmpty(queue)){
		int temp = queue->data[queue->front];
		queue->front = (queue->front+1) % MAXSIZE;
		return temp;
	}else{
		printf("queue is null!");
		return;
	}
} 

//��ȡ��ͷ 
int getHead(CircleQueue *queue){
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
int clearQueue(CircleQueue *queue){
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
int destoryQueue(CircleQueue *queue){
	if(queue==NULL){
		printf("not init queue!\n");
		return;
	}
	free(queue);
	return 1;
} 

//��ӡ
void print(CircleQueue *queue){
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
	printf("Create Circle Queue��\n"); 
	CircleQueue * queue = createCircleQueue();
	printf("%d\n\n",queue);
	 
	printf("Push Circle Queue��\n"); 
	int i;
	for(i=0;i<10;i++){
		pushQueue(queue,i);
	}
	print(queue);
	printf("\n");
	
	printf("Out Circle Queue��\n"); 
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
