/*
* File: pi_algorithm.c
* Author: Julio Freire
*
* Created on March 31, 2024
*
* This algorithm that aproximates the value of Pi using a method called Monte Carlo.
* The insight to develop the entire algorithm was gained by calculating using the first tip
* given in class.
* Some syntax were written with the help of ChatGPT, but the main logic was developed by the author.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// void Usage(char* prog_name);

void Usage(char* prog_name) {

   fprintf(stderr, "usage: %s <lenght of the square> <number of trials>\n", prog_name);
   // fprintf(stderr, "<number of trials>\n");
   exit(0);
}  /* Usage */


int main(int argc, char *argv[]){

	// Declaring variables
	float lenght, lenght_up2;
	float x, y;
	float r_up2;
	float n_hits, n_trials;

	// Initiate the number of hits
	n_hits = 0;
	
	// Using time to generate a new seed
    srand(time(NULL));

    // Asking a value of lenght and generate a random point inside the lenght
	// printf("Please enter a value to lenght of the square:\n");
	// scanf("%f", &lenght);

	// This number will be compared with a hypotenuse of triangle
	

	// The number of trials or points that will be generated
	// printf("Please enter the number of trials:\n");
	// scanf("%f", &n_trials);

	if (argc != 3) Usage(argv[0]);
	lenght = strtof(argv[1], NULL);
	n_trials = strtof(argv[2], NULL);

	lenght_up2 = (lenght * lenght)/4;

	for(int i = 0; i < n_trials; i++){
		// Generate a random pair of coordinates between -lenght/2 to lenght/2
		x = (((float)rand() / ((float)RAND_MAX + 1.0)) * (lenght)) - lenght/2;
		y = (((float)rand() / ((float)RAND_MAX + 1.0)) * (lenght)) - lenght/2;

		// Checking if the point is inside of a circle with radius equals to lenght/2
		r_up2 = x*x + y*y;
		if (r_up2 <= lenght_up2) {
			n_hits++;
		}
	}
	// This formula is obtained through (Area of circle/Area of square) = (n_hits/n_trials)
	float p = 4 * (n_hits/n_trials);
	printf("%f\n", p);

	return 0;
}
