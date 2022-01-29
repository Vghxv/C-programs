#include<stdio.h>
int main(){
    int a=7,b=6,c,d;
    c=a++ + ++b;///14
    d=a-- - --b;//2
    printf("%d\n",c);
    printf("%d",d);
    return 0;
}
