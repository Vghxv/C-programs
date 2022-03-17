#include<stdio.h>
int gcf(int n1,int n2){
    return n2 == 0 ? n1 : gcf(n2,n1%n2);
}
int main(){
    int fu1, fd1, fu2, fd2,resgcf;
    int res=0, resu=0, resd=0;
    char op;
    char yn;
    int nega = 0;
    int tmp;
    scanf("%d/%d", &fu1, &fd1);
    scanf("%d/%d", &fu2, &fd2);
    scanf(" %c", &op);
    //scanf(" %c%*c", &yn);
    if(op == '/'){
        tmp = fu2; fu2 = fd2; fd2 = tmp;
    }
    if(fd1 == 0 || fd2 == 0)printf("ERROR");
    else{
        switch(op){
            case '*':
                resu = fu1 * fu2;
                resd = fd1 * fd2;
                break;
            case '/':
                resu = fu1 * fd2;
                resd = fd1 * fu2;
                break;
            case '+':
                resu = fu1 * fd2 + fu2 * fd1;
                resd = fd1 * fd2;
                break;
            case '-':
                resu = fu1 * fd2 - fu2 * fd1;
                resd = fd1 *fd2;
                break;
        }

        resgcf = gcf(resu,resd);
        resu /= resgcf; resd /= resgcf;

        //printf("%d %d\n", resu, resd);
        if(resu == 0){
            printf("0");
        }
        else{
            if(resu<0){
                resu*=-1;
                nega=1;
            }
            if(resd < 0){
                resd*=-1;
                nega=1;
            }
            if(resu>resd){
                res = resu/resd;
                resu%=resd;
            }
        if(nega)printf("-");
        if(res == 0)printf("%d/%d",resu,resd);
        else printf("%d(%d/%d)",res,resu,resd);
        }
    }
    return 0;
}
