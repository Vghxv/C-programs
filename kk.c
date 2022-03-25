#include<stdio.h>
int gcf(int a,int b){
    return(b==0)a:gcf(b,a%b);
}
struct frac{
    int numerator;
    int denominator;
    int integer = 0;
    int nega = 1;
};
int is_valid(struct frac* f){
    return (f->denominator==0)0:1;
}
void adjust(struct frac* f){
    int gcfn;
    gcfn=(f->numerator,f->denominator);
    f->numerator/=gcfn;
    f->denominator/=gcfn;
    if(f->denominator<0){
        f->denominator*=-1;
        f->nega*=-1;
    }
    if(f->numerator<0){
        f->numerator*=-1;
        f->nega*=-1;
    }
    if(f->numerator >= f->denominator){
        f->ingeter = (f->numerator)/(f->denominator);
        f->numerator = (f->numerator)%(f->denominator);
    }
}
struct frac caculate_m(struct frac* f1,struct frac* f2) {
    struct frac n;
    n->numerator = f1->denominator - f2->denominator;
    n->denominator = f1->numerator - f2->numerator;
    adjust(n);
    return n;
}
struct frac caculate_b(struct frac* f1,struct frac* f2){
    struct frac n;
    n->numerator = (f2->numerator)*(f1->denominator)-(f1->numerator)*(f2->denominator);
    n->denominator = f2->numerator - f1->numerator;
    adjust(n);
    return n;
}
struct frac inputfrac(){
    int x,y;
    struct frac t;
    scanf("%d%*c%d%*c",&x,&y);
    t.numerator = x;
    t.denominator = y;
    return t;
}
int main(){
    struct frac f1 = inputfrac();
    struct frac f2 = inputfrac();
    struct frac m = caculate_m(f1,f2);
    struct frac b = caculate_b(f1,f2);
    printf("y=");
    if(m.nega==-1)printf("-");
    if(m.ingeter0==0){
        printf("%d/%d",m.numerator,m.denominator);
    }
    return 0;

}
