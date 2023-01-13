#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int *arr,int front,int end){
    int pivot = *(arr+end);
    int pivot_i = front-1;
    int j;
    for(j=front;j<end;j++){
        if(*(arr+j)<pivot){
            pivot_i++;
            swap(arr+pivot_i,arr+j);
        }
    }
    pivot_i++;
    swap(arr+pivot_i,arr+j);
    return pivot_i;
}
void qs(int *arr,int front,int end){
    if(front<end){
        int pivot_i = partition(arr,front,end);
        qs(arr,front,pivot_i-1);
        qs(arr,pivot_i+1,end);
    }
}
void printarr(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        if(i!=0)printf(", %d",*(arr+i));
        else printf("%d",*(arr+i));
    }
}
void inputarr(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        scanf("%d",arr+i);
    }
}
int main(){
    int i;
    int size=10;
    int *arr=malloc(size*sizeof(int));
    printf("arr size?\n");
    scanf("%d",&size);
    printf("enter a unsorted array:\n");
    inputarr(arr,size);
    qs(arr,0,size-1);
    printarr(arr,size);
    free(arr);
    return 0;

}
/*
10
7 5 3 9 1 0 2 4 6 8
10
12 34 56 78 91 23 45 6 78 9
16
12 34 56 78 91 23 45 6 78 9 0 9 646 1 -1 -0.234



*/