#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int i,j,k,l;
	scanf("%d %*c %d %*c",&i,&j);
	scanf("%d %*c %d %*c",&k,&l);
	printf("%d %d %d %d",i,j,k,l)
	return 0;
}


// x[0]=x[0]+1
// x is $s1



// try:
// ll $t0,($s1)
// addi $t0,$t0,1
// sc $t0,($s1)
// beq $t0,$0,try