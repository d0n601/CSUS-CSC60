/*------------------------------------------------------------------*/
/* Ryan Kozak                                                       */
/* Lab 5                                                            */
/* Figure the perimeter and area of a polygon                       */
/* surrounded by a circle                                           */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define IN_FILE_NAME "lab5sample.dat"
#define IN_FILE_NAME "lab5.dat"
//#define OUT_FILE_NAME "lab5sample.out"
#define OUT_FILE_NAME "lab5.out"
 
int main(void) {

	double radius, nsides, perimeter, area;
	FILE * data_file;
	FILE * output_file;
	

	data_file = fopen(IN_FILE_NAME, "r");
	
	if (data_file == NULL) {
		printf ("Error opening the data file \n");
		exit (EXIT_FAILURE);
	}


	output_file = fopen(OUT_FILE_NAME, "w");

	if(output_file == NULL) {
		printf("Error on opening the output file\n");
		exit(EXIT_FAILURE);
	}  


        fprintf(output_file, "\nRyan Kozak.  Lab 5.\n\n");
        fprintf(output_file, "            Number      Perimeter      Area Of  \n");
        fprintf(output_file, " Radius    Of Sides    Of Polygon      Polygon  \n");
        fprintf(output_file, "--------   --------   ------------   ----------- \n");

	while(fscanf(data_file, "%lf%lf", &radius, &nsides) == 2) {
				
		perimeter = 2 * nsides * radius * sin(M_PI/nsides);
		area = 0.5 *  nsides * pow(radius,2.0) * sin(2*M_PI/nsides);

        	fprintf(output_file, "%7.2f   %8.2f   %12.4f  %12.4f\n", radius, nsides, perimeter, area);

	}        	
	
	fclose(data_file);
	fclose(output_file);

}
