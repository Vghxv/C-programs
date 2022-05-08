#include<stdio.h>
#include<math.h>
int main(){
	int i;
	for(i=1;i<=200;i++){
		// int t=pow(13,i);
		if((5*i)%53==1)
		printf("%d,%d\n",i,(5*i)%53);
	}
	return 0;
}