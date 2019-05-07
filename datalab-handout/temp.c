#include<stdio.h>

int main(){
    int x = 0x80000000;
    x<<=31;
    x>>=31;
    int y = 0x80000000&x;
    int z = 0x7fffffff&x;
    printf("%d\n",x);
    return 0;
}