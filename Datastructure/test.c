#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customDS.h"

struct Item{
	unsigned char value;
	const char *key;
};

struct dict{
	unsigned int size;
	unsigned int n;
	struct Item *Table;
};

void main(void){
	Dict mydict;

	mydict = DictCreate(2);
	const char *key = "hey";
	insert(mydict,key,4);
	
	return;
}	