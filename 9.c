#include<stdio.h>
#include<math.h>

int main(){
    int bit = 0;
    int num = 0;
    int judge = 0;
    int a[10] = {};
    int i;
    do{
        scanf("%d %d",&bit,&num);
        scanf("%d",&judge);
        while(num!=0){
            a[i]=num%2;
            i++;
            num=floor(num/2);
        }
        for(; i>0;i--){
            printf("%d",a[i-1]);
        }
    }while(judge!=-1);
    return 0;
}
