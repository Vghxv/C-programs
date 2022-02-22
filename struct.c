#include<stdio.h>
struct Node{
    int val;
    int *next;
};
int main(){
    struct Node n1;
    struct Node n2;
    int tmp=0;
    scanf("%d", tmp);
    n1.val=tmp;
    //getchar();
    printf("-------");
    scanf("%d",tmp);
    n2.val=tmp;
    n1.next=&n2.val;
    //getchar();

    printf("values : %d%d",n1.val,n2.val);
    printf("pointer : %d",n1.next);
    printf("%d",&n2.val);
    return 0;
}
