#include<stdio.h>
/*
int sort(int a[],int an,int b[],int bn,int c[]){
    int i,cursor=0;


    for(i=0;i<an;i++){
        if(i<bn){

            if(a[i]>b[i]){
                c[i+cursor] = a[i];
                c[i+cursor+1] = b[i];
            }
            else{
                c[i+cursor] = b[i];
                c[i+cursor+1] = a[i];
            }
            cursor++;
        }
        else{
            c[i] = a[i];S
        }
    }
    return an +bn;
}
*/
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
int merge(int a[],int an,int b[],int bn,int c[]){
    int i=0,j=0,k=0;
    if(i<an&&j<bn){
        if(a[i]>b[i]){
            c[k++] = a[i++];
            c[k++] = b[j++];
        }
        else{
            c[k++] = b[j++];
            c[k++] = a[i++];
        }
    }
    if(i<an)c[k++] = a[i++];
    if(j<bn)c[k++] = b[j++];
    return k;
}

int main(){
    int *arr = malloc(80);
    inputarr(arr,20)

    return 0;
}
