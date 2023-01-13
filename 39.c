#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct birth_s{
	int year;
	int month;
	int day;
}birth_t;
typedef struct data_s{
	char name[20];
	int age;
	birth_t birth;
}data_t;
typedef data_t* datap_t;
typedef struct node_s{
	data_t data;
	struct node_s *next;
}node_t;
typedef node_t* nodep_t;
nodep_t newnode(data_t data){
	nodep_t k=(nodep_t)malloc(sizeof(node_t));
	strcpy(k->data.name,data.name);
	k->data.age=data.age;
	k->data.birth=data.birth;
	k->next=NULL;
	return k;
}
data_t init(){
	data_t k;
	memset(k.name,0,sizeof(k.name));
	k.age=0;
	k.birth.year=0;
	k.birth.month=0;
	k.birth.day=0;
	return k;
}
int queuelen(nodep_t head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
void enqueue(nodep_t* head,nodep_t* tail,data_t data){
	nodep_t new=newnode(data);
	if(*tail==NULL){
		*head=new;
		*tail=new;
		return ;
	}
	(*tail)->next=new;
	*tail=new;
}
data_t dequeue(nodep_t* head,nodep_t* tail){
	nodep_t tmp = *head;
	data_t k=init();
	if((*head)==NULL){
		free(tmp);
		return k;
	}
	else{
		strcpy(k.name,tmp->data.name);
		k.age=tmp->data.age;
		k.birth=tmp->data.birth;
		*head=(*head)->next;
		free(tmp);
		if(*head==NULL)*tail=NULL;
		return k;
	}
}
void print_birth(birth_t birth){
	printf("%d_%d_%d\n",birth.year,birth.month,birth.day);
}
void print_data(data_t k){
	printf("%s %d %d_%d_%d\n",k.name,k.age,k.birth.year,k.birth.month,k.birth.day);
}
void print_list(nodep_t head){
	if(head==NULL)puts("The Queue is empty");
	while(head!=NULL){
		print_data(head->data);
		head=head->next;
	}
}
int main(){
	int ins=0;
	nodep_t head=NULL;
	nodep_t tail=NULL;
	while(1){
		scanf("%d",&ins);
		if(ins==1){
			data_t data=init();
			scanf("%s%d%d%d%d",data.name,&(data.age),&(data.birth.year),&(data.birth.month),&(data.birth.day));
			enqueue(&head,&tail,data);
		}
		else if(ins==2){
			int choice;
			scanf("%d",&choice);
			data_t data=dequeue(&head,&tail);
			if(data.age!=0){
				if(choice==1)printf("%s\n",data.name);
				else if(choice==2)printf("%d\n",data.age);
				else if(choice==3)print_birth(data.birth);
			}
			else puts("The Queue is empty");
		}
		else if(ins==3){
			data_t data;
			while(head!=NULL){
				data=dequeue(&head,&tail);
				if(data.age!=0)
					print_data(data);
			}
		}
		else if(ins==4){
			print_list(head);
		}
		else{
			int count=queuelen(head);
			printf("%d",count);
			break;
		}
		// puts("\nnowstack:---------");
		// print_list(head);
		// puts("----------------------\n");
	}
	return 0;
}