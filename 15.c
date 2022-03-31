#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BSIZE 80
void input(int *arr){
    char t[BSIZE];
    int tL;
    int i;
    memset(t,0,sizeof(t));
    scanf("%s",t);
    tL = strlen(t);
    for(i=tL-1;i>-1;i--){
        arr[i] = t[i]-'0';
    }
}
void print(int *arr){
    int i=BSIZE-1;
    int is_0=0;
    while(arr[i]==0){
        i--;
    }
    while(i>-1){
        printf("%d",*(arr+i));
    }
    printf("\n");
}
void add(int *arr1,int *arr2,int *ans){
    int i;
    int carry=0;
    int len = max(flen(arr1),flen(arr2));
    for(i=0;i<=len;i++){
        if(i==len){
            ans[i] = carry;
        }
        else{
            if(arr2[i]==-1){
                ans[i] = arr1[i] + carry;
            }
            else{
                ans[i] = arr1[i] + arr2[i] + carry;
            }
            carry = ans[i] / 10;
            ans[i] %= 10 ;
        }
    }
    ans[i]=-1;
}
void sub(int *arr1,int *arr2,int *ans){
    int i;
    int len = max(flen(arr1),flen(arr2));
    for(i=0;i<len;i++){
        if(arr2[i]==-1)arr2[i]=0;
        if(arr1[i]<arr2[i]){
            arr1[i+1]--;
            ans[i] = 10 + arr1[i] - arr2[i];
        }
        else{
            ans[i] = arr1[i] - arr2[i];
        }
    }
    ans[i]=-1;
}

void mul(int *arr1,int *arr2,int *ans){
    int i,j,k;
    int carry=0;
    int tmp[BSIZE];
    for(j=0;j<flen(arr2);j++){
        memset(tmp,0,sizeof(tmp));
        for(i=0;i<flen(arr1);i++){
            tmp[i+j]=arr1[i]*arr2[j]+carry;
            carry = tmp[i+j]/10;
            tmp[i+j]%=10;
        }
        tmp[i+j]=-1;
		print(tmp);
        for(k=0;k<flen(tmp);k++){
            ans[k]+=tmp[k];
        }
    }
    ans[k]=-1;
    for(k=0;k<flen(ans);k++){
        ans[k]+=carry;
        carry=ans[k]/10;
        ans[k]%=10;
    }
    ans[k]=-1;
}

int main(){
    int arr1[BSIZE],arr2[BSIZE],ans[BSIZE];
    int i;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    memset(ans,0,sizeof(ans));
    input(arr1);
    input(arr2);
    //reverse(arr1);
    //reverse(arr2);
    //cmpnum(arr1,arr2);
    //int *tp;
    //int L1 = flen(arr1);
    //int L2 = flen(arr2);
    //if(L1<L2||(L1==L2&&*(arr1+L1-1)<*(arr2+L2-1))){
    //tp=arr1;
    //arr1=arr2;
    //arr2=tp;
    //}
    //add(arr1,arr2,ans);
    //sub(arr1,arr2,ans);
    print(arr1);
    print(arr2);
    //mul(arr1,arr2,ans);
    //mul(arr1,arr2,ans);
    //reverse(ans);
    //print(ans);
    return 0;
}


