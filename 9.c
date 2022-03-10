#include<stdio.h>
#include<math.h>
int *garycode(int *bin,int bit){
    int i;
    for(i=1;i<bit;i++){
        bin[i] = bin[i]^bin[i-1];
    }
    return bin;
}
int main(){
    int bit = 0;
    int num = 0;
    int judge = 0;
    int bin[20] = {};
    int *pbin;
    int i=0,j;
    do{
        scanf("%d %d",&bit,&num);
        scanf("%d",&judge);
        while(num!=0){
            bin[i]=num%2;
            i++;
            num/=2;
        }
        for(j=i;j<bit;j++){
            bin[j]=0;
        }
        pbin=garycode(bin,bit);
        for(;j>0;j--){
            printf("%d",*(pbin+j-1));
        }
        //printf("\n");
    }while(judge!=-1);
    return 0;
}
