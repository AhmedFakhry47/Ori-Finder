#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customDS.h"

#define BASE 255
#define INITIAL_SIZE 60
#define GROWTH_FACTOR 2

struct Item{
	unsigned char value;
	const char *key;
};

struct dict{
	unsigned int size;
	unsigned int n;
	struct Item *Table;
};


Dict DictCreate(unsigned int size){
	Dict d;

	d = malloc(sizeof(*d));
	d->size  = size;
	d->n     = 0;
	d->Table = malloc(sizeof(Item) * d->size);

	if( d->Table ==0){
		return NULL;
	}

	for(int i=0; i< d->size ; i++){
		d->Table[i].value = 0; 	
		d->Table[i].key   = "";
	} 
	return d;
}


void DictGrow(Dict oriP){

	int old_size = oriP->size;
	oriP = realloc(oriP, oriP->size * GROWTH_FACTOR );
	oriP->size = old_size * GROWTH_FACTOR;

	return;
}

unsigned int hash(const char *key, unsigned int length){
	/*
	A function that :
		1-Takes the string key of the hash table
		2-Length of the hash table array
	  returns:
	  	 - The randomized position of the hash table
	*/
	
	unsigned int h =0;
	unsigned const char *us = (unsigned const char *) key; // Mapping to 0-255
	
	while(*us != '\0'){
		h = (h * BASE + *us) % length;
		us++;
	}
	return h;
	
}

void Dinsert(Dict diH,const char *key,unsigned char value){

	unsigned int position = hash(key,diH->size);
	diH->Table[position].value = value;
	diH->Table[position].key   = key;

	diH->n ++;

	if (diH->n >= diH->size) DictGrow(diH);
	return;
}

unsigned char Dsearch(Dict diH, const char *key){

	unsigned int position = hash(key, diH->size);
	const char *Okey   = diH->Table[position].key;

	printf("%s\n", Okey );
	if (!strcmp(Okey,"\0")){
		printf("No such key ! \n");
		return 0;
	}

	unsigned char value   = diH->Table[position].value;
	return value;
}

void Ddelete(Dict diH, const char *key){

	unsigned int position = hash(key, diH->size);
	const char *Okey   = diH->Table[position].key;

	if (strcmp(Okey,"\0")){
		diH->Table[position].key   = "";
		diH->Table[position].value = 0;
	}
	else{
		printf("No such key !\n");
		return;
	}
	return;
}