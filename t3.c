#include <stdio.h>
#include <string.h>
#define SIZE 69
int fibb(int n,int *f){
    if(!f[n])
        f[n]=fibb(n-1,f)+fibb(n-2,f);
    return f[n];
}
int main(){
    unsigned int f[SIZE];
    memset(f,0,SIZE*sizeof(int));
    f[0]=1;
    f[1]=1;
    printf("%u",fibb(2,f));
    return 0;
}