#include<stdio.h>

int main(){
    int bit = 0;
    int num = 0;
    int judge = 0;
    int bin[20] = {};
    int i = 0;
    do{
        scanf("%d%d%d",&bit,&num,&judge);
        for(;i<bit;i++){
            bin[i] = (num^(num>>1))&1;
            num>>=1;
        }
        for(;i>0;i--)printf("%d",bin[i-1]);
        printf("\n");
    }while(judge!=-1);

    return 0;
}
