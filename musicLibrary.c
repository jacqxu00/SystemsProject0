/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "musicLibrary.h"


/* takes a pointer to a node struct and prints out all of the data in the list */
void print_list(struct node * list) {
	while (list) {
		printf("%d -> ", list->i);
		list = list->next;
	}
	printf("NULL\n");
}

/* takes a pointer to the existing list and the data to be added, creates a new node and puts
it at the beginning of the list; second argument match whatever data you contain in your nodes;
returns a pointer to the beginning of the list. */
struct node * insert_front(struct node * list, int x) {
	struct node *ans = (struct node *) malloc(sizeof(struct node));
	ans->i = x;
	ans->next = list;
	return ans;
}

/* takes a pointer to a list as a parameter and then goes through the entire list freeing
each node and return a pointer to the beginning of the list (which should be NULL by then). */               
struct node * free_list(struct node * list) {
	while (list) {
		struct node *temp = list;
		free(list);
		temp = list;
	}
	//once released you have no access to piece of memory anymore
	//then in main you would do n = free_list(n) to reallocate memory
	return NULL;
}