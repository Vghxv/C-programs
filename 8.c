#include<stdio.h>
void dot1(int li){
    int i;
    int j;
    for (i=li;i>0;i--){
        for(j=0;j<i;j++)printf(".");
        for(j=0;j<li-i;j++)printf("*");
        for(j=0;j<li-i+1;j++)printf("*");
        printf("\n");
    }
}
void dot2(int li){
    int i;
    int j;
    for(i=0;i<li+1;i++){
        for(j=0;j<i;j++)printf(".");
        for(j=0;j<li-i;j++)printf("*");
        for(j=0;j<li-i+1;j++)printf("*");
        printf("\n");
    }
}
void mer1(int li){
    int i;
    int j;
    for(i=li;i>0;i--){
        for(j=0;j<i;j++)printf(".");
        for(j=0;j<li-i+1;j++)printf("*");
        printf("\n");
    }
}
void mer2(int li){
    int i;
    int j;
    for(i=0;i<li+1;i++){
        for(j=0;j<i;j++)printf(".");
        for(j=0;j<li-i+1;j++)printf("*");
        printf("\n");
    }
}
void star1(int li){
    int i;
    int j;
    for(i=1;i<=li;i++){
        for(j=0;j<i;j++)printf("*");
        printf("\n");
    }
}
void star2(int li){
    int i;
    int j;
    for (i=li+1;i>0;i--){
        for(j=0;j<i;j++)printf("*");
        printf("\n");
    }
}
int main(){
    int ch = 0;
    int li = 0;
    int tmp = 0;
    scanf("%d",&ch);
    scanf("%d",&li);
    tmp = (li-1)/2;
    if(ch==1){
        star1(tmp);
        star2(tmp);
    }
    else if(ch==2){
        mer1(tmp);
        mer2(tmp);
    }
    else{
        dot1(tmp);
        dot2(tmp);
    }
    return 0;
}
