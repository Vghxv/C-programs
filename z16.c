#include<stdio.h>
#include<stdlib.h>
void swap(char *a,char *b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}
void fliplr(char **input,int width,int height){
	int i,j;
	for(i=0;i<height/2;i++){
		for(j=0;j<width/2;j++){
			swap(&input[i][j],&input[height-i-1][j]);
		}
	}
}
void flipud(char **input,int width,int height){
	int i,j;
	for(i=0;i<height/2;i++){
		for(j=0;j<width/2;j++){
			swap(&input[i][j],&input[i][width-j-1]);
		}
	}
	
}
void process(char name[50],int width,int height,char ins[3]){
	char *input[width];
	int i,j;
	input=(char[][width])malloc(sizeof(char)*height*width);
	for(i=0;i<height;i++){
		scanf("%s",input[i]);
	}
	int k;
	for(k=0;k<3;k++){
		if(ins[k]=='R')fliplr(input,width,height);
		else if(ins[k]=='I') flipud(input,width,height);
	}
}

int main(){
	int width=0,height=0;
	char name[50],ins[3];
	scanf("%s%d%d%s",name,&width,&height,ins);
	process(name,width,height,ins);
	return 0;
}