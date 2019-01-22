//����˳��洢

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct str{
	char *str;      //��ָ�� 
	int length;		//���ĳ���	
}String; 

//��ֵ 
int strAssign(String * s,char *p){
	
	//��ȡp�ĳ��� 
	int i=0;
	while(p[i]!='\0'){
		i++;
	}
	//��str�����ڴ�
	s->str = (char *)malloc(sizeof(char) * (i+1));
	//��ֵ
	int j;
	for(j=0;j<i;j++){
		s->str[j] = p[j]; 
	} 
	s->str[j] = '\0';
	s->length = i;

	return 1;
}  
//��ȡ���ĳ���
int getLength(String *s){
	return s->length;
} 

//���ƴ�,��t���Ƶ�s�� 
void strCopy(String *s,String *t){
	s->str = (char*)malloc(sizeof(char) * (t->length+1));
	memset(s->str,'\0',t->length+1);
	int i;
	for(i=0;i<t->length;i++){
		s->str[i] = t->str[i];
	}
	s->length = t->length;
} 

//�ж��������Ƿ����
int strEqual(String *s1,String *s2){
	char *ss1 = s1->str;
	char *ss2 = s2->str; 

	if(s1->length != s2->length){
		return 0;
	}
	if(*ss1++ != *ss2++){
		return 0;
	}
	return 1;
} 

//����������
int strConnect(String *s,String *p){
	int len = s->length + p->length;
	
	//��ʱ�ռ� 
	char *temp = (char*)malloc(sizeof(char) * (len+1));
	int i,j;
	
	//����s 
	for(i=0;i<s->length;i++){
		temp[i] = s->str[i];
	}
	//����p 
	for(j=0;j<p->length;j++){
		temp[j+i] = p->str[j];
	}
	temp[j+i] = '\0';
	
	//�ַ���ָ��temp 
	s->str = temp;
	s->length = len;
	
	return 1;
} 

//�Ƚ��������Ĵ�С 
int strCompete(String *s,String *p){
	int slen = s->length;
	int plen = p->length;
	char *s1 = s->str;
	char *p1 = p->str;
	
	//ͬʱ���������ַ�������һ��Ϊ��ʱ����ѭ���� 
	while(*s1!='\0' && *p1!='\0'){
		// s > p 
		if(*s1 > *p1){
			return 1; 
		}
		//s < p 
		if(*s1 < *p1){
			return -1; 
		}
		s1++;
		p1++;  
	} 
	
	//�����ַ���ǰn���ַ����ʱ���Ƚϳ��� 
	if(slen == plen){  //s=p 
		return 0;
	}
	if(slen>plen){  //s>p
		return 1;
	}
	if(slen<plen){  //s<p 
		return -1;
	}
} 
//���봮  ���ַ���p���뵽s��ָ��λ���� 
int strInsert(String *s,String *p,int pos){
	//λ���ж�
	if(pos<0||pos>s->length){
		printf("insert position error!\n");
		return;
	} 
	
	int len = s->length + p->length;
	char * temp = (char *)malloc(sizeof(char)*(len+1));
	
	int i,j;
	
	//���� s����߲��� 
	for(i=0;i<pos;i++){
		temp[i] = s->str[i];
	} 
	//���� p 
	for(j=0;j<p->length;j++){
		temp[j+pos] = p->str[j];
	}
 	//���� s���ұ߲��� 
	for(;i<s->length;i++){
		temp[j+i] = s->str[i];
	} 
	temp[j+i] = '\0';
	s->str = temp;
	s->length = len;
} 

//ɾ�� 
int strDelete(String *s, int pos, int length){
	//λ���ж�
	if(pos<0||pos>s->length){
		printf("delete position error!\n");
		return;
	} 
	
	int len = s->length - length;
	char * temp = (char*)malloc(sizeof(char)*(len+1));
	
	int i,j;
	for(i=0;i<pos;i++){
		temp[i] = s->str[i]; 
	} 
	
	j = pos+length;
	for(;j<s->length;j++){
		temp[i] = s->str[j];
		i++;
	}
	temp[i] = '\0';
	s->str = temp;
	s->length = len;
	
	return 1;
}


int main(){
	printf("Create String:\n");
	String * s = (String *)malloc(sizeof(String));
	char *s1 = "abcdefg";
	strAssign(s,s1); 
	puts(s->str);
	
	printf("Length = %d\n",getLength(s));
	printf("\n");

	String * p = (String *)malloc(sizeof(String));	
	char *p1 = "abc";
	strAssign(p,p1); 

	printf("Copy String %s to %s:\n",s->str,p->str);
	strCopy(p,s);
	puts(s->str);
	printf("\n");
	
	printf("�Ƿ���ȣ�%d\n",strEqual(s,p));
	
	printf("Insert String %s to %s:\n",p->str,s->str);
	strInsert(s,p,2);
	
	puts(s->str);
	printf("\n");
	
	printf("Delete String:\n");
	strDelete(s,2,3);
	puts(s->str);
	
	return 0;
} 
