#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int k,ck=0,g=0,cg=0,cch,pch=2,p=0;
	char a[50];
	scanf("%d%*c",&k);
	scanf("%s",a);
	while(1){
		if(k==1){
			cch=isupper(*(a+p));
			if(cch==pch){
				g=(g>cg)?g:cg;
				cg=1;
			}
			else{
				cg++;
			}
			p++;
			pch=cch;
			if(*(a+p)==0)break;
		}
		else{
			cch=isupper(*(a+p))?1:0;
			if(cch==pch){
				ck++;
				if(ck==k){
					cg+=k;
					g=(g>cg)?g:cg;
				}
				else if(ck>k)cg=k;
			}
			else{
				if(ck<k)cg=0;
				ck=1;
			}
			pch=cch;
			p++;
			if(*(a+p)==0)break;
		}
	}
	printf("%d",g);
	return 0;
}