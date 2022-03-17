#include<stdio.h>
int main(){
    int a=7;
    int b=6;
    int c=0;
    int d=0;
    c=a++ + b++;//14
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    d=a-- - --b;//2
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d",d);
    return 0;
}
