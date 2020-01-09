//---------------------------------------------------------------
//
//  4190.308 Computer Architecture (Fall 2019)
//
//  Project #1: 64-bit Integer Arithmetic using 32-bit Operations
//
//  September 9, 2019
//
//  Jin-Soo Kim (jinsoo.kim@snu.ac.kr)
//  Systems Software & Architecture Laboratory
//  Dept. of Computer Science and Engineering
//  Seoul National University
//
//---------------------------------------------------------------

#include <stdio.h>
#include "pa1.h"

int A_is_bigger_than_B(HL64 A, HL64 B);

HL64 Uadd64 (HL64 a, HL64 b)
{
	
	HL64 	x;

	x.lo = a.lo + b.lo;
	u32 carry = 0;
	if (!((x.lo >= a.lo) && (x.lo >= b.lo))){
		carry+=1;
	}

	x.hi = a.hi + b.hi + carry;
	
	return x;
}

// Usub64() implements the subtraction between two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively. In the following example, x.hi and x.lo should
// have the upper and lower 32 bits of (A - B), respectively.

HL64 Usub64 (HL64 a, HL64 b)
{
	HL64 	x;

	u32 carry = 0;
	if (a.lo < b.lo){
		carry+=1;
	}

	x.lo = a.lo - b.lo;
	x.hi = a.hi - b.hi - carry;

	return x;
}

// Usub64() implements the multiplication of two 64-bit unsigned integers.
// Assume that a' and b' are the 64-bit unsigned integer represented by
// a and b, respectively.  In the following example, x.hi and x.lo should
// have the upper and lower 32 bits of (A * B), respectively.

HL64 Umul64 (HL64 a, HL64 b)
{
	HL64 	x;
	unsigned int half = 1<<16;

	HL64 carries;
	HL64 tmp1;
	HL64 tmp2;

	carries.hi = 0;
    carries.lo = (a.lo % half) * (b.lo % half); // lo의 뒷부분(half)들끼리 곱한것!

    u32 lo_a_back_b_front = (a.lo % half) * (b.lo >> 16); // a의 lo 뒷부분과 b의 lo 앞부분끼리 곱하기
    tmp1.hi = lo_a_back_b_front >> 16;
    tmp1.lo = (lo_a_back_b_front % half) << 16;

    u32 lo_a_front_b_back = (b.lo % half) * (a.lo >> 16); // b의 lo 뒷부분과 a의 lo 앞부분끼리 곱하기
    tmp2.hi = lo_a_front_b_back>> 16;
    tmp2.lo = (lo_a_front_b_back % half) << 16;

    carries = Uadd64(carries, Uadd64(tmp1,tmp2));

    x.lo = a.lo * b.lo; // 그 다음으로 hi로 넘어가는애들은 나중에 더해줄것임

    x.hi = a.lo * b.hi + a.hi * b.lo // 넘어가는애들은 생각할 필요 X
			+ (a.lo >> 16) * (b.lo >> 16) 
			+ carries.hi; // a의 lo 앞부분과, b의 lo앞부분끼리 곱하기 더한거! 

	return x;
}


// Udiv64() implements the division of two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively.  Udiv64() should return x, where x.hi and x.lo 
// contain the upper and lower 32 bits of the quotient of (A / B), 
// respectively.



int A_is_bigger_than_B(HL64 A, HL64 B){
	return ((A.hi > B.hi) || ((A.hi == B.hi)&&(A.lo >= B.lo)) )? 1:0;
}


HL64 Udiv64 (HL64 a, HL64 b)
{
	HL64 x;
	if ((b.hi==0) && (b.lo==0)){
		x.hi = 0;
		x.lo = 0;
		return x;
	} 

	HL64 R; R.hi=0; R.lo=0;
	HL64 Q = a;
	HL64 divisor = b;

	for (int i=0; i<64; i++){
		// 1. shift left
		/////////////////////////////////////////////
		R.hi = (R.hi<<1) + (R.lo>>31); // add R.lo's MSB
		R.lo = (R.lo<<1) + (Q.hi>>31);  // add Q.hi's MSB
		Q.hi = (Q.hi<<1) + (Q.lo>>31); // add Q.lo's MSB
		Q.lo = Q.lo<<1;
		////////////////////////////////////////////
		// 2. update Q's LSB
		if (A_is_bigger_than_B(R,divisor)==1){
			Q.lo += 1;
			R = Usub64(R,divisor);
		}
	}

    x = Q;

	return x;
}





