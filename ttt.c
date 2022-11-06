#define ShapeText(TYPE) \
	char name[10];\
	float (*perimeter)(struct TYPE*);
#include<stdio.h>
#include<string.h>

// typedef struct _Shape { // Shape 物件無欄位
	// ShapeText(_Shape)
// } Shape;
// typedef struct _Circle {
	// ShapeText(_Circle);
	// float radius;
// } Circle;
// float ShapeArea(Shape *obj) { return 0; }
// float ShapePerimeter(Shape *obj) { return 0; }
// void ShapeNew(Shape *obj) {
	// strcpy(obj->name,"shape");
	// obj->perimeter = ShapePerimeter;
// }
// float CircleArea(Circle *obj)
	// { return 3.14 * obj->radius * obj->radius; }
// float CirclePerimeter(Circle *obj)
	// { return 2*3.14 * obj->radius; }
// void CircleNew(Circle *obj) {
	// strcpy(obj->name,"circle");
	// obj->perimeter = CirclePerimeter;
// }
void f(int *a,int c){
	*a=c;
}

int main() {
	int c=70;
	int a=100;
	printf("%d",a);
}