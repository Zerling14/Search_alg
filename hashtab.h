#ifndef HASHTAB_H
#define HASHTAB_H

typedef struct listnode{
	int value;
	char *key;
	struct listnode *next;
} listnode;

unsigned int hashtab_hash(char *key);

void hashtab_init(listnode **hashtab);

void hashtab_add(listnode **hashtab, char *key, int value);

listnode *hashtab_lookup(listnode **hashtab, char *key);

void hashtab_delete(listnode **hashtab, char *key);

#endif
