#include <stdio.h>
int main(){
    int i;
    int state=0;
    int outn=0;
    char input='0';
    for(i=0;i<5;++i){
        scanf("%c%*c",&input);
        if(input=='O'){
            outn++;
            if(outn==3)state=0;
        }
        else if(input=='1')state=(state<<1)|(1);
        else if(input=='2')state=(state<<2)|(1<<1);
        else if(input=='3')state=(state<<3)|(1<<2);
        else state=0;
        state=state&7;
    }
    printf("%d\n", state&1);
    printf("%d\n", (state>>1)&1);
    printf("%d", (state>>2)&1);
    return 0;
}
