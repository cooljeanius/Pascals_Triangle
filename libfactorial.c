/*
 *  libfactorial.c
 *  Pascals_Triangle
 *
 *  Created by Eric Gallager on 6/30/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include "libfactorial.h"

/*
 * Computes n!
 * n must be greater than or equal to zero -- premature exit on negative data
 */
int factorial(int n); // prototype
int
factorial(int n) {
	int i = 0; /* local variables */
	int product = 1;
	if (n < 0) {
		printf("\n***Function factorial reports ");
		printf("ERROR:	%d! is undefined***\n", n);
		exit(1);
	} else {
		/* Compute the product n x (n-1) x (n-2) x ... x 2 x 1 */
		for (i = n; i > 1; --i) {
			product = product * i;
		}
		/* Return function result */
		return (product);
	}
}

// newline \n

