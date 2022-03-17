#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    int *num = (int *)malloc(sizeof(int)*10);
    int i;
    for(i=0; i<10; i++)*(num+i) = i;
    for(i=0; i<10; i++)printf("%d,",*(num+i));


    p = num;

    p++; // p 值會變，指向下一個 1

    printf("%d\n",p);

    printf("%d\n", (*p)++); // p 值不會變，1變2

    for(i=0; i<10; i++)printf("%d,",*(num+i));
    printf("%d\n",p);

    printf("%d\n", ++(*p)); // p 值不會變，2變3

    for(i=0; i<10; i++)printf("%d,",*(num+i));
    printf("%d\n",p);

    printf("%d\n", *(p++)); // p 值會變，指向下一個，再取值

    for(i=0; i<10; i++)printf("%d,",*(num+i));
    printf("%d\n",p);

    printf("%d\n", *p++); //要看 * 或 ++哪一個運算子優先

    for(i=0; i<10; i++)printf("%d,",*(num+i));
    printf("%d\n",p);
    free(num);
    return 0;
}
