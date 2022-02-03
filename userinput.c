#include<stdio.h>
#include<string.h>
int main(){
    int age;
    //char fuck;
    char name[25];
    char nickname[10];

    printf("Enter your name : ");
    fgets(name,25,stdin);
    name[strlen(name)-1]='\0';

    printf("Enter your age : ");
    scanf("%d",&age);

    //scanf("%c",&fuck); //trash
    getchar();
    
    printf("Enter your nickname : ");
    fgets(nickname,10,stdin);
    nickname[strlen(nickname)-1]='\0';
    

    printf("name : %s, ok\n",name);
    printf("age : %d, ok\n",age);
    printf("nickname : %s, ok\n",nickname);
    printf("hello");


    return 0;
}
