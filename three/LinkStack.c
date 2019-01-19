//单链表实现栈 
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct stack{
	int size;                //栈大小 
	struct node *top;		//栈顶指针 
}LinkStack;

LinkStack * createLinkStack(){
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	if(stack!=NULL){
		stack->top = NULL;
		stack->size = 0;
	}
	return stack; 
}
//判断空
int isEmpty(LinkStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(stack->top == NULL || stack->size <=0){
		return 1;
	}
	return 0;
} 
//获取栈顶元素
Node * getTopStack(LinkStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(!isEmpty(stack)){
		return stack->top;
	}
	
	return -2;
} 

//出栈 
Node * popStack(LinkStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	
	if(!isEmpty(stack)){
		Node * topNode = stack->top; 
		stack->top = stack->top->next;
		stack->size--;
		return topNode;
	}
	return -2;
}

//入栈 
int pushStack(LinkStack *stack,int data){
	
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}

	Node * node = (Node*)malloc(sizeof(Node));
	node->data = data;
	
	if(!isEmpty(stack)){ //不是空 
		node->next = stack->top;
		stack->top = node;
	}else{ 				//是空 
		stack->top =  node;
	}
	stack->size++;
	return 1;
}

//销毁栈
int destoryStack(LinkStack *stack) {
	if(stack == NULL){
		printf("not init stack!\n");
		return -1;
	}
	if(!isEmpty(stack)){
		do{
			Node * node;
			node = popStack(stack);
			free(node);
		}while(stack->size>0);
		 
	}
	return 1;
}

//打印
void print(LinkStack *stack){
	if(stack == NULL){
		printf("not init stack!\n");
		return;
	}
	int i;
	Node * curNode = stack->top;
	
	//curNode指向栈底 
	printf("栈顶<----------栈底\n"); 
	for(i=0;i<stack->size;i++){
		printf("%d ",curNode->data); 
		curNode = curNode->next; 
	}
	
	printf("\n");
} 

int main(){
	printf("Create Link Stack：\n"); 
	LinkStack * stack = createLinkStack();
	printf("%d\n\n",stack);
	 
	printf("Push Link Stack：\n"); 
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
	printf("%d\n",getTopStack(stack)->data);
	printf("\n");
	
	printf("Destory stack：\n"); 
	int flag = destoryStack(stack);
	print(stack);
	if(flag){
		printf("Destory Success!\n");
	}
	return 0;
} 
