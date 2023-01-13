#include<stdio.h>
#include<string.h>
float tp(char *s){
    float tmp = 0;

    if(strcmp(s,"10")==0)tmp+=10;

    else if(strcmp(s,"J")==0||strcmp(s,"Q")==0||strcmp(s,"K")==0)tmp+=0.5;

    else if(strcmp(s,"A")==0)tmp+=1;

    else tmp+=s[0]-'0';

    return tmp;
}
int main(){
    char s[3]={0,0,0};
    float as = 0,bs = 0;
    int judge = 0;
    int i;

    for(i=0;i<3;i++){
        scanf("%s",s);
        as+=tp(s);
        memset(s,0,3);
    }

    for(i=0;i<3;i++){
        scanf("%s",s);
        bs+=tp(s);
        memset(s,0,3);
    }
    if(as>10.5){
        as = 0;
    }
    if(bs>10.5){
        bs = 0;
    }
    printf("%.1f\n",as);
    printf("%.1f\n",bs);

    if(as>bs)printf("A wins.");

    else if(as<bs)printf("B wins.");

    else printf("It's a tie.");

    return 0;
}
