/*
 * gcd.c
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
#include <gmpxx.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
	// Everything divides 0
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	// Base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

// Driver code
int main()
{
	mpz_class r,a,b,x,y,z;
	for(a = 1; a < 10; a++)
		for(b = a+1; b < 10; b+=2)
			{
				r = gcd(a,b);
				if(r == 1)
				{
					//~ gmp_printf("%Zd,%Zd,%Zd\n",a,b,r);
					x = 2*a*b;
					y = b*b - a*a;
					z = a*a + b*b;
					gmp_printf("%Zd,%Zd,%Zd\n",x,y,z);
				}
			}

	return 0;
}



