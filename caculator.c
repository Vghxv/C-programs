#include<stdio.h>
int main(){
    char op;
    double a=0;
    double b=0;
    double ans=0;
    printf("caculator on\n");
    scanf("%f%c%f",&a,&op,&b);
    switch(op){
        case '+':
            ans=a+b;
            break;
        case '-':
            ans=a-b;
            break;
        case '*':
            ans=a*b;
            break;
        case '/':
            ans=a/b;
            break;
        default:
            printf("incorrect input");
            break;

    }
    printf("%.3f",ans);

    return 0;
}
