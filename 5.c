#include<stdio.h>
void say_it(int ar,int a,int b){
    printf("%d and %d conflict on %d", a, b, ar);
}
int main(){
    int flag=1;
    int i;
    int j;
    int lesson1,lesson2,lesson3;
    int hour1,hour2,hour3;
    int ar1[3],ar2[3],ar3[3];
    int h1,h2,h3;
    scanf("%d",&lesson1);
    scanf("%d",&hour1);
    for(j=0;j<hour1;++j)scanf("%d",&ar1[j]);


    scanf("%d",&lesson2);
    scanf("%d",&hour2);
    for(j=0;j<hour2;++j)scanf("%d",&ar2[j]);


    scanf("%d",&lesson3);
    scanf("%d",&hour3);
    for(j=0;j<hour3;++j)scanf("%d",&ar3[j]);


    h1=()? :
    for (i = 0; i <= hour1;i++){
        if(ar1[i]==ar2[i]){
            say_it(ar1[i],lesson1,lesson2);
            flag = 0;
            break;
        }
        if(ar1[i]==ar3[i]){
            say_it(ar1[i],lesson1,lesson3);
            flag = 0;
            break;
        }
    }

        for (i = 0; i <= hour2;i++){
            if(ar1[i]==ar2[i]){
                say_it(ar2[i],lesson1,lesson2);
                flag = 0;
                break;
            }
            if(ar2[i]==ar3[i]){
                say_it(ar2[i],lesson2,lesson3);
                flag = 0;
                break;
            }
        }
    }
    if(flag==1){
        for (i = 0; i <= hour3;i++){
            if(ar1[i]==ar3[i]){
                say_it(ar3[i],lesson1,lesson3);
                flag = 0;
                break;
            }
            if(ar2[i]==ar3[i]){
                say_it(ar3[i],lesson2,lesson3);
                flag = 0;
                break;
            }
        }
    }

    return 0;
}
