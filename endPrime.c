#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<math.h>
#include<unistd.h>
#include "endPrime.h"

int Primes[MAX_LENGTH] = {1}; // the array to host all prime numbers
int *tail = Primes; // the pointer to indicate the present location(tail)	
int count = 0;

void print_result()
{
	int i = 0;
	int j = 0;

	while (i < count)
	{
		if (i == 0) printf("\n");
		if (j < 7)
		{
			printf("%d", Primes[i]);
			printf("\t", Primes[i]);
			++i;
			++j;		
		}
		else
		{
			printf("\n");
			j = 0;
		}
		
	}
}

void break_handler()
{
	print_result();
	
	exit(0);
}


int main()
{
	signal(SIGINT, break_handler);
	for (int i = 2; i < MAX_LENGTH; i++)
	{
		if(if_prime(i))
		{
			*tail = i;
			++ tail; // store the current prime and move the pointer to next position(0)
			++ count;
		}
	}
	print_result();
	printf("/n");
	return 0;
}

int if_prime(int n)
{
	if (2==n) return 1;
	if (3==n) return 1;
	for (int i = 2; i <= sqrt((double)n); i++)
	{
		if (!(n % i))
		return 0;
		//sleep(1);
	}
	return 1;
}


