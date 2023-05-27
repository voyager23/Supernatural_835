/*
 * abtest.c
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


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned a,b,lhs,rhs;
	for(unsigned delta = 1; delta < 6; ++delta)
	{
		printf("delta: %u\n",delta);
		for(a = 1; a < 51; ++a)
		{
			for(b = a+1; b < 52; b ++)
			{
				lhs = (2*a*b - b*b);
				rhs = (a*a - delta*delta);
				//printf("lhs: %u		rhs: %u\n",lhs,rhs);
				if (lhs == rhs)
				{
					printf("\nType 1 solution a:%u b:%u\n",a,b);
				}
				lhs *= -1;
				rhs *= -1;
				if (lhs == rhs)
				{
					printf("Type 2 solution a:%u b:%u\n",a,b);
				}
			}
		}
	}
	return 0;
}

