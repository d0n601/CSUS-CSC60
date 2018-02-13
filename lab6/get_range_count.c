/*-----------------------------------------------------------*/
/* Ryan Kozak                                                */
/* LAB 6   1-dimensional arrays                              */

#include "lab6.h"

void get_range_count(int number_list[], int real_filesize, int *range_count) {
	
	*range_count = 0;

	for(int c = 0; c < real_filesize; c++) {
		if( number_list[c] >= 90 && number_list[c] <= 99 ) {
			(*range_count)++;
		}
	}

    return;
}


