#include<stdio.h>

int main(){
    int x=0xffffffff;
//     int temp = x^(x>>31); //get positive x
//   int isZero = !temp;
//   int notZeroMask = (!!x<<31)>>31; //0->0,!0->0xffffffff
//   int bit_16,bit_8,bit_4,bit_2,bit_1;
//   bit_16 = (!!(temp>>16))<<4;
//   temp >>= bit_16;
//   bit_8 = (!!(temp>>8))<<3;
//   temp >>= bit_8;
//   bit_4 = (!!(temp>>4))<<2;
//   temp>>=bit_4;
//   bit_2 = (!!(temp>>2))<<1;
//   temp >>=bit_2;
//   bit_1 = !!(temp>>1);
//   int sum = bit_16+bit_8+bit_4+bit_2+bit_1+2;
//   int result =isZero|(sum&notZeroMask); 
//   return isZero|(sum&notZeroMask);
    int temp=x^(x>>31);//get positive of x;
    int isZero=!temp;
    //notZeroMask is 0xffffffff
    int notZeroMask=(!(!temp)<<31)>>31;
    int bit_16,bit_8,bit_4,bit_2,bit_1;
    bit_16=!(!(temp>>16))<<4;
    //see if the high 16bits have value,if have,then we need at least 16 bits
    //if the highest 16 bits have value,then rightshift 16 to see the exact place of  
    //if not means they are all zero,right shift nothing and we should only consider the low 16 bits
    temp=temp>>bit_16;
    bit_8=!(!(temp>>8))<<3;
    temp=temp>>bit_8;
    bit_4=!(!(temp>>4))<<2;
    temp=temp>>bit_4;
    bit_2=!(!(temp>>2))<<1;
    temp=temp>>bit_2;
    bit_1=!(!(temp>>1));
    temp=bit_16+bit_8+bit_4+bit_2+bit_1+2;//at least we need one bit for 1 to tmax,
    //and we need another bit for sign
    int result = isZero|(temp&notZeroMask);
    return result;
}