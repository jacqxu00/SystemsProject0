/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "song_lists.c"
#include "music_library.h"

// Converts ASCII character into an integer value to use to get index for the playlist array
int letter_index(char letter) {
	int ans = letter - 'a';
	return ans;
	// letter 'a' = 0, 'b' = 1, etc 
}

char first_letter(char * string) {
	return string[0];
}

// Adds song nodes
void add_song(struct song_node playlist[26], struct song_node * insert) {
}

// Searches for a song given song and artist name
// Returns: a pointer to the song
struct song_node * search_song(struct song_node playlist[26], char * song, char * person) {
	return NULL;
}


// Search for an artist
// Returns: a pointer to the first song of the artist
struct song_node * search_artist(struct song_node playlist[26], char * person) {
	return NULL;
}

// Print out all the entries under a certain letter
void print_letter(struct song_node playlist[26], char letter) {
	
}

// Print out all the songs of a certain artist
void print_artist(struct song_node playlist[26], char * person) {
	
}

// Print out the entire library
void print_all(struct song_node playlist[26]) {
	
}

// Shuffle - print out a series of randomly chosen songs
void shuffle(struct song_node playlist[26]) {
	
}

// Delete a song
void delete_song(struct song_node playlist[26], struct song_node * one) {
	
}

// Delete all the nodes
void delete_all(struct song_node playlist[26]) {
	
}

int main() {
	
	//testing letter_index
	printf("Index of a: %d\n", letter_index('a'));
	printf("Index of n: %d\n", letter_index('n'));
	printf("Index of z: %d\n", letter_index('z'));
	
	//testing first_letter
	char s1[12] = "hello";
	char s2[12] = "alphabet";
	printf("First letter testing\n");
	printf("hello: %c\n",first_letter(s1));
	printf("alphabet: %c\n",first_letter(s2));
}


