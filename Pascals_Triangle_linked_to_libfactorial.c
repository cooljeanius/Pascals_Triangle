/*
 *  Pascals_Triangle_linked_to_libfactorial.c
 *  Pascals_Triangle
 *
 *  Created by Eric Gallager on 7/1/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 *	This file should build into the same thing as main_Pascals_Triangle.c, except the factorial function should come from libfactorial instead of being in this piece of code itself.
 *
 */

#include "libfactorial.h"

/*
 * Combination function: computes the number of combinations of n items taken r at a time
 */
int combination(int n, int r); // Prototype
int
combination(int n, int r)
{
	int c = factorial(n) / (factorial(r) * factorial(n-r));
	return (c);
	/*	printf("\n c is %d \n", c); // statement for debugging */
}

/*
 * Main function: does what the program was overall designed for
 */
int main (int row_number) {
	int i = 1;
	int answer = 1;
    printf("\n Enter the row of Pascal's Triangle you would like to find \n (the first row is row 0) \n (also be nice to your computer and keep your row number reasonably low) \n > "); // prompt // ("reasonably low" currently means below 13 to get correct results, and below 34 to *not* get a floating point exception.)
	scanf("%d", &row_number); // get input
	/* printf("\n Row number is %d. \n", row_number); // statement for debugging */
	printf("\n The contents of row %d are: \n", row_number);
	/* int fact = factorial(row_number);
	 printf("\n Factorial of the row number is %d ", fact); // testing factorial function */
	/* 
	 * WARNING!
	 * In some circumstionces, the following will make the program fail to compile unless you pass -fnested-functions to the compiler, so be sure to enable that flag
	 */
	if (row_number == 0) { // the first few rows are odd, hard-coding them just in case
		printf("\n 1 \n");
	} else if (row_number == 1) {
		printf("\n 1 1 \n");
	} else if (row_number > 1) { // here's the actual programmatic part
		printf("\n 1 "); // this needs to be hard-coded
		for (i = 1; i <= row_number; i++) { // incrementing is done with the normal i++, *not* the combination function (duh)
			answer = combination(row_number, i); // the combination part goes here, not in the incrementing step for the for-loop
			printf(" %d ", answer);
		}
		printf(" \n ");
	} else 
		printf("\n This is not supposed to happen. \n"); // just in case
    return 0;
}

// newline \n

