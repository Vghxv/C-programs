#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char values[][20] = { "This", "is", "a", "book", "That","is","a","cook"};

int cmpfunc (const void * a, const void * b){ 
	return strncmp( (char*)a , (char*)b,20 ); 

}


int main(){
	int n;

	printf("Before sorting the list is: \n");
	for( n = 0 ; n < 8; n++ ) {
		printf("%s ", values[n]);
	}

	qsort(values, 8, sizeof(char[20]), cmpfunc);

	printf("\nAfter sorting the list is: \n");
	for( n = 0 ; n < 8; n++ ) {
		printf("%s ", values[n]);
	}
	return 0;
}