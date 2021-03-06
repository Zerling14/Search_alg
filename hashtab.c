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
	//return KPHash(s);
	return ELFHash(s);
	
}

unsigned int KPHash(char *s) 
{
	int h = 0;
	char *p;
	for (p = s; *p != '\0'; p++) {
		h = h * HASH_MUL + (unsigned int)*p;
	}
	return h;
	
}

unsigned int ELFHash(char *key)
{
	unsigned int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h;
}

void hashtab_init(listnode **hashtab)
{
	if (hashtab == NULL) {
		printf("hashtab_init error listnode pointer is NULL\n");
		return;
	}
	//*hashtab = calloc(10, sizeof(listnode*));
	for (int i = 0; i < 10000; i++) {
		hashtab[i] = calloc(1, sizeof(listnode));
	}
	return;
}

int collision = 0;

int get_num_collision()
{
	return collision;
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
	unsigned int key_hash = hash_hash(key) % 10000;
	//printf("\n%u\n", key_hash);
	listnode *node = hashtab[key_hash];	
	//printf("\n%u\n", key_hash);
	do {
		//printf("%p\n", node);
		if(node->key == NULL) {
			//printf("c\n");
			node->key = calloc(strlen(key) + 1, sizeof(char));
			node->value = value;
			strcpy(node->key, key);
			//printf("dgdf\n");
			return;
		}
		if (node->key != NULL && node->next == NULL) {
			//printf("cn\n");
			collision++;
			node->next = calloc(1, sizeof(listnode));
			node->next->key = calloc(strlen(key) + 1, sizeof(char));
			node->next->value = value;
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
	unsigned int key_hash = hash_hash(key) % 10000;
	listnode *node = hashtab[key_hash];
	if (node->key != NULL && strcmp(node->key, key) == 0) {
		return node;
	}
	while (node->next != NULL) {
		node = node->next;
		//printf("%u\n", key_hash);
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}

void hashtab_delete(listnode **hashtab, char *key) 
{

}
