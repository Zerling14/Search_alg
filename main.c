#include <stdio.h>
#include "bstree.h"
#include "hashtab.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

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
			num_arr[i] = calloc(strlen(itoa(rand() % max_element, buf, 10)) + 1, sizeof(char));
			strcpy(num_arr[i], buf);
	}
}
void free_rand_num(char *num_arr[], int num_in_tree)
{
	for (int i = 0; i < num_in_tree; i++) {
		free(num_arr[i]);
	}
}

void load_words(char *num_arr[], int num_in_tree)
{
	FILE *in = fopen("word.txt", "r");
	char buf[256];
	for (int i = 0; i < num_in_tree; i++) {
			fscanf(in ,"%s[^\n]", buf);
			//printf("%s\n", buf);
			num_arr[i] = calloc(strlen(buf) + 1, sizeof(char));
			strcpy(num_arr[i], buf);
	}
	fclose(in);
}

int calc_num_word(char *name_file)
{
	FILE *in = fopen(name_file, "r");
	char buf[256];
	int i = 0;
	while (!feof(in)) {
		fscanf(in ,"%s[^\n]", buf);
		i++;
	}
	fclose(in);
	return i;
}

int main()
{
	setlocale(0, "");
	//while(1) {
		system("clear");
		srand(time(0));
		//int max_element = 80; //or
		int num_in_tree = calc_num_word("word.txt");
		char *num_arr[num_in_tree];
		//load_rand_num(num_arr, num_in_tree, max_element); // or
		load_words(num_arr, num_in_tree);
		
		heap_make(num_arr, num_in_tree);
		
		bstree *test = bstree_create(num_arr[num_in_tree / 2], 1);
		
		for (int i = (num_in_tree / 2) - 1; i >= 0; i--) {
			bstree_add(test, num_arr[i], 1);
		}
		for (int i = (num_in_tree / 2) + 1; i < num_in_tree; i++) {
			bstree_add(test, num_arr[i], 1);
		}
		
		free_rand_num(num_arr, num_in_tree);
		
		// int sum_all_node = 0;
		// char buf[10];
		// for(int i = 0; i < max_element; i++) {
			// bstree *result = bstree_lookup(test, itoa(i, buf, 10));
			// if (result == NULL) {
				// continue;
			// }
			// sum_all_node += result->value;
		// }
		// printf("Sum all elements: %d\n", sum_all_node);
		
		bstree *min = bstree_min(test);
		printf("min: %d : %s\n", min->value, min->key);
		bstree *max = bstree_max(test);
		printf("max: %d : %s\n", max->value, max->key);
		
		//bstree_print_init(test, 30);
		bstree_delete(test);
		Sleep(1000);
	//}
	return 0;
}
