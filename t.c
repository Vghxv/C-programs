#include<stdio.h>
#include<stdlib.h>
int main(){
    char a[10];
    memset(a,'0',sizeof(a));
    int i;
    for(i=0;i<10;i++)printf("%d\n",a[i]);
    return 0;
}
