#include "bstree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
bstree *bstree_create(char *key, int value)
{
	if (key == NULL) {
		printf("bstree_create: key is null");
		return 0;
	}
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
	if (tree->first == NULL && tmp < 0) {
		tree->first = bstree_create(key, value);
		return;
	}
	if (tree->second == NULL && tmp > 0) {
		tree->second = bstree_create(key, value);
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
		tree->value++;
	}
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	if (tree == NULL) {
		printf("Error bstree_lookup NULL pointer\n");
		return NULL;
	}
	
	int tmp = strcmp(key, tree->key);
	bstree *result = NULL;
	if (tree->first != NULL && tmp < 0) {
		result = bstree_lookup(tree->first, key);
	} else if (tree->second != NULL && tmp > 0) {
		result = bstree_lookup(tree->second, key);
	} else if (tmp == 0) {
		result = tree;
	}
	return result;
}

void bstree_print_init(bstree *tree, int arr_size) 
{
	printf("%d\n", arr_size);
	char *arrs[arr_size];
	for (int i = 0; i < arr_size; i++) {
		arrs[i] = calloc(120, sizeof(char));
		for (int j = 0; j < arr_size - i; j++) {
			strcat(arrs[i], " ");
		}
	}
	bstree_print(tree, 0, arrs, arr_size);
	for (int i = 0; i < arr_size; i++) {
		printf("\n%s", arrs[i]);
		free(arrs[i]);
	}
}

void bstree_print(bstree *tree, int num, char **arrs, int arr_size)
{
	if (tree == NULL) {
		strcat(arrs[num], " ");
		strcat(arrs[num], "e");
		if (num + 1 < arr_size) {
			strcat(arrs[num + 1], " ");
		}
		return;
	}
	strcat(arrs[num], " ");
	strcat(arrs[num], tree->key);
	// for (int numt = num-1; numt > 0; numt--) {
		// strcat(arrs[numt], " ");
	// }
	//printf("%s ", tree->key);
	if (num + 1 < arr_size) {
		bstree_print(tree->first, num + 1, arrs, arr_size);
		bstree_print(tree->second, num + 1, arrs, arr_size);
	}
 }

bstree *bstree_min(bstree *tree) {
	if (tree == NULL) {
		printf("Error bstree_min NULL pointer\n");
		return NULL;
	}

	bstree *result = NULL;
	bstree *tmp;
	if (tree->first != NULL) {
		tmp = bstree_min(tree->first);
		if (tmp != NULL && tmp->value < tree->value) {
			result = tmp;
		} else {
			result = tree;
		}
	} 
	if (tree->second != NULL) {
		tmp = bstree_min(tree->second);
		if (tmp != NULL && tmp->value < tree->value) {
			result = tmp;
		} else {
			result = tree;
		}
	}
	return result;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL) {
		printf("Error bstree_min NULL pointer\n");
		return NULL;
	}
	bstree *result = tree;
	bstree *tmp;
	if (tree->first != NULL) {
		tmp = bstree_max(tree->first);
		if (tmp != NULL && tmp->value > result->value) {
			result = tmp;
		}
	} 
	if (tree->second != NULL) {
		tmp = bstree_max(tree->second);
		if (tmp != NULL && tmp->value > result->value) {
			result = tmp;
		}
	}
	return result;
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
