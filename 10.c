#include<stdio.h>
#include<math.h>
void d2bprint(int n){
    int res[4];
    int i;
    for(i = 0;i < 4;i++){
        res[4-i-1]=n&1;
        n>>=1;
    }
    for(i = 0;i < 4;++i){
        printf("%d",*(res+i));
    }
    printf("\n");
}
int b2d(char *input){
    int i;
    int decimal=0;
    for(i = 0;i < 8;i++){
        if(*(input+7-i)-'0'==1)decimal+=pow(2,i);
    }
    return decimal;
}
int C(int n){
    int count=0;
    while(n>1){
        if(n%2==1)n+=1;
        n>>=1;
        count++;
    }
    return count;
}
int main(){
    int resn, i, *res, decimal;
    int jg;
    char input[9];
    fgets(input,9,stdin);
    scanf("%d%*c",&jg);

    decimal=b2d(input);
    //printf("%d",decimal);
    resn=C(decimal);
    //puts(input);
    //d2bprint(resn);

    return 0;
}
