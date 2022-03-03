#include<stdio.h>
struct lesson{
    int classname;
    int arr[5];
};

int main(){

    int i;
    int j;
    int name;
    int h;
    int ar[5];
    for(i=0;i<3;++i){
        scanf("%d",&name);
        scanf("%d",&h);
        for(j=0;j<h;++j)scanf("%d",&ar[j]);
        /*printf("%d\n",name);
        printf("%d\n",h);
        for(j=0;j<h;++j)printf("%d\n",ar[j]);*/
    }

    lesson L1 = {name,ar};
    printf("%d",L1.classname);
    printf("%d",L1.arr[1]);
    return 0;
}
