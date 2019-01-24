//�ַ�����ģʽƥ���㷨
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����ƽⷨ
int search(char *s, char *p){
	int lens = strlen(s);
	int lenp = strlen(p);
	int i=0,j=0;
	
	while(i<lens && j<lenp){
		
		if(s[i]!=p[j]){
			i = i - j + 1;      //��������һ��λ�ÿ�ʼ 
			j = 0;             //ģʽ����0��ʼ 
		}else{
			i++;
			j++;
		}
	}
	if(j==lenp){    //ƥ��ɹ� 
		return i-j; //j����p�ĳ��ȼ�1 , iΪs���������ַ�������1 ��i-jΪp��s��ƥ��ɹ����һ���ַ��Ŀ�ʼ�±�
	}else{ 			//û��ƥ��ɹ� 
		return -1; 
	}
}

//��̬�滮 
int dynamicSearch(char *s,char *p){
	int lens = strlen(s);
	int lenp = strlen(p);
	int temp[lens][lenp];
	int i,j;
	for(i=0;i<lens;i++){
		for(j=0;j<lenp;j++){
			if(j==0||i==0){
				if(p[j] == s[i]){
					temp[i][j] = 1;
				}else{
					temp[i][j] = 0;
				}
			}else{
				if(p[j] == s[i]){
					temp[i][j] = temp[i-1][j-1] + 1;
				}else{
					temp[i][j] = 0;
				}
			}
			
			if(temp[i][j] == lenp){
				return i - lenp +1;
			}
		}
	}
	return -1;
}

void getNext(char* p, int next[]){
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1){
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || p[j] == p[k]){
			++j;
			++k;
			//��֮ǰnext�����󷨣��Ķ�������4��
			if (p[j] != p[k])
				next[j] = k;   //֮ǰֻ����һ��
			else
				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]
				next[j] = next[k];
		}
		else{
			k = next[k];
		}
	}
}

//KMP�㷨
int kmpSearch(char *s,char *p){
	int lens = strlen(s);
	int lenp = strlen(p);
	int next[lenp];
	getNext(p,next);
	
	int k;
	int i=0,j=0;
	while(i<lens && j<lenp){
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
		}else{
			j = next[j];
		} 
	}
	if(j==lenp){    
		return i-j; 
	}else{ 	
		return -1; 
	}
}

int main(){
	char *s = "abcabgabcabay";
	char *p = "abcaba";
	printf("s = \"abcabgabcabay\"  p = \"abcaba\"\n");
	
	printf("���ص�ģʽƥ�䣺\n"); 
	int pos = search(s,p);
	printf("pos = %d\n",pos);
	
	printf("��̬�滮�㷨��\n");
	pos = kmpSearch(s,p);
	printf("pos = %d\n",pos);
	
	printf("KMP�㷨��\n");
	pos = dynamicSearch(s,p);
	printf("pos = %d\n",pos);
	
	return 0;
} 
