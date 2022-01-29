#include<stdio.h>
int main(){
    int i,*ptr;
    ptr=&i;
    *ptr=100;
    printf("The \"ptr\" value is %d\n",*ptr);
    printf("The \"ptr\" points to %u\n",ptr);
    return 0;
}

