/*
maman11_q1 - count_odd_bits.c
* Description:
The Program gets a decimal number.
It will print the number of bits equal to 1 in odd indexes.

* Assumptions:
Input validation was not required in the task. therefore I presume the user will enter a valid number.
*/

#include <stdio.h>

/*This function returns the number of bits equal to 1 in odd indexes*/
int count_odd_bits(unsigned long decimal_input)
{
	int count=0;
	decimal_input>>=1; /*Skip the 0 index bit*/
	while(decimal_input) /*While there are still bits to check*/
	{
		if((decimal_input & 1) == 1) /*isolate the rightmost bit and check if it's equal to 1*/
		{
			count++;
		}
		decimal_input>>=2; /*get to the next odd index bit*/
	}
	return count;
	}

int main()
{
	unsigned long decimal_input;
	scanf("%lu", &decimal_input);
	printf("%d\n", count_odd_bits(decimal_input));
	return 0;
}
