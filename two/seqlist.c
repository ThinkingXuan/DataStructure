#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结点
typedef struct SeqList {            //包含表的各种属性
	int capacity;        // 容量
	int length; 		//长度
	int * node;       	//指针数组
} HSeqList;

//创建顺序表
HSeqList * createSeqList(int capacity) {
	int ret;
	HSeqList * head = (HSeqList *)malloc(sizeof(HSeqList));

	if(head == NULL) {
		ret = 1;
		printf("create seqList error %d\n",ret);
		return NULL;
	}

	memset(head,0,sizeof(HSeqList));       //清空头结点
	head->capacity = capacity;
	head->length = 0;
	head->node = (int *) malloc(sizeof(void *)*capacity);

	if(head->node == NULL) {
		ret = 2;
		printf("create seqList error %d\n",ret);
		return NULL;
	}

	return head;
}

//添加数据
int addData(HSeqList * list,int data) {
	if(list == NULL) {
		printf("not init SeqList\n");
		return 0;
	}
	if(list->length>=list->capacity) {
		printf("SeqList is full,not add data,current data is %d\n",data);
		return 0;
	}
	int index = list->length;
	list->node[index] = data;
	list->length++;
	return 1;
}


//求顺序表容量
int getCapacity(HSeqList * list) {
	HSeqList * temp = NULL;
	if(list == NULL) {
		return;
	}
	temp = list;
	return temp->capacity;
}
//求顺序表长度
int getLength(HSeqList * list) {
	HSeqList * temp = NULL;
	if(list == NULL) {
		return;
	}
	temp = list;
	return temp->length;
}

//输出
void print(HSeqList * list) {
	if(list == NULL) {
		printf("not init SeqList\n");
		return;
	}
	int length = getLength(list);
	int i;
	printf("[");
	for(i=0; i<length-1; i++) {
		printf("%d,",list->node[i]);
	}
	printf("%d]\n",list->node[i]);
}
//插入
int insert(HSeqList *list,int data,int pos) {
	int i;
	if(list == NULL) {
		printf("not init SeqList\n");
		return -1;
	}
	if(list->length>=list->capacity) {
		printf("SeqList is full,not insert data,current data is %d\n",data);
		return -2;
	}

	//如何插入位置在length之前，则默认插入到最后一位
	if(pos>list->length) {
		pos = list->length;
	}
	//从后往前移位，防止数据丢失
	for(i=list->length; i>pos; i--) {
		list->node[i] = list->node[i-1];
	}
	//插入数据
	list->node[i] = data;
	//增加长度
	list->length ++;

	return 1;
}

//删除
int delete(HSeqList *list, int pos) {
	if(list == NULL) {
		printf("not init SeqList!\n");
		return -1;
	}
	if(list->length <= 0) {
		printf("SeqList not data!\n");
		return -2;
	}
	
	if(pos < 0 || pos >list->length){
		printf("delete position error!\n");
		return -3;
	}
	
	int i;
	for(i=pos; i<=list->length;i++){
		list->node[i] = list->node[i+1];
	}
	
	list->length--;
	return 1;
}

//查找某个位置上的指定元素
int getData(HSeqList *list,int pos){
	if(list == NULL) {
		printf("not init SeqList!\n");
		return -1;
	}
	if(pos < 0 || pos >=list->length){
		printf("position error!\n");
		return -3;
	}
	
	return list->node[pos];
}

//清空表
int clear(HSeqList *list){
	if(list == NULL) {
		printf("not init SeqList!\n");
		return -1;
	}
	list->length = 0;
	memset(list->node,0,(list->capacity * sizeof(void *)));
	return 1;
}
int main() {
	
	printf("init:\n");
	int capacity = 100;
	HSeqList *list = createSeqList(capacity);
	int s = getCapacity(list);
	printf("Capacity = %d\n",s);

	printf("addData:\n");
	int i;
	for(i=0; i<10; i++) {
		addData(list,i);
	}
	print(list);
	
	printf("insert:\n");
	insert(list,100,3);
	print(list);
	printf("delete:\n");
	delete(list,3);
	print(list);
	
	printf("getData:\n");
	printf("index %d is %d\n",0,getData(list,0));
	
	printf("clear:\n");
	clear(list);
	print(list);
	return 0;
}


