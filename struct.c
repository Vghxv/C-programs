#include<stdio.h>
typedef struct lesson lesson;
struct lesson{
    char *name;
    int h;
    int arr[3];
};

int main(){
    int i;
    int j;

    char namet[5];
    int ht;
    int arrt[3]={};

    for(i=0;i<1;i++){
        scanf("%s",namet);
        scanf("%d*c",&ht);
        for(j=0;j<ht;j++){
            scanf("%d*c",&arrt[j]);
        }
    }

    lesson L1={
        .name = namet,
        .h = ht,
        .arr = {arrt[0],arrt[1],arrt[2]}
    };

    //printf("%s\n%d\n%d %d %d",namet,ht,arrt[0],arrt[1],arrt[2]);
    printf("%s\n",namet);
    printf("%s\n%d\n%d %d %d",L1.name,L1.h,L1.arr[0],L1.arr[1],L1.arr[2]);
    return 0;
}
