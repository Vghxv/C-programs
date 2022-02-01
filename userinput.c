#include<stdio.h>
int main(){
    int age;
    char fuck;
    char name[25];
    char nickname[10];

    printf("Enter your name : ");
    fgets(name,25,stdin);
    printf("name : %s",name);

    printf("Enter your age : ");
    scanf("%d",&age);
    printf("age : %d\n",age);

    scanf("%c",&fuck); //trash

    printf("Enter your nickname : ");
    fgets(nickname,10,stdin);
    printf("nickname : %s",nickname);


    return 0;
}
