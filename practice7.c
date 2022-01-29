#include<stdio.h>
#include<math.h>
int judge(int a,int b,int c){
    int temp=0;
    temp=pow(b,2)-4*a*c;
    if (temp>0||temp==0)return temp;
    else return -1;
}
int main()
{
    int a=0,b=0,c=0,D=0,r1=0,r2=0;
    char input[10]={};
    fgets(input,10,stdin);
    sscanf(input,"%d %d %d",&a, &b,&c );

    printf("the a, b, c is %d, %d, %d\n",a,b,c);
    D=judge(a,b,c);
    if (D!=-1){
        r1=(-b+sqrt(D))/(2*a);
        r2=(-b-sqrt(D))/(2*a);
        printf("answer is %d, %d",r1,r2);
    }
    else printf("discriminant is less than 0");


    return 0;
}
