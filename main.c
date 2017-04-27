#include <stdio.h>
#include "bstree.h"
#include "hashtab.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void swap (char **a, char **b) {
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify (char *arr[], int pos, int n) {
    while (2 * pos + 1 < n) {
        
        int t = 2 * pos +1;
        if (2 * pos + 2 < n && strcmp(arr[2 * pos + 2], arr[t]) >= 0)
        {
            t = 2 * pos + 2;
        }
        if (strcmp(arr[pos], arr[t]) < 0) {
            swap(&arr[pos], &arr[t]);
            pos = t;
        } 
        else break;
        
    }
}

void heap_make(char *arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void load_rand_num(char *num_arr[], int num_in_tree, int max_element)
{
	char buf[10];
	for (int i = 0; i < num_in_tree; i++) {
			num_arr[i] = calloc(strlen(itoa(rand() % max_element, buf, 10)), sizeof(char));
			strcpy(num_arr[i], buf);
	}
}
void free_rand_num(char *num_arr[], int num_in_tree)
{
	for (int i = 0; i < num_in_tree; i++) {
		free(num_arr[i]);
	}
}

int main()
{
	while(1) {
		system("clear");
		srand(time(0));
		int max_element = 50;
		int num_in_tree = 20000;
		char *num_arr[num_in_tree];
		load_rand_num(num_arr, num_in_tree, max_element);

		
		heap_make(num_arr, num_in_tree);
		
		bstree *test = bstree_create(num_arr[num_in_tree / 2], 1);
		
		for (int i = (num_in_tree / 2) - 1; i >= 0; i--) {
				bstree_add(test, num_arr[i], 1);
		}
		for (int i = (num_in_tree / 2) + 1; i < num_in_tree; i++) {
				bstree_add(test, num_arr[i], 1);
		}
		
		free_rand_num(num_arr, num_in_tree);
		
		int sum_all_node = 0;
		char buf[10];
		for(int i = 0; i < max_element; i++) {
			bstree *result = bstree_lookup(test, itoa(i, buf, 10));
			if (result == NULL) {
				continue;
			}
			sum_all_node += result->value;
		}
		printf("Sum all elements: %d\n", sum_all_node);
		bstree *min = bstree_min(test);
		printf("min: %d : %s\n", min->value, min->key);
		bstree *max = bstree_max(test);
		printf("max: %d : %s\n", max->value, max->key);
		
		bstree_print_init(test, 30);
		bstree_delete(test);
		Sleep(1000);
	}
	return 0;
}
