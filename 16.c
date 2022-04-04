#include<stdio.h>
#include<string.h>
#define BSIZE 100
void div(int *arr1,const int *arr2,int *ans){
	int i,j;
	int tenpower[BSIZE];
    int temp[BSIZE];
    int t[BSIZE];
	memset(tenpower,0,BSIZE*sizeof(int));
	for(i=BSIZE/2-1;i>-1;i--){
		for(j=9;j>-1;j--){
			memset(t,0,BSIZE*sizeof(int));
			memset(temp,0,BSIZE*sizeof(int));
			t[0]=j;
			tenpower[i]=1;
			mul(arr2,t,temp);
			memset(t,0,BSIZE*sizeof(int));
			mul(tenpower,temp,t);
			tenpower[i]=0;
			if(j==0){
				ans[i]=0;
			}
			else if(jgsize(arr1,t)<=0){
				sub(arr1,t,arr1);
				ans[i]=j;
				break;
			}
		}
	}
}
void mul(int *arr1,int *arr2,int *ans){
    int i,j;
    int carry=0,tmp;
	for(i=0;i<BSIZE/2;i++){
		for(j=0;j<BSIZE/2;j++){
			tmp = arr1[i]*arr2[j]+ans[i+j]+carry;
			carry = tmp/10;
            ans[i+j] = tmp%10;
        }
	}
}
int jgsize(int *arr1,int *arr2){
    int i;
    for(i=BSIZE-1;i>=0;i--){
        if(arr1[i]>arr2[i])return -1;
        else if(arr1[i]<arr2[i])return 1;
    }
    return 0;
}
void input(int *arr){
    char t[BSIZE];
    int i;
    memset(t,0,sizeof(t));
    scanf("%s",t);
    for(i=0;i<strlen(t);i++)arr[i] = t[strlen(t)-i-1]-'0';
}
void print(int *arr){
    int i=BSIZE-1;
	while(arr[i]==0){
		i--;
		if(i==-1){
			printf("0");
			break;
		}
	}
    while(i>-1)printf("%d",*(arr+i--));
}
void add(int *arr1,int *arr2,int *ans){
    int i,tmp;
	int carry=0;
    for(i=0;i<BSIZE;i++){
        tmp = arr1[i] + arr2[i] + carry;
		ans[i] = tmp%10;
        carry = tmp/10;
    }
}
void sub(int *arr1,int *arr2,int *ans){
    int i,borrow=0;
    for(i=0;i<BSIZE;i++){
		ans[i] = arr1[i] - arr2[i] - borrow;
		if(ans[i]<0){
			ans[i]+=10;
			borrow=1;
		}
		else{
			borrow=0;
		}
    }
}
int main(){
    int arr1[BSIZE],arr2[BSIZE],ans[2*BSIZE];
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    memset(ans,0,sizeof(ans));
    input(arr1);
	input(arr2);
	div(arr1,arr2,ans);
	print(ans);
    return 0;
}
