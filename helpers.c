#include <stdlib.h>
#include <string.h>
#include "genome.h"

char *sliced_str(char *genome, int i, unsigned short k){

	char *temp = malloc(sizeof(char)*k);

	for(int j=0; j< k ; j++){
		*(temp+j) = *(genome+i+j);
	}

	return temp;
}

unsigned char find_freq(char *genome, char *kmer){

	unsigned char freq = 0;

	unsigned short g_len = strlen(genome);
	unsigned short k_len = strlen(kmer);


	char *temp = malloc(sizeof(char)*k_len);

	for (int i =0 ; i < g_len; i ++ ){
		
		temp = sliced_str(genome,i,k_len);

		if(!strcmp(temp,kmer)){
			freq++;
		}
	}	

	return freq;
}


