#ifndef BSTREE_H
#define BSTREE_H

typedef struct {
	char *key;
	int value;
} bstree;

struct bstree *bstree_create(char *key, int value);

void bstree_add(bstree *tree, char *key, int value);

struct bstree *bstree_lookup(bstree *tree, char *key);

struct bstree *bstree_min(bstree *tree);

struct bstree *bstree_max(bstree *tree);

#endif
