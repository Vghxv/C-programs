#include<stdio.h>
int main(){
    int i=0;
    int *ptr;
    ptr=&i;
    *ptr=100;
    printf("The \"ptr\" value is %d\n",*ptr);
    printf("The \"ptr\" points to %u\n",ptr);
    return 0;
}

