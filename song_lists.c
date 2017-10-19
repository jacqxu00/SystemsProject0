/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_lists.h"

// takes: a pointer to a node struct, prints out all of the data in the list
void print_list(struct song_node * list) {
	printf("\n");
	while (list) {
		printf(" artist: %s \n ", list->artist);
		printf(" song: %s \n", list->name);
		list = list->next;
	}
	//printf("NULL\n"); //only for testing purposes
}

// takes a pointer to the existing list and the data to be added, creates a new node and puts it at the beginning of the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_front(struct song_node * list, struct song_node * insert) {
	insert->next = list;
	return insert;
}

struct song_node * insert_end(struct song_node * list, struct song_node * insert){
	while(list && list->next != NULL){
		list = list->next; }

	list->next = insert;
	return insert;
}

//takes in pointers to two different song nodes, compares the artist strings then song title strings;
// returns: -1 if a comes before b, 0 if they are the same, 1 if b comes before a
int compare_nodes(struct song_node * a, struct song_node * b) {
	char * artist_A = a->artist;
	char * artist_B = b->artist;

	if (strcmp(artist_A, artist_B) < 0){
		return -1; } //this means artist a is before artist b

	else{
			if (strcmp(artist_A, artist_B) > 0){
				return 1; } //this means artist a comes after artist b

			else{
				char * song_A = a->name;
				char * song_B = b->name;
				if (strcmp(song_A, song_B) < 0){
					return -1; } //this means song a comes before song b
				if (strcmp(song_A, song_B) > 0){
					return 1; } //this means song a comes after song b
				}
		}

		return 0; //if all else fails
}

// inputs information into a song_node
// returns: a pointer to the song_node
struct song_node * initialize_song(struct song_node * node, char * person, char * song){
	strcpy(node->artist, person);
	strcpy(node->name, song);
	return node;
}

// takes a pointer to the existing list and the data to be added, creates a new node and alphabetizes it in the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_song(struct song_node * list, struct song_node * insert) {
	struct song_node *copy = list; //so we can return beginning of the list later

	//while the current song's artist and name is not "less" than the song we want to insert
	while (list && list->next != NULL && compare_nodes(list->next, insert) != 0 && compare_nodes(list, insert) != 0){
		//case 1: if insert should be first song in list
		if (compare_nodes(insert,list) < 0){
			insert_front(list, insert);
		 	return copy; }

		//case 2: add in middle
		else if (compare_nodes(insert,list) > 0 && compare_nodes(insert, list->next) < 0){
			insert->next = list->next;
			list->next = insert;
			return copy; }

		list = list->next; }

		//case 3: if insert should be the last song in list
		//if while loop lasted till end, we know insert end must be the case
		insert_end(list,insert);
		return copy;
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
	while (list){
		if (strcmp(list->name, song) == 0){
			print_list(list); //for testing purposes
			return list; }
		else{
			list = list->next; }
	}

	printf("\n Song not found :( \n");
	return NULL;
}

// takes a pointer to the existing list and an artist name, goes through entire list until artist name matches;
// returns: a pointer to the first node whose artist name matches parameter
struct song_node * find_artist(struct song_node * list, char * person) {
	while (list){
		if (strcmp(list->artist, person) == 0){
			print_list(list);
			return list; }
		else{
			list = list->next; }
	}

	printf("\n Artist not found :( \n");
	return NULL;
}

// takes a pointer to the existing list, goes through the entire list;
// returns: how many nodes in the entire linked list
int length_of(struct song_node * list) {
	int ans = 0;
	while (list) {
		list = list->next;
		ans++;
	}
	return ans;
}

//this needs a parameter
// takes a pointer to the existing list;
// returns: how a pointer to a random node in the list
struct song_node * find_random(struct song_node * list) {
	int l = length_of(list);
	printf("\nlength of list: %d \n", l);

	srand(time(NULL));
	int r = ( rand() % l) + 1;
	printf("\nrandom index: %d \n", r);

	int i = 0;

	//this needs work
	while(i < r){
		list = list->next;
		i++; }

	return list;
}

// takes a pointer to the existing list and a node to be removed, goes through entire list until node matches and removes it;
// returns: pointer to the beginning of the edited list
struct song_node * remove_song(struct song_node * list, struct song_node * one) {
	struct song_node *copy = list; //so we can return beginning of the list later

	//case 1: if remove first node of list
	if (compare_nodes(list,one) == 0){
		copy = list->next;
	 	list = NULL; //FIX to free
	}

	else {
		while (list && list->next != NULL){
			//case 2: remove from the middle
			if (compare_nodes(one,list->next) == 0){
				struct song_node *temp = list->next;
				list->next = temp->next;
				temp->next = NULL; //FIX to free
			}

			list = list->next;
		}
	}

	//case 3: remove from the end
	//if while loop lasted till end, we know list is the last node
	list = NULL; //FIX to free
	return copy;
}

/** ignore, to be explained later
void set_firstsong(struct song_node * first, struct song_node * list,  struct song_node * insert){
	while(list){
		if (compare_nodes(list,insert) < 0){
			first = list;
			insert_song(list, insert); }
		else{
			if(list->next == NULL){
				first = insert;
				insert_song(insert, list); } //linking step
			else{
				list = list->next; }
		}
	}
} */


int main(){

	/**
	//wanna get rid of this chunk later
	struct song_node *song1 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song2 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song3 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song4 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song5 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song6 = (struct song_node *)malloc(sizeof(struct song_node));

	initialize_song(song1, "A", "a song");
	initialize_song(song2, "B", "b song");
	initialize_song(song3, "C", "c song");
	initialize_song(song4, "D", "d song");
	initialize_song(song5, "E", "e song");
	initialize_song(song6, "F", "f song");

	//testing inserting in beginning
	printf("\ntesting insert a in front of b->c->d, should print a -> b -> c -> d \n");
	song2->next = song3;
	song3->next = song4; //so far, it's b -> c ->d
	insert_song(song2, song1);
	print_list(song1);

	//testing inserting in end
	printf("\ntesting insert f in end of a->b->c->d, should print a -> b -> c -> d -> f \n");
	insert_song(song1, song6);
	print_list(song1);

	//testing inserting in middle
	printf("\ntesting insert e in middle of a->b->c->d->f, should print a -> b -> c -> d -> e -> f \n");
	insert_song(song1, song5);
	print_list(song1);

	//free_list(song1); //this doesn't work

	//testing find random
	find_random(song1);
	printf("\n");
	print_list(song1); //doesnt work

	*/

	//more thorough testing
	struct song_node *nas_song1 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *nas_song2 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *jayz_song1 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *jayz_song2 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *radiohead_song1 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *nirvana_song1 = (struct song_node *)malloc(sizeof(struct song_node));

	initialize_song(nas_song1, "Nas", "NY State of Mind");  //song 3
	initialize_song(nas_song2, "Nas", "The World is Yours"); //song 4
	initialize_song(jayz_song1, "Jay Z", "Ninety Nine Problems"); //song 2
	initialize_song(jayz_song2, "Jay Z", "Dirt Off Your Shoulder"); //song 1
	initialize_song(radiohead_song1, "Radiohead", "No Surprises"); //song 6
	initialize_song(nirvana_song1, "Nirvana", "Lithium"); //song 5

	/** order in which we insert songs matter
	if (compare_nodes(nas_song1, nas_song2) < 0){
	 	insert_song(nas_song1, nas_song2);
		first_song = nas_song1; }
	else{
		insert_song(nas_song2, nas_song1);
	 	first_song = nas_song2; } */

	/**
	if (compare_nodes(first_song, jayz_song1) > 0){
		insert_song(jayz_song1, first_song);
		first_song = jayz_song1; }
	else{
		insert_song(first_song, jayz_song1); }

	if (compare_nodes(first_song, jayz_song2) > 0){
		insert_song(jayz_song2, first_song);
		first_song = jayz_song2; }
	else{
		insert_song(first_song, jayz_song2); } */

	//list parameter should be the first song to work
	insert_song(jayz_song2, jayz_song1);
	insert_song(jayz_song2, nas_song1);
	insert_song(jayz_song2, nas_song2);
	insert_song(jayz_song2, nirvana_song1);
	insert_song(jayz_song2, radiohead_song1);

	find_song(jayz_song2, "NY State of Mind");
	find_song(jayz_song2, "Lithium");

	find_artist(jayz_song2, "Radiohead");
	find_artist(jayz_song2, "Nas");

}
