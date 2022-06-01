#include<stdio.h>
#include<string.h>
#include<ctype.h>
void swap(char *a,char *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int main(){
	char *cursor;
	char a[100];
	char b[100];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	gets(a);
	gets(b);
	cursor=a;
	int i;
	int L;
	for(i=0;i<strlen(b);i++){
		L=strlen(a);
		if(b[i]=='0') cursor = a;
		else if(b[i]=='$') cursor = a+L;
		else if(b[i]=='x') {
			char *tmp;
			tmp=cursor;
			while(tmp!=a+L+1){
				swap(tmp,tmp+1);
				tmp++;
			}
			
		}
		else if(b[i]=='s'){
			if(cursor<a+L-1)swap(cursor,cursor+1);
		}
		else if(b[i]=='i'){
			char *tmp;
			tmp=a+L-1;
			while(tmp!=cursor-1){
				swap(tmp,tmp+1);
				tmp--;
			}
			i++;
			*cursor=b[i];
			cursor++;
			*(a+L+1)=0;
		}
		else if(b[i]=='u'){
			if(isalpha(*cursor)) *cursor=toupper(*cursor);
			cursor++;
		}
		else if(b[i]=='+') cursor++;
		else if(b[i]=='-') cursor--;
		// printf("%s %c\n",a,b[i]);
	}
	printf("%s\n",a);

	// int q;
	// for(q=0;q<50;q++)printf("%d ",a[q]);
	return 0;
}