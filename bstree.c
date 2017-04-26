#include "bstree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bstree *bstree_create(char *key, int value)
{
	bstree *tmp = calloc(1, sizeof(bstree));
	if (tmp == NULL) {
		return NULL;
	}
	tmp->key = calloc(strlen(key) + 1, sizeof(char));
	if (tmp->key == NULL) {
		free(tmp);
		return NULL;
	}
	strcpy(tmp->key, key);
	tmp->value = value;
	tmp->first = NULL;
	tmp->second = NULL;
	return tmp;
}

void bstree_add(bstree *tree, char *key, int value)
{
	if (tree == NULL) {
		printf("Error bstree_add NULL pointer\n");
		return;
	}

	int tmp = strcmp(key, tree->key);
	
	if (tree->first == NULL && tree->second == NULL) {
		if (tmp < 0) {
			tree->first = bstree_create(key, value);
		} else if (tmp > 0) {
			tree->second = bstree_create(key, value);
		}
		return;
	}
	
	if (tree->first != NULL && tmp < 0) {
		bstree_add(tree->first, key, value);
		return;
	}
	if (tree->second != NULL && tmp > 0) {
		bstree_add(tree->second, key, value);
		return;
	}
	if (tmp == 0) {
		value++;
	}
}

void bstree_delete(bstree *tree)
{
	if (tree == NULL) {
		return;
	}
	if (tree->first != NULL) {
		bstree_delete(tree->first);
	}
	if (tree->second != NULL) {
		bstree_delete(tree->second);
	}
	free(tree->key);
	free(tree);
}
