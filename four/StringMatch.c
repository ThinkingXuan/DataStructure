//字符串的模式匹配算法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//暴力破解法
int search(char *s, char *p){
	int lens = strlen(s);
	int lenp = strlen(p);
	int i=0,j=0;
	
	while(i<lens && j<lenp){
		
		if(s[i]!=p[j]){
			i = i - j + 1;      //主串从下一个位置开始 
			j = 0;             //模式串从0开始 
		}else{
			i++;
			j++;
		}
	}
	if(j==lenp){    //匹配成功 
		return i-j; //j代表p的长度减1 , i为s中搜索的字符个数减1 。i-j为p在s中匹配成功后第一个字符的开始下标
	}else{ 			//没有匹配成功 
		return -1; 
	}
}

//动态规划 
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
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k]){
			++j;
			++k;
			//较之前next数组求法，改动在下面4行
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
				next[j] = next[k];
		}
		else{
			k = next[k];
		}
	}
}

//KMP算法
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
	
	printf("朴素的模式匹配：\n"); 
	int pos = search(s,p);
	printf("pos = %d\n",pos);
	
	printf("动态规划算法：\n");
	pos = kmpSearch(s,p);
	printf("pos = %d\n",pos);
	
	printf("KMP算法：\n");
	pos = dynamicSearch(s,p);
	printf("pos = %d\n",pos);
	
	return 0;
} 
