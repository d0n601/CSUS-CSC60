/*-------------------------------------------------------------*/
/* Ryan Kozak                                                  */
/* LAB 6   1-dimensional arrays                                */


#include "lab6.h"

const char *FILENAME[] = 	/* array of the data file names */
    {"lab6a.dat", "lab6b.dat", NULL };

/*---------------------------------------------------------------*/
int main(void) {

    int file_count = 0;         /* keeps track of which file we are on */
    int check_overflow = 0;     /* counter to prevent array overflow   */
    int real_filesize = 0;      /* actual count of the values read     */
    int number_list[MAX_SIZE];  /* the array                           */
    int range_count;         /* count of numbers within the range   */


    /* loop through each file, reading it, and getting stats on it */

    for (file_count=0; FILENAME[file_count] != NULL; file_count++) {

       real_filesize = get_data( FILENAME[file_count], number_list );
	    
       get_range_count(number_list, real_filesize, &range_count);

       print_all(FILENAME[file_count], real_filesize, &range_count);

    }
    return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------*/
/* This function will open the input file, read the data into      */
/* array k, and return real_filesize.                              */

int get_data(const char *filename,  /* input, current file name */
	     int number_list[])     /* output, the filled array */
{
    FILE * input_file;
    int real_filesize=0;

    input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
	printf("Error on file-open of file %s", filename);
	exit(EXIT_FAILURE);
    }
	
    while ((fscanf(input_file, "%i", &number_list[real_filesize])) == 1)
	real_filesize += 1;

    return real_filesize;
}

/*-----------------------------------------------------------------*/
/* This function will print all but your name (which is above)     */

void print_all(	const char *filename,  /* input, the current filename    */
		int real_filesize,     /* input, actual size of the data */
		int *range_count)   /* input, # of values in range    */
{
    int d;

    printf("\n\nRyan Kozak.  Lab 6. \n\n");
    printf("\nFile %s:  ", filename);
    printf("\nThere are %i values in the range of 90 through 99\n",*range_count);
    printf("out of a total of %i values.", real_filesize);
	
    printf("\n\n");

    return;
}
/*-----------------------------------------------------------------*/

