#include<stdio.h>
#include<string.h>
int main(){
	char a[50];
	char b[50];
	char *toka;
	char *tokv;
	toka=strtok(a," ");
	while(toka!=NULL){
		tokb=strtok(b," ");
		while(tokb!=NULL){
			//sth
			tokb=strtok(NULL," ");
		}
		toka=strtok(NULL," ");
	}
	return 0;
}


// x[0]=x[0]+1
// x is $s1



// try:
// ll $t0,($s1)
// addi $t0,$t0,1
// sc $t0,($s1)
// beq $t0,$0,try