#include <stdio.h>
#include <malloc.h>

int main() {
	int i,j,num=3;
	char (*a)[num] = (char(*)[num])malloc(num*num*sizeof(char));
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) 	
			printf("%p ", &a[i][j]); //輸出元素的地址 
		printf("\n");
	}
	free(a);
	return 0;
}