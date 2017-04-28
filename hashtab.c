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
	//*hashtab = calloc(10, sizeof(listnode*));
	for (int i = 0; i < 10; i++) {
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
	unsigned int key_hash = hashtab_hash(key);
	listnode *node = hashtab[key_hash];	
	printf("%p\n", node);
	do {
		if(node->key == NULL) {
			printf("c\n");
			node->key = calloc(strlen(key) + 1, sizeof(char));
			strcpy(node->key, key);
			return;
		}
		if (node->key != NULL && node->next == NULL) {
			printf("cn\n");
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
	unsigned int key_hash = hashtab_hash(key);
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





