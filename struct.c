#include<stdio.h>
struct Node{
    int value;
    int *next;
};
int main(){
    struct Node n1;
    struct Node n2;
    int tmp=0;
    scanf("%d", tmp);
    n1.value=tmp;
    getchar();

    scanf("%d",tmp);
    n2.value=tmp;
    n1.next=&n2.value;
    getchar();

    return 0;
}
