#include <stdio.h>
#include <stdlib.h>
#include "genome.h"

char *InputString(FILE *fp ,size_t size){
	char *str;
	size_t clen = 0;

	char ch;

	str  = realloc(NULL, sizeof(*str) * size);
	if (!str) return str;

	while (EOF!=(ch=fgetc(fp)) && ch != '\n'){
		str[clen++] = ch;

		if (clen == size){
			str = realloc(str, sizeof(*str) * (size += 8));
			if (!str) return str;
		}
	}

	str[clen++] = '\0';
	str = realloc(str, sizeof(*str)*clen); //Shrinking The Memory again
	return str;
}

void main(void){
	char *genome;
	char *kmer;

	printf("Enter the genome sequence: \n");
	genome = InputString(stdin, 8);

	printf("Enter the kmer to find number of freq : \n");
	kmer   = InputString(stdin, 3);

	unsigned char freq = find_freq(genome,kmer);
	printf("The kmer '%s' is repeated number of %d times \n",kmer,freq);

	
}	