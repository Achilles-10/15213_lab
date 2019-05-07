#include<stdio.h>

int main(){
    int x=0x80000000,y=0xffffffff;
    int sx = (x>>31) & 1;
    int sy = (y>>31) & 1;
    int sign_diff = sx & !sy;
    int sign_same = !(sx^sy);
    int big = (((x+~y)>>31) & 1);
    return 0;
}