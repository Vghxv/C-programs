#include<stdio.h>
#include<math.h>
double f1(double a,double x){
	return sqrt(fabs(a-pow(x,2)));
}
double f2(double a,double x){
	return (a*pow(x,3) + 7.0L*x)/sqrt(fabs(a+x));
}
double integral(int n,double a,double p, double q,double (*f)(double,double)) {
	int i;
	double area = (fabs(((*f)(a,p)) + fabs((*f)(a,q)))) / 2.0L;
	double gap = (q - p) / n;
	double next = p;
	for (i = 1; i < n; i++) {
		area += fabs((*f)(a,next+=gap));
	}
	return area * gap;
}
int main(){
	
	int jg,err,n;
	double a,p,q;
	double(*f)(double,double);
	while(1){
		scanf("%d",&jg);
		if(jg==0)break;
		scanf("%lf%lf%lf%d",&a,&p,&q,&err);
		n=1;
		err*=-1;
		f=(jg==1)?f1:f2;
		double errn=pow(10,err);
		double parea=0.0L;
		double narea=0.0L;
		while(1){
			narea=integral(n,a,p,q,f);
			if(fabs(narea-parea)<errn)break;
			parea=narea;
			// printf("%.12f n:%d\n",narea,n);
			n=n*2;
		}
		printf("%.12f\n",narea);
	}
	return 0;
}
