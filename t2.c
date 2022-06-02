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
	
	// while(p!=NULL&&p->score!=score)p=p->next;
	// strcpy(name,p->name);
	// return name;
// int main{
	// nodep_t p=NULL;
	// insertFromFront(&p,5);
	// insertFromFront(&p,3);
	// insertFromBack(&p,8);
	// insertFromBack(&p,7);
	// printList(p);
	// return 0;
// }