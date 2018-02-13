/*--------------*/ 
/* Ryan Kozak   */ 
/* Lab 4        */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

int main(void) { 

	int c,square, start, end;
	double s2root, sine;

	printf("\nRyan Kozak. Lab 4.\n");

	printf("\nEnter your Start Number:  ");
	scanf("%i", &start);


	printf("\nEnter your End Number:  ");
	scanf("%i", &end);


	printf("\n  N       Squared      Square Root       Sine \n");
	printf("-----     -------      -----------     --------\n");

	for(c = start; c <= end; c++) {

		square = c*c;
		s2root = sqrt(c);
		sine = sin(c);

		printf("% 4i      % 6i      % 11.3f       % -.3f\n", c, square, s2root, sine);
	}

	printf("\n");

	return EXIT_SUCCESS;

}

