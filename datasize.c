#include<stdio.h>
int main(){
    int i=0x4142;
    long j=0x43444546L;
    printf("Size of int i:%d\n",sizeof(i));
    printf("Size of int j:%d\n",sizeof(j));

    printf("%d\n",i);
    printf("%d\n",j);
    return 0;
}
