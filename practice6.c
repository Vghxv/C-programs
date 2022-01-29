#include<stdio.h>
int fun(int a,int b,int c){
    return 0;
}
int main(void){
    int i=0,j=0;
    char str[20];//定義一個最大長度為19，末尾是'\0'的字元陣列來儲存字串
    printf("請輸入一個字串：");
    fgets(str,7,stdin);//從輸入流stdin即輸入緩衝區中讀取7個字元到字元陣列str中
    printf("%s",str);

    return 0;
}
