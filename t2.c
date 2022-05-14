#include<stdio.h>
#include<string.h>
typedef struct p_t{
	char name[50];
	int age;
};
int main(){
	p_t a;
	p_t b;
	scanf("%s",a.name);
	scanf("%s",b.name);
	scanf("%d%d",&a.age,&b.age);
	printf("%d",(a.age>b.age)?a.age:b.age);
	return 0;
}


