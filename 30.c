#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ShapeText(TYPE);\
	double (*perimeter)(struct TYPE*);\
	double (*area)(struct TYPE*)
typedef struct shape_s {
	ShapeText(shape_s);
} shape_t;
typedef struct circle_s {
	ShapeText(circle_s);
	double radius;
} circle_t;
typedef struct rectangle_s {
	ShapeText(rectangle_s);
	double length;
	double width;
} rectangle_t;
typedef struct square_s {
	ShapeText(square_s);
	double edge;
} square_t;
typedef struct triangle_s {
	ShapeText(triangle_s);
	double edge1;
	double edge2;
	double edge3;
} triangle_t;
double Tp(triangle_t *a){return a->edge1+a->edge2+a->edge3;}
double Sp(square_t *a){return a->edge * 4.0L;}
double Rp(rectangle_t *a){return (a->length + a->width)*2.0L;}
double Cp(circle_t *a){return 2.0L * a->radius * 3.14L;}
double Ta(triangle_t *a){
	double s =(a->edge1 + a->edge2 + a->edge3)/2.0L;
	double x = s*(s - a->edge1)*(s - a->edge2)*(s - a->edge3);
	return sqrt(x);
}
double Sa(square_t *a){return a->edge * a->edge;}
double Ra(rectangle_t *a){return a->length * a->width;}
double Ca(circle_t *a){return a->radius * a->radius *3.14L;}
int main(){
	int n,i;
	char cc;
	double perimeter=0;
	double area=0;
	shape_t *o;
	scanf("%d%*c",&n);
	for(i=0;i<n;i++){
		scanf("%c",&cc);
		if(cc=='T'){
			triangle_t a;
			a.perimeter=Tp;
			a.area=Ta;
			scanf("%lf%lf%lf%*c",&a.edge1,&a.edge2,&a.edge3);
			o=(shape_t*)&a;
		}
		else if (cc=='S'){
			square_t a;
			a.perimeter=Sp;
			a.area=Sa;
			scanf("%lf%*c",&a.edge);
			o=(shape_t*)&a;
		}
		else if (cc=='R'){
			rectangle_t a;
			a.perimeter=Rp;
			a.area=Ra;
			scanf("%lf%lf%*c",&a.length,&a.width);
			o = (shape_t*)&a;
		}
		else if (cc=='C'){
			circle_t a;
			a.perimeter=Cp;
			a.area=Ca;
			scanf("%lf%*c",&a.radius);
			o=(shape_t*)&a;
		}
		double d1=o->perimeter(o);
		double d2=o->area(o);
		perimeter+=d1;
		area+=d2;
		printf("%.2f %.2f\n",(double)((int)(d1*100+0.5L))/100,(double)((int)(d2*100+0.5L))/100);
	}
	printf("%.2f %.2f\n",(double)((int)(perimeter*100+0.5L))/100,(double)((int)(area*100+0.5L))/100);
	return 0;
}