#include<stdio.h>
#include<math.h>
int min(int a, int b,int c){
    int d;
    d = (a<b) ? a : b;
    d = (c<d) ? c : d;
    return d;
}
int main(){
    int kindmm[3] = {183, 383, 983};
    float invo[3] = {0.08, 0.07, 0.06};
    float exvo[3] = {0.1393, 0.1304, 0.1087};
    float cityvo[3] = {0.1349, 0.1217, 0.1018};
    float inte[3] = {1.1287, 1.1127, 0.9572};
    float exte[3] = {1.4803, 1.2458, 1.1243};

    int input[5]={};
    float output[3]={};
    int op[3]={};
    int i;
    int j;
    int o;
    for(i=0;i<5;++i){
        scanf("%d",&input[i]);
    }
    for(i=0;i<3;++i){
        output[i] = input[0]*invo[i]+input[1]*exvo[i]+input[2]*cityvo[i]+input[3]*inte[i]+input[4]*exte[i];
        op[i] = (lround(output[i])>kindmm[i]) ? lround(output[i]) : kindmm[i];
    }
    o = min(op[0],op[1],op[2]);
    for(i=0;i<3;++i){
        if(o == op[i]){
            printf("%d",kindmm[i]);
            break;
        }
    }
    return 0;
}
