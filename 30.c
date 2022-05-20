#include<stdio.h>
#define ShapeText(TYPE) char name[10];\
	double (*perimeter)(struct TYPE*);\
	double (*area)(struct TYPE*);

typedef struct shape_s {
	ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
	ShapeText(circle_s);
	double radius;
} circle_t;

int main(){
	int n,i;
	for(i=0;i<n;i++){
		
	}
	return 0;
}