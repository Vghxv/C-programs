#include<stdio.h>
#include<string.h>
#define BSIZE 100
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
    printf("\n");
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
void mul(int *arr1,int *arr2,int *ans){
    int i,j;
    int carry=0,tmp;
	for(i=0;i<BSIZE;i++){
        carry=0;
		for(j=0;j<BSIZE;j++){
			tmp = arr1[i]*arr2[j]+ans[i+j]+carry;
			carry = tmp/10;
            ans[i+j] = tmp%10;
        }
	}
}
int jgsize(int *arr1,int *arr2){
	int i=BSIZE-1,j=BSIZE-1;
	while(arr1[i]==0)i--;
	while(arr2[j]==0)j--;
	if(i<j)return 1;
	while(i==j&&i>-1){
		if(arr1[i]<arr2[j])return 1;
		i--;
		j--;
	}
	return 0;
}
int main(){
    int arr1[BSIZE],arr2[BSIZE],ans[2*BSIZE],cmdi;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    memset(ans,0,sizeof(ans));
    void(*func[])(int*,int*,int*) = {add,sub,mul};
	cmdi = getchar()-'1';
	getchar();
    input(arr1);
	input(arr2);
    if(jgsize(arr1,arr2)){
		func[cmdi](arr2,arr1,ans);
		if(cmdi==1)printf("-");
	}
	else{
		func[cmdi](arr1,arr2,ans);
	}
	print(ans);
    return 0;
}


