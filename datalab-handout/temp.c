#include<stdio.h>

int main(){
    int x = 0x30;
    x>>=3;
    x^=0x06;
    x=!x;
    printf("%d\n",x);
    return 0;
}