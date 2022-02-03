#include<stdio.h>
int main(){
    int i,j;
    for(i=5;i>0;i--){
        for (j=i+4 ;j >5-i ;j-=2){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}
/*
97531
8642
753
64
5
*/
