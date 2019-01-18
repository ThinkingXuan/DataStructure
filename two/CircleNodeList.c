//ѭ������
 
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
}NodeList;

//����һ����������ͷ��� 
Head * createList(){
	Head *phead = (Head*)malloc(sizeof(Head));
	phead->length = 0;
	phead->next = NULL;
	return phead;
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

int insertCircleList(Head * pHead,int data,int pos){
	if(pHead==NULL){
		printf("not init head node!\n");
		return -1;
	}
	if(pos < 0||pos > pHead->length){
		printf("insert postion error!\n");
		return -2;
	}
	
	//�����½�� 
	NodeList * newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->data = data;
	
	//����ǿ� 
	if(isEmpty(pHead)){
		pHead->next = newNode;   //ֱ�Ӳ��뵽ͷ������
		newNode->next = newNode; //�Լ�ָ���Լ� 
	}else{
		
		NodeList *curNode = pHead->next;
		
		//��Ϊpos ==0Ϊ�漰��ͷ��㣬�������� 
		if(pos==0){
			
			//curNodeָ��β���
			while(curNode->next!=pHead->next){
				curNode = curNode->next;
			}
			
			newNode->next =pHead->next;
			pHead->next = newNode;
			curNode->next = newNode; 
		}else{
			//ʹcurNodeָ�����λ�õ�ǰһ����� 
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
//��ӡ 
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

