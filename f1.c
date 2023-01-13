#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int i;
	int a,b,c;
	int jg=469484;
	int y;
	while(jg!=0){
		puts("inverse module:1 div:2 mul:3 2537chart:4 sub:5 exit:0");
		scanf("%d",&jg);
		switch(jg){
			case 1:
				scanf("%d%d%*c",&a,&b);
				for(i=1;i<9999;i++){
					int o=a*i;
					printf("%d:%d\n",i,o%b);
					if(o%b==1){puts("============================");break;}
				}
				break;
			case 2:
				scanf("%d%d",&a,&b);
				printf("ans:%d\nmod:%d\n",a/b,a%b);
				
				break;
			case 3:
				scanf("%d%d",&a,&b);
				printf("ans:%d\n",a*b);
				break;
			case 4:
				for(i=1;i<10;i++)printf("%d\t%d\n",i,2537*i);
				break;
			case 5:
				scanf("%d%d",&a,&b);
				printf("ans:%d\n",a-b);
				break;
		}
	}
	return 0;
}