#include "bstree.h"
#include <stdlib.h>
#include <string.h>

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
	tmp->left_tree = NULL;
	tmp->right_tree = NULL;
	return tmp;
}
