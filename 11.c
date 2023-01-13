#include<stdio.h>
#include<math.h>
void print(int *p){
    int i;
    for(i = 0;i < 11;i++){
        printf("%d",*(p+i));
    }
    printf("\n");
}
void d2b(int n,int *resp){
    int i;
    for(i = 0;i < 11;i++){
        resp[11-i-1]=n&1;
        n>>=1;
    }
}
int b2d(char *input){
    int i;
    int decimal=0;
    for(i = 0;i < 8;i++){
        if(*(input+7-i)-'0'==1)decimal+=pow(2,i);
    }
    return decimal;
}
int Out(int n){
    int i, count=0;
    for(i=0;i<n+1;i++){
        count+=C(i);
    }
    return count;
}
int C(int n){
    int count=0;
    while(n>1){
        if(n%2==1)n+=1;
        n>>=1;
        count++;
    }
    return count;
}
int main(){
    int i=0, j=0;
    int resp[11]={};
    int jg=0;
    char input[9];
    int storage[20]={};
    while(jg==0){
        fgets(input,9,stdin);
        scanf("%d%*c",&jg);
        storage[i] = Out(b2d(input));
        i++;
    }
    for(j = 0;j<i;j++){
        d2b(storage[j],resp);
        print(resp);
    }

    return 0;
}
