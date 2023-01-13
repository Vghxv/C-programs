#include<stdio.h>
#include<math.h>
int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    double D = 0;
    double x1 = 0;
    double x2 = 0;
    scanf("%d%*c", &a);
    scanf("%d%*c", &b);
    scanf("%d%*c", &c);
    D = sqrt(b * b - 4 * a * c);
    x1 = ((-b) + D)/ (2 * a);
    x2 = ((-b) + D )/(2 * a);
    printf("%.1lf\n", x1);
    printf("%.1lf", x2);

    return 0;
}
