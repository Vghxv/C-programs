#include<stdio.h>
#include<math.h>
double f1(double a,int x){
	return sqrt(a-x*x);
}
double f2(double a,int x){
	return (a*x*x*x + 7.0L*x)/sqrt(a+x);
}
double fA(int n,double a,double p,double q,double(*f)(double,int)){
	int i;
	double gap=(q-p)/n;
	double fres1=fabs((*f)(a,p));
	double fres2=fabs((*f)(a,p+gap));
	double area=0;
	for(i=0;i<n;i++){
		area+=(fres1+fres2)*gap/2.0L;
		fres1=fres2;
		fres2=(*f)(a,p+gap*(i+1));
	}
	return area;
}
int main(){
	int jg,err,n=1;
	double a,p,q;
	double(*f)(double,int);
	scanf("%d%lf%lf%lf%d",&jg,&a,&p,&q,&err);
	err*=-1;
	f=(jg==1)?f1:f2;
	double errn=pow(10,err);
	double parea=0;
	double narea=0;
	int debug=0;
	while(debug<14){
		printf("%d\n",debug);
		narea=fA(n,a,p,q,f);
		if(fabs(narea-parea)<errn)break;
		parea=narea;
		n*=2;
		debug++;
	printf("%.12f",narea);
	}
	return 0;
}