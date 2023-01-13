#include<stdio.h>
int gcf(int a,int b){
    return (b==0)?a:gcf(b,a%b);
}
struct frac{
    int numerator;
    int denominator;
    int integer;
    int nega;
};
void adjust(struct frac* f){
    int gcfn;
    if((f->denominator)<0){
        (f->denominator)*=-1;
        (f->nega)*=-1;
    }
    if((f->numerator)<0){
        (f->numerator)*=-1;
        (f->nega)*=-1;
    }
    gcfn=gcf(f->numerator,f->denominator);
    (f->numerator)/=gcfn;
    (f->denominator)/=gcfn;
    if(f->numerator >= f->denominator){
        (f->integer) = (f->numerator)/(f->denominator);
        (f->numerator) = (f->numerator)%(f->denominator);
    }
}
struct frac caculate_m(struct frac* f1,struct frac* f2) {
    struct frac n;
    (n.numerator) = (f1->denominator) - (f2->denominator);
    (n.denominator) = (f1->numerator) - (f2->numerator);
    n.integer = 0;
    n.nega = 1;
    adjust(&n);
    return n;
}
struct frac caculate_b(struct frac* f1,struct frac* f2){
    struct frac n;
    (n.numerator) = (f2->numerator)*(f1->denominator)-(f1->numerator)*(f2->denominator);
    (n.denominator) = (f2->numerator) - (f1->numerator);
    n.integer = 0;
    n.nega = 1;
    adjust(&n);
    return n;
}
struct frac inputfrac(){
    int x,y;
    struct frac t;
    scanf("%d%*c%d%*c",&x,&y);
    t.numerator = x;
    t.denominator = y;
    t.integer = 0;
    t.nega = 1;
    return t;
}
int main(){
    int m0 = 0;
    struct frac f1 = inputfrac();
    struct frac f2 = inputfrac();
    struct frac m = caculate_m(&f1,&f2);
    struct frac b = caculate_b(&f1,&f2);
    printf("y=");
    if(m.numerator!=0||m.integer!=0){
        m0=1;
        if(m.nega==-1)printf("-");
        if(m.integer==0){
            if(m.denominator!=1)printf("%d/%d",m.numerator,m.denominator);
        }
        else{
            if(m.denominator==1){
                if(m.integer!=1)printf("%d",m.integer);
            }
            else printf("%d(%d/%d)",m.integer,m.numerator,m.denominator);
        }
        printf("x");
    }
    if(b.numerator!=0||b.integer!=0){
        if(b.nega==-1)printf("-");
        else printf("+");
        if(b.integer==0){
            if(b.denominator!=1)printf("%d/%d",b.numerator,b.denominator);
            else printf("1");
        }
        else{
            if(b.denominator==1)printf("%d",b.integer);
            else printf("%d(%d/%d)",b.integer,b.numerator,b.denominator);
        }
    }
    else{
        if(m0==0)printf("0");
    }
    return 0;
}
