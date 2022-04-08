#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define whywouldIscanfstrandmemsetstr re
void whywouldIscanfstrandmemsetstr(char *ans,char *str,int *stri,int n,int shift,int str_l,int nowx,int nowy){
	if(*stri==str_l){
		return;
	}
	if(str[*stri]==50){
		(*stri)+=1;
		re(ans,str,stri,n,shift/2,str_l,nowx,nowy);
		(*stri)+=1;
		re(ans,str,stri,n,shift/2,str_l,nowx,nowy+shift/2);
		(*stri)+=1;
		re(ans,str,stri,n,shift/2,str_l,nowx+shift/2,nowy);
		(*stri)+=1;
		re(ans,str,stri,n,shift/2,str_l,nowx+shift/2,nowy+shift/2);
	}
	else if(str[*stri]==49){
		int i,j;
		for(i=nowx;i<shift+nowx;i++){
			for(j=nowy;j<shift+nowy;j++){
				*(ans+n*i+j) = '1';
			}
		}
	}
}
int main(){
	char *ans;
	char str[200];
	int n,str_l,stri=0,nowx=0,nowy=0;
	scanf("%s",str);
	scanf("%d%*c",&n);
	str_l = strlen(str);
	ans = malloc(n*n*sizeof(char));
	memset(ans,'0',n*n*sizeof(char));
	whywouldIscanfstrandmemsetstr(ans,str,&stri,n,n,str_l,nowx,nowy);
	int i;
	int jg=1;
	for(i=0;i<n*n;i++){
		if(ans[i]==49){
			jg=0;
			printf("%d,%d\n",i/n,i%n);
		}
	}
	if(jg)printf("all white");
	free(ans);
	return 0;
	
}