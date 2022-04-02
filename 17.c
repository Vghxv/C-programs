#include<stdio.h>
#include<string.h>
#include<math.h>
#define BSIZE 30
int is_valid(char *bin){
	int i;
	for(i=0;i<BSIZE;i++){
		if(bin[i]-'0'>1)return 0;
	}
	return 1;
}

int main(){
	int i,j,k;
	int blen=0;
	int divisor=0;
	int dnum=0;
	char bin[BSIZE],ans[BSIZE];
	memset(bin,0,sizeof(char)*BSIZE);
	memset(ans,0,sizeof(char)*BSIZE);
	scanf("%s",bin);
	if(is_valid(bin)){
		for(i=1;i<BSIZE;i++){
			if(bin[i]!=0){
				break;
			}
			else{
				if(i==BSIZE-1){
					printf("%c",bin[0]);
					return 0;
				}
			}
		}
		blen=strlen(bin);
		for(i=0;i<blen;i++){
			dnum+=(bin[blen-i-1]-'0')*pow(2,i);
		}
		i=0;
		//printf("%d",dnum);
		while(pow(7,i)<dnum)i++;
		i--;
		for(j=0;j<BSIZE&&i>=0;j++){
			divisor = pow(7,i);
			ans[j] = dnum/divisor+'0';
			dnum%=divisor;
			i--;
		}
		for(k=0;k<j;k++){
			printf("%c",ans[k]);
		}
		
	}
	else{
		printf("ERROR");
	}
	
	return 0;
}