#include<stdio.h>
struct die{
	int U;
	int F;
	int R;
};
void doit(int *dicemove,struct die *arr){
	
	for(i=0;i<4;i++){
	//printf("%d,%d\n",*(dicemove+i),*(point+i));
		
	}
}
int main(){
	int n,i;
	struct die arr[4];
	
	int dicemove[4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",dicemove,dicemove+1,dicemove+2,dicemove+3);
		doit(dicemove,arr);
		
	}
	return 0;
}
