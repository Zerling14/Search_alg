#include "hashtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_MUL 31
#define HASH_SIZE 128

unsigned int hashtab_hash(char *key)
{
	return strlen(key) % 10;
}

unsigned int hash_hash(char *s) 
{
	int h = 0;
	char *p;
	for (p = s; *p != '\0'; p++) {
		h = h * HASH_MUL + (unsigned int)*p;
	}
	return h % HASH_SIZE;
}

void hashtab_init(listnode **hashtab)
{
	if (hashtab == NULL) {
		printf("hashtab_init error listnode pointer is NULL\n");
		return;
	}
	//*hashtab = calloc(10, sizeof(listnode*));
	for (int i = 0; i < 128; i++) {
		hashtab[i] = calloc(1, sizeof(listnode));
	}
	return;
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
	unsigned int key_hash = hash_hash(key) % 128;
	//printf("\n%u\n", key_hash);
	listnode *node = hashtab[key_hash];	
	//printf("\n%u\n", key_hash);
	do {
		//printf("%p\n", node);
		if(node->key == NULL) {
			//printf("c\n");
			node->key = calloc(strlen(key) + 1, sizeof(char));
			strcpy(node->key, key);
			//printf("dgdf\n");
			return;
		}
		if (node->key != NULL && node->next == NULL) {
			//printf("cn\n");
			node->next = calloc(1, sizeof(listnode));
			node->next->key = calloc(strlen(key) + 1, sizeof(char));
			strcpy(node->next->key, key);
			return;
		}
			node = node->next;
	}
	while (node != NULL);

}

listnode *hashtab_lookup(listnode **hashtab, char *key)
{
	if (hashtab == NULL) {
		printf("hashtab_lookup error listnode pointer is NULL\n");
		return NULL;
	}
	if (key == NULL) {
		printf("hashtab_lookup error key pointer is NULL\n");
		return NULL;
	}
	unsigned int key_hash = hash_hash(key);
	listnode *node = hashtab[key_hash];
	if (node->key != NULL && strcmp(node->key, key) == 0) {
		return node;
	}
	while (node->next != NULL) {
		node = node->next;
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}

void hashtab_delete(listnode **hashtab, char *key) 
{

}





