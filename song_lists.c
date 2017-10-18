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
	while (list) {
		printf(" song: %s \n ", list->name);
		printf(" artist: %s \n", list->artist);
		list = list->next;
	}
	printf("NULL\n");
}

// takes a pointer to the existing list and the data to be added, creates a new node and puts it at the beginning of the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_front(struct song_node * list, char * person, char * song) {
	struct song_node *ans = (struct song_node *) malloc(sizeof(struct song_node));
	strcpy(ans->artist, person);
	strcpy(ans->name, song);

	ans->next = list;
	return ans;
}

struct song_node * insert_end(struct song_node * list, char * person, char *song){
	struct song_node *ans = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(ans->artist, person);
	strcpy(ans->name, song);

	while(list){
		list = list->next; }

	list->next = ans;
	return ans;

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

// takes a pointer to the existing list and the data to be added, creates a new node and alphabetizes it in the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_song(struct song_node * list, char * person, char * song) {
	struct song_node *copy = list; //so we can return beginning of the list later

	struct song_node * insert = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(insert->artist, person);
	strcpy(insert->name, song);

	//while the current song's artist and name is  not "less" than the song we want to insert
	while (list && compare_nodes(list->next, insert) != 0 && compare_nodes(list, insert) != 0){
		//case 1: if insert should be first song in list
		if (compare_nodes(insert,list) < 0){
			insert_front(list, person, song); }

		//case 2: if insert should be the last song in list
		else if(list->next == NULL && compare_nodes(insert,list) > 0){
			list->next = insert; }

		//case 3: add in middle
		else if (compare_nodes(insert,list) > 0 && compare_nodes(insert, list->next) < 0){
			insert->next = list->next;
			list->next = insert; }

			list = list->next;
		}

	return copy; //this is beginning of list

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
	int r;
	for (r = rand() % l; r > 0; r--) {
		list = list->next;
	}
	return list;
}

// takes a pointer to the existing list and a node to be removed, goes through entire list until node matches and removes it;
void remove_song(struct song_node * list, struct song_node * one) {
}

//NEW, to make testing easier? this doesn't work tho, optional
/**
struct song_node * construct_song(struct song_node * new_node, char * person, char * song){
	new_node = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(new_node->artist, person);
	strcpy(new_node->name, song);
	return new_node;
} */

int main(){
	//simple testing
	struct song_node *songBiggie = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *songTupac = (struct song_node *)malloc(sizeof(struct song_node));

	strcpy(songBiggie->artist, "Biggie");
	strcpy(songBiggie->name, "Juicy");
	strcpy(songTupac->artist, "Tupac");
	strcpy(songTupac->name, "Changes");

	printf("compare songBiggie to songTupac: %d \n", compare_nodes(songBiggie, songTupac) ); //should return -1, "Biggie" before "Tupac"

	//i wanna get rid of this ugly piece, we should write construct funtion later maybe
	struct song_node *song1 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song2 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song3 = (struct song_node *)malloc(sizeof(struct song_node));
	struct song_node *song4 = (struct song_node *)malloc(sizeof(struct song_node));

	strcpy(song1->artist, "A");
	strcpy(song1->name, "a song");
	strcpy(song2->artist, "B");
	strcpy(song2->name, "b song");

	strcpy(song3->artist, "C");
	strcpy(song3->name, "c song");
	strcpy(song4->artist, "D");
	strcpy(song4->name, "d song");


	//testing inserting in middle
	song1->next = song3;// A: a song -> C: c song
	insert_song(song1, song2->artist, song2->name); //we want A: a song -> B: b song -> C: c song
	print_list(song1); //works

	//testing inserting in end
	insert_song(song4, song4->artist, song4->name); //inserting d song after c song
	print_list(song1);


}
