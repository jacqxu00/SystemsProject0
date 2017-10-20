/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include "song_lists.h"
#include "music_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initialize_playlist(){
	int i = 0;
	while (i < 26){
		playlist[i] = NULL;
		i ++; }
}

// Converts ASCII character into an integer value to use to get index for the playlist array
int letter_index(char letter) {
	int ans = letter - 65;
	return ans;
	// letter 'A' = 0, 'B' = 1, etc
}

char first_letter(char * string) {
	return string[0];
}

// Adds song nodes
void add_song(char *person, char *song) {

	int i = letter_index(first_letter(person));
	if (playlist[i] == NULL){
		playlist[i] = initialize_song(person,song); }
	else{
		playlist[i] = insert_song(playlist[i], person, song); }
}

// Print out the entire library
void print_all() {
	int i;
	for (i = 0; i < 26; i++) {
		if (playlist[i]){
			printf("%c table: ", 'A' + i);
			print_list(playlist[i]);
		  printf("\n\n"); }
		}
}

/**
// Searches for a song given song and artist name
// Returns: a pointer to the song
struct song_node * search_song(struct song_node * playlist[26], char * song, char * person) {
	int i = letter_index(first_letter(person));
	return find_node(playlist[i], song, person);
}

// Search for an artist
// Returns: a pointer to the first song of the artist
struct song_node * search_artist(struct song_node * playlist[26], char * person) {
	int i = letter_index(first_letter(person));
	return find_artist(playlist[i], person);
}

// Print out all the entries under a certain letter
void print_letter(struct song_node * playlist[26], char letter) {
	int i = letter_index(letter);
	print_list(playlist[i]);
}

// Print out all the songs of a certain artist
void print_artist(struct song_node * playlist[26], char * person) {
	int i = letter_index(first_letter(person));
	struct song_node * charlist = playlist[i];
	while (charlist) {
		if (strcmp(person,charlist->artist)==0) {
			printf("(%s: %s) ", charlist->artist, charlist->name);
		}
		charlist = charlist->next;
	}
}



// Print out a series of randomly chosen songs
void shuffle(struct song_node * playlist[26], int n) {
	int i;
	for (i = 0; i < n; i++){
		int random_int = rand() % 26;
		find_random(playlist[random_int]); }
}

// Delete a song
void delete_song(struct song_node * playlist[26], char * person, char * song) {
	int i = letter_index(first_letter(person));
	struct song_node * new = (struct song_node *) malloc(sizeof(struct song_node));
	initialize_song(new, person, song);
	remove_song(playlist[i], new);

}

// Delete all the nodes
void delete_all(struct song_node * playlist[26]) {
	int i;
	for (i = 0; i < 26; i++) {
		struct song_node * current = playlist[i];
		while (current) {
			struct song_node * temp = remove_song(current,current);
			current = temp;
		}
	}
} */

int main() {

	/**
	//testing letter_index
	printf("Index of A: %d\n", letter_index('A'));
	printf("Index of N: %d\n", letter_index('N'));
	printf("Index of Z: %d\n", letter_index('Z'));

	//testing first_letter
	char s1[12] = "Hello";
	char s2[12] = "Alphabet";
	printf("\nFirst letter testing:\n");
	printf("hello: %c\n",first_letter(s1));
	printf("alphabet: %c\n",first_letter(s2)); */

	//testing print_library
	initialize_playlist();
	add_song("Biggie", "Juicy");
	add_song("Tupac", "Changes");
	print_all();

	/**
	add_song(nas_song1);
	add_song(nas_song2);
	add_song(nirvana_song1);
	add_song(radiohead_song1); */
	//print_all(playlist);
}
