#include<stdio.h>
#include<stdlib.h>
#define BSIZE 80
void swap(int *n1,int *n2){
    int tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void reverse(int *arr){
    int i;
    int len = flen(arr);
    for(i=0;i<len/2;i++){
        swap(arr+i,arr+len-i-1);
    }
}
int flen(int *arr){
    int len;
    for(len=BSIZE-1;len>0;len--){
        if(*(arr+len)!=-1)break;
    }
    return len+1;

}

int max(int a,int b){return (a>b)?a:b;}

void print(int *arr){
    int i;
    for(i=0;i<50;i++){
        printf("%d",*(arr+i));
    }
    printf("\n");
}

void input(int *arr){
    char t[BSIZE];
    int tL;
    int i;
    memset(t,0,sizeof(t));
    scanf("%s",t);
    tL = strlen(t);
    for(i=0;i<tL;i++){
        arr[i] = t[i]-'0';
    }

}

void add(int *arr1,int *arr2,int *ans){
    int i;
    int carry = 0;
    int len = max(flen(arr1),flen(arr2));
    //printf("%d%d\n",flen(arr1),flen(arr2));
    for(i=0;i<=len;i++){

        ans[i] = arr1[i] + arr2[i] + carry;
        carry = ans[i] / 10;
        ans[i] %= 10 ;
    }


}
void sub(int *arr1,int *arr2,int *ans){
    int i;
    int len = max(flen(arr1),flen(arr2));
    for(i=0;i<len;i++){
        if(arr1[i]<arr2[i]){
            //arr1[i+1]--;
            ans[i] = 10 + arr1[i] - arr2[i];
        }
        else{
            ans[i] = arr1[i] - arr2[i];
        }
    }

}
int main(){
    int arr1[BSIZE],arr2[BSIZE],ans[BSIZE];
    int i;

    memset(arr1,-1,sizeof(arr1));
    memset(arr2,-1,sizeof(arr2));
    memset(ans,-1,sizeof(ans));
    input(arr1);
    input(arr2);
    reverse(arr1);
    reverse(arr2);
    add(arr1,arr2,ans);
    //print(arr1);
    //print(arr2);
    //sub(arr1,arr2,ans);
    print(ans);


    return 0;
}
