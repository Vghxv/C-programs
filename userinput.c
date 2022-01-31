#include<stdio.h>
int main(){
    int age;
    char fuck[5];
    char id[15];
    char name[25];
    char nickname[10];
    printf("Enter your age\n");
    scanf("%d",&age);
    printf("age : %d\n",age);

    fgets(fuck,5,stdin);

    printf("Enter your name\n");
    fgets(name,25,stdin);
    name[strlen(name)-1]='\0';
    printf("name : %s\n",name);

    printf("Enter your ID\n");
    fgets(id,15,stdin);
    printf("ID : %s\n",id);
    id[strlen(id)-1]='\0';

    printf("Enter your niclname\n");
    fgets(nickname,10,stdin);
    printf("nickname : %s\n",nickname);


    return 0;
}
