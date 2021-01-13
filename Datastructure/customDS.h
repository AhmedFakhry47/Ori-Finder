#ifndef CUSTOMDS_H_
#define CUSTOMDS_H_

typedef struct dict *Dict;
typedef struct Item Item;

Dict DictCreate(unsigned int size);
void DictGrow(Dict oriP);
unsigned int hash(const char *key, unsigned int length);
void insert(Dict diH,const char *key,unsigned char value);
	
#endif