#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE* fp;
	char c;
	fp = fopen("heart.txt","r");
	while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
    }
    fclose(fp);
	return 0;
}