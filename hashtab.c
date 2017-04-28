#include "hashtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned int hashtab_hash(char *key)
{
	return strlen(key) % 10;
}

void hashtab_init(listnode **hashtab)
{
	if (hashtab == NULL) {
		printf("hashtab_init error listnode pointer is NULL\n");
		return;
	}
	*hashtab = calloc(10, sizeof(listnode));
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
	if (hashtab == NULL) {
		printf("hashtab_add error listnode pointer is NULL\n");
		return;
	}
	if (key == NULL) {
		printf("hashtab_add error key pointer is NULL\n");
		return;
	}
	unsigned int key_hash = hashtab_hash(key);
	while (hashtab[key_hash]->next == NULL) {
		if ((*hashtab)->key == NULL) {
			(*hashtab)->value = value;
			(*hashtab)->key = calloc(strlen(key) + 1, sizeof(char));
			strcpy((*hashtab)->key, key);
			return;
		}
		if ((*hashtab)->key != NULL) {
			if(strcmp((*hashtab)->key, key) == 0) {
				return;
			}
			hashtab_add((*hashtab)->next, key, value);
		}
	}
}

listnode *hashtab_lookup(listnode **hashtab, char *key)
{
	
}