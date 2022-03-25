#include<stdio.h>
int main(){
    int a,i,j,X=0,Y=0;
    char ans[4]={'0','0','0','0'};
    char guess[4]={'0','0','0','0'};
    for(i=0;i<4;i++)scanf("%c",ans+i);
    getchar();
    //for(i=0;i<4;i++)printf("%c",*(arr+i));
    for(a=0;a<6;a++){
        X=0;Y=0;
        for(i=0;i<4;i++)scanf("%c",guess+i);
        getchar();
        for(i=0;i<4;i++){
            if(*(ans+i)==*(guess+i))X++;
            else{
                for(j=0;j<4;j++){
                    if(*(ans+j)==*(guess+i))Y++;
                }
            }
        }
        if(X==4){
            printf("win");
            break;
        }
        else{
            printf("%dA%dB\n",X,Y);
        }
    }
    return 0;
}
