/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "song_lists.h"

// takes: a pointer to a node struct, prints out all of the data in the list
void print_list(struct song_node * list) {
	while (list) {
		printf("%d -> ", list->i);
		list = list->next;
	}
	printf("NULL\n");
}

//takes in pointers to two different song nodes, compares the artist strings then song title strings;
// returns: -1 if a comes before b, 0 if they are the same, 1 if b comes before a
int compare_nodes(struct song_node * a, struct song_node * b) {
	return 0;
}

// takes a pointer to the existing list and the data to be added, creates a new node and puts it at the beginning of the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_front(struct song_node * list, char * person, char * song) {
	struct song_node *ans = (struct song_node *) malloc(sizeof(struct song_node));
	ans->artist = person;
	ans->name = song;
	return ans;
}

// takes a pointer to the existing list and the data to be added, creates a new node and alphabetizes it in the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_song(struct song_node * list, char * person, char * song) {
	return NULL;
}

// takes a pointer to the existing list, goes through the entire list freeing each node;
// returns: a pointer to the beginning of the list (which should be NULL by then).              
struct song_node * free_list(struct song_node * list) {
	while (list) {
		struct song_node *temp = list;
		free(list);
		temp = list;
	}
	//once released you have no access to piece of memory anymore
	//then in main you would do n = free_list(n) to reallocate memory
	return NULL;
}

// takes a pointer to the existing list and a song title, goes through entire list until song title matches;
// returns: a pointer to the node whose song title matches parameter
struct song_node * find_song(struct song_node * list, char * song) {
	return NULL;
}

// takes a pointer to the existing list and an artist name, goes through entire list until artist name matches;
// returns: a pointer to the first node whose artist name matches parameter
struct song_node * find_artist(struct song_node * list, char * person) {
	return NULL;
}

// takes a pointer to the existing list, goes through the entire list;
// returns: how many nodes in the entire linked list
int length_of(struct song_node * list) {
	return 0;
}

// takes a pointer to the existing list;
// returns: how a pointer to a random node in the list
struct song_node * find_random() {
	return NULL;
}

// takes a pointer to the existing list and a node to be removed, goes through entire list until node matches and removes it;
void remove_song(struct song_node * list, struct song_node * one) {
}
