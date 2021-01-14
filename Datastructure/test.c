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

	mydict = DictCreate(5);
	const char *key = "hey";
	
	Dinsert(mydict,"Soha",4);
	Dinsert(mydict,"BAmed",3);
	Dinsert(mydict,"BB",1);

	unsigned char value = Dsearch(mydict, "");

	printf("%d\n",value);
	return;
}	