#include "bstree.h"

bstree *bstree_create(char *key, int value)
{
	bstree *tmp = calloc(1, sizeof(bstree));
	bstree->key = calloc(strlen(key) + 1, sizeof(char);
	strcpy(bstree->key, key);
	bstree->value = value;
	return bstree;
}
