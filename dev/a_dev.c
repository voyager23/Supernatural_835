/*
 * a_dev.c
 * 
 * Copyright 2023 mike <mike@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//~ #include <numeric>
//~ #include <gmp.h>
#include <gmpxx.h>

int main(int argc, char **argv)
{
	//~ (void) std::gcd(56,98); // C version
	mpz_t Tn,T2,T1;
    mpz_inits(Tn,T2,T1,NULL);
    
    mpz_t e,s1,s2,s3,p,S;	// 3 sides, perimeter and cumulative sum of perimeter
    mpz_inits(e,s1,s2,s3,p,S,NULL);	// e is element of the side calculation
    
    mpz_set_ui(T1, 1U);
    mpz_set_ui(T2, 6U);
    
    unsigned long index = 2;  
    while (index < 10)
    {
		mpz_mul_ui(Tn,T2,6U);	// Tn = 6*T2
		mpz_sub(Tn,Tn,T1);	// Tn = TN - T1
		mpz_set(T1,T2);
		mpz_set(T2,Tn);
		index += 1;
		gmp_printf("T[%u]: %Zd		",index,Tn);
		// Calc 3 sides of AIRA triangle
		mpz_set_ui(e, 8U);
		mpz_mul(e,e,Tn);
		mpz_mul(e,e,Tn);
		mpz_add_ui(e,e,1U);	// e = 8*Tn*tn - 1
		mpz_sqrt(e,e);		// e = sqrt(e)
		// side 1
		mpz_mul_ui(s1,Tn,4U);
		mpz_sub_ui(s1,s1,1u);
		mpz_add(s1,s1,e);
		mpz_div_ui(s1,s1,2U);
		// side 2
		mpz_mul_ui(s2,Tn,4U);
		mpz_add_ui(s2,s2,1u);
		mpz_add(s2,s2,e);
		mpz_div_ui(s2,s2,2U);
		// side 3
		mpz_mul_ui(s3,Tn,2U);
		mpz_add(s3,s3,e);
		
		gmp_printf("s1: %Zd		s2: %Zd		s3:%Zd\n",s1,s2,s3);
		
	}
	return 0;
}

