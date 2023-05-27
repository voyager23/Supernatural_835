/*
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
 *	b_aira.cxx 
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gmpxx.h>

void find_ab(mpz_class* a,mpz_class* b,mpz_class x,mpz_class y,mpz_class z)
{
	*b = sqrt((y + z) / 2);
	
	*a = x / (*b * 2);
	
	gmp_printf("a: %Zd  b: %Zd\n",a,b);
}


int main()
{
	mpz_class r,a,b,x,y,z,p,S;
	mpz_class Pell[3];
	
	Pell[0] = 5U;
	Pell[1] = 2U;
	Pell[2] = 1U;

	for(a = 1; a < 100; a++)
	{
		b = a+1;
		if (gcd(a,b) == 1U)
		{
			x = 2*a*b;
			y = b*b - a*a;
			z = a*a + b*b;
			if((abs(x-y) == 1)||(abs(x-z) == 1)||(abs(y-z) == 1))
			{
				gmp_printf("x:%Zd, y:%Zd, z:%Zd,	a:%Zd, b:%Zd\n",x,y,z,a,b);
				S = S + (x+y+z);
				S = (S % 10000U);
			}
			// check for outlier
			if(a == Pell[0])
			{
				// calc next Pell number
				Pell[2] = Pell[1];
				Pell[1] = Pell[0];
				Pell[0] = 2 * Pell[1] + Pell[2];
				// set b = Pell
				b = Pell[0];
				// repeat test
				x = 2*a*b;
				y = b*b - a*a;
				z = a*a + b*b;
				if((abs(x-y) == 1)||(abs(x-z) == 1)||(abs(y-z) == 1))
				{
					gmp_printf("		x:%Zd, y:%Zd, z:%Zd,	a:%Zd, b:%Zd\n",x,y,z,a,b);
					S = S + (x+y+z);
					S = (S % 10000U);
				}
			}
		}
	}
	gmp_printf("Perimeter Sum = %Zd\n",S);
}



