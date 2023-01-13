#include<stdio.h>
#include<string.h>
#define BS 100
void add(const int *a,const int *b,int *c){
	int i,carry=0,t;
	for(i=0;i<BS-1;i++){
		t=a[i]+b[i]+carry;
		c[i] = t%10;
		carry/=10;
	}
}
void input(int *a){
	int i,L;
	char tmp[BS];
	scanf("%s",tmp);
	L=strlen(tmp);
	for(i=0;i<L;i++){
		a[L-1-i] = tmp[i]-'0';
	}
}
void print(int *a){
	int i=BS-1;
	while(a[i]==0)i--;
	while(i>=0)printf("%d",a[i--]);
}
int main(){
	int arr1[BS],arr2[BS],ans[BS];
	memset(arr1,0,sizeof(arr1));
	memset(arr2,0,sizeof(arr2));
	memset(ans,0,sizeof(ans));
	input(arr1);
	print(arr1);
	return 0;
}