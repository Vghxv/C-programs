#include<stdio.h>
int main(){
    char name[20], tel[50], field[20], areaCode[20], code[20];
    int age;
    char a[31]="name:john age:40 tel:082-313530";
    sscanf("name:john age:40 tel:082-313530", "%[^:]", name);
    printf("%s\n", name);
    return 0;
}
