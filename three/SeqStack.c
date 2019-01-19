//顺序表实现栈 
#include<stdio.h>
#include<stdlib.h>
 
#define MAXSIZE 1024
 
typedef struct stack{
	
	int data[MAXSIZE];   
	int top; 		//栈顶指针 
}SeqStack;

//创建栈 
SeqStack * createSeqStack(){
	SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
	stack->top = -1;
}
//判断空
int isEmpty(SeqStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(stack->top == -1){
		return 1;
	}
	return 0;
} 
//获取栈顶元素
int getTopStack(SeqStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(!isEmpty(stack)){
		return stack->data[stack->top];
	}
	
	return -2;
} 

//出栈 
int popStack(SeqStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(!isEmpty(stack)){
		 return stack->data[stack->top--];
	}
	return -2;
}

//入栈 
int pushStack(SeqStack *stack,int data){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	//判断是否栈满
	if(stack->top == MAXSIZE-1){
		printf("stacl already full!\n");
		return -3;
	} 
	stack->top++;
	stack->data[stack->top] = data;
	return 1;
}

//销毁栈
int destoryStack(SeqStack *stack) {
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	if(!isEmpty(stack)){
		 free(stack);
	}
	return 1;
}

//打印
void print(SeqStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return;
	}
	int i;
	for(i=0;i<=stack->top;i++){
		printf("%d ",stack->data[i]);
	}
	printf("\n");
} 
int main(){
	printf("Create Stack：\n"); 
	SeqStack * stack = createSeqStack();
	printf("%d\n\n",stack);
	 
	printf("Push Stack：\n"); 
	int i;
	for(i=0;i<10;i++){
		pushStack(stack,i);
	}
	print(stack);
	printf("\n");
	
	printf("Pop Stack：\n"); 
	popStack(stack);
	print(stack);
	printf("\n");
	
	printf("Get top from stack：\n"); 
	printf("%d\n",getTopStack(stack));
	printf("\n");
	
	printf("Destory stack：\n"); 
	int flag = destoryStack(stack);
	if(flag){
		printf("Destory Success!\n");
	}
	return 0;
} 
