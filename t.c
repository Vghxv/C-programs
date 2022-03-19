#include<stdio.h>
#include<stdlib.h>
int main(){
    int size = 10;
    int *arr=malloc(size*sizeof(int));
    int i;
    for(i=0;i<size;i++){
        scanf("%d",arr+i);
    }
    for(i=0;i<size;i++){
        printf("%d ,",*(arr+i));
    }
    return 0;
}
