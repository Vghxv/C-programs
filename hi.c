#include<stdio.h>
void md(int *up1,int *down1,int *up2, int *down2 ){
    *up1*=*up2;
    *down1*=*down2;
}
int max_gonin(int n1,int n2){
    return n2 == 0 ? n1 : max_gonin(n2,n1%n2);
}
int main(){
    int a,b,c,d,maxab,maxcd;
    int res=0,resu=0,resd=0;
    char jg;
    char yn;
    int max=0;
    int tmp=0;
    scanf("%d/%d",&a,&b);
    scanf("%d/%d",&c,&d);
    scanf(" %c",&jg);
    //scanf("%c%*c",&yn);
    if(b==0||d==0){
        printf("ERROR");
    }
    else{
        switch(jg){
            case '*':
                md(&a,&b,&c,&d);
                resu=a;
                resd=b;
                break;
            case '/':
                md(&a,&b,&d,&c);
                resu=a;
                resd=b;
                break;
            case '+':
                resu=a*d+c*b;
                resd=b*d;
                break;
            case '-':
                resu=a*d-c*b;
                resd=b*d;
                break;
        }
    maxab=max_gonin(a,b);
    maxcd=max_gonin(c,d);
    a/=maxab;
    b/=maxab;
    c/=maxcd;
    d/=maxcd;
    printf("%d %d\n",a,b);
    printf("%d %d",c,d);
    }

//                max=max_gonin(b,d);
  //              b/=max;
    //            d/=max;
      //          a*=d;
        //        c*=b;
          //      tmp=b*d;
            //    b=d=tmp;
              //  b*=max;
                //d*=max;
    return 0;
}
