#ifndef BSTREE_H
#define BSTREE_H

typedef struct bstree{
	char *key;
	int value;
	struct bstree *first;
	struct bstree *second;
} bstree;

bstree *bstree_create(char *key, int value); //

void bstree_add(bstree *tree, char *key, int value); //

bstree *bstree_lookup(bstree *tree, char *key); //

bstree *bstree_min(bstree *tree);

bstree *bstree_max(bstree *tree);

void bstree_delete(bstree *tree); ////

void bstree_print_init(bstree *tree, int arr_size); ////

void bstree_print(bstree *tree, int num, char **arrs, int arr_size); //

#endif
