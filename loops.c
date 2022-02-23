#include<stdio.h>
void L2H(int);
void H2L(int);
void ch(int);
void t(int,int);
int main(){
    int size=5,i;
    int s=size/2;
    printf("")
    //scanf("%d",&size);
    for(i=1;i<;i++){
        ch(-i);
        L2H(i);
        printf("%c",'\n');
    }
    return 0;
}


void L2H(int i){
    int j;
    for(j=1;j<i;j++)printf("%d",j);
}
void H2L(int i){
    int j;
    for(j=i;j>0;j--)printf("%d",j);
}
void ch(int i){
    int j;
    for(j=0;j<i;j++)printf("%c",'_');
}

void t(int i,int j){
    for(i=5;i>0;i--){
        for (j=i+4 ;j >5-i ;j-=2){
            printf("%d",j);
        }
    }
}
/*
97531
8642
753
64
5
__1__
_121_
12321
_121_
__1__
*/
