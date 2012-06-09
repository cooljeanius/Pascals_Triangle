/* Eric Gallager
 * In-Class Assignment #3
 * 
 * Problem:
 * For this assignment, I would like you to write a program that will print a level of Pascal's Triangle specified by the user.
 *
 * You might recall Pascal's triangle from a previous class. If you don't you may always visit Wikipedia and look up Pascal's triangle.  
 * Consider the first few rows of Pascal's triangle, numbered starting at zero.
 *
 * 0:     1
 * 1:    1  1
 * 2:   1  2  1
 * 3:  1  3  3  1
 * 4: 1  4  6  4  1 
 * 
 * What we can see here is that the zeroth level is 1, then subsequent levels are made by placing 1's at the edges and summing values 'above' the numbers we wish to create for a row.
 * However, there is a short cut for our assignment which is for the user to input a row at zero or more* and then for the program to print the row labeled with that number.
 * We can use Combinations. You might have also heard of combinations, but if you haven't you can also go to Wikipedia.
 * 
 * The Formula for a Combination is:
 * 
 * C(n,r) = n! /(r! * (n-r)!)
 * 
 * What the combination formula is used to do is find out the number of ways to choose items without regard for the order those items are picked in. 
 * When used in this fashion; 
 * n = the number of items in your collection.
 * r = the number of items that you choose from the collection.
 * 
 * Consider then a group of 4 markers which are red, black, green, and blue.
 * There is 1 way to choose 0 markers from the set of 4 markers, you just choose no markers.
 * There are 4 ways to choose 1 markers from the set of 4 markers. You can choose a red one, a green one, a blue one, or a black one.
 * There are 6 ways to choose 2 markers from the set of 4 markers. You can choose (1) red and black, (2) red and green, (3) red and blue, (4) black and green, (5) black and blue, or (6) green and blue.
 * Now consider the formula, choosing 2 markers from a set of 4 markers is called 4 choose 2; which is 
 * C(4,2) = 
 * 4! / (2! * (4-2)!) = 
 * 4!  / (2! * 2!) = 
 * (4*3*2!)/(2!*2!) = 
 * (4*3)/2! = 
 * 12/2 = 
 * 6
 * 
 * There are also 4 ways to choose 3 markers and 1 way to choose all 4 markers. 
 * We can relate this math to Pascal's triangle because the numbers that you get for a row are the same numbers you get when you do the combinations by setting r to the numbers between 0 and n. To take a closer look at the forth row 4: C(4,0)=1, C(4,1)=4, C(4,2)=6, C(4,3)=4, C(4,4) =1.
 * This sort of logic can be done for any other row.
 * 
 * So, now what do you need to do this assignment.
 * You need to write a function for Factorial which you can do easily
 * You need to write a function for Combination, which you can do after you have a function for Factorial.
 * Then you need to use the Combination function to create a row of Pascal's triangle by using the Combination function in a loop from 0 to the user's selected n.
 * 
 * ---
 * 
 * Algorithm for the factorial function:
 * 
 * 1. Get a number as input
 * 2. Find all numbers from that number down to 1 (use a for-loop, subtracting 1 each time) (actually never mind, maybe try recursion instead)
 * 3. Multiply all those numbers
 *
 * Actually never mind all that, there's a perfectly good one in the textbook
 * 
 */ 

#include <math.h>
#include <stdio.h>

/*
 * Factorial function: computes n! for n greater than or equal to zero.
 */
int
factorial(int n)
{
	int i, /* local variables */
		product = 1;
	
	/* Computes the product n x (n-1) x (n-2) x ... x 2 x 1 */
	for (i = n; i > 1; --i) {
		product *= i;
	}
	
	/* Returns function result */
	return (product);
/*	printf("\n %d \n", product); // statement for debugging */
}

/*
 * Combination function: computes the number of combinations of n items taken r at a time
 */
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
