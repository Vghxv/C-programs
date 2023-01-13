#include<stdio.h>
int main(){
    int m1;
    int m2;
    float x;
    float y;
    scanf(" %d",&m1);
    scanf( "%d",&m2);
    scanf(" %f",&x);
    scanf(" %f",&y);
    printf("%.1f\n",(m1+m2)*x*0.92-y*0.05);
    printf("%.1f\n",y*0.05);
    printf("%.1f",(m1+m2)*x*0.08);

    return 0;
}
