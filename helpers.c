#include <stdlib.h>
#include <string.h>
#include "genome.h"
#include "./Datastructure/customDS.h"


struct Item{
	unsigned char value;
	const char *key;
};

struct dict{
	unsigned int size;
	unsigned int n;
	struct Item *Table;
};

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

unsigned char highest_freq(char *genome, unsigned char kmer_length){

	Dict kmer_dict;
	kmer_dict = DictCreate(100);

	unsigned short g_len = strlen(genome);
	char *temp = malloc(sizeof(char)*kmer_length);
	int position = 0;

	for(int i=0; i< g_len; i++){
		temp     = sliced_str(genome,i,kmer_length);
		position = Dsearch(kmer_dict,temp);
		
		if(position == -1){
			Dinsert(kmer_dict,temp,1);
		}
		else{
			kmer_dict->Table[position].value +=1;
		}
	}

	//To be modified
	unsigned char highest = 0;

	for(int j=0; j< kmer_dict->size ;j++ ){
		if (!strcmp(kmer_dict->Table[j].key,"")){
			continue;
		}

		if (kmer_dict->Table[j].value >= highest){
			highest = kmer_dict->Table[j].value;
		}
	}

	return highest;
}


