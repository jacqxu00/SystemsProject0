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
void add_song(struct song_node * playlist[26], struct song_node * insert) {
	int i = letter_index(first_letter(insert->artist));
	insert_song(playlist[i],insert);
}

// Searches for a song given song and artist name
// Returns: a pointer to the song
struct song_node * search_song(struct song_node * playlist[26], char * song, char * person) {
	int i = letter_index(first_letter(person));
	return find_song(playlist[i], song, person);
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

// Print out the entire library
void print_all(struct song_node * playlist[26]) {
	int i;
	for (i = 0; i < 26; i++) {
		print_list(playlist[i]);
	}
}

// Shuffle - print out a series of randomly chosen songs
void shuffle(struct song_node * playlist[26]) {
	//QUESTION: do they not repeat
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
}

int main() {
	
	//testing letter_index
	printf("Index of a: %d\n", letter_index('a'));
	printf("Index of n: %d\n", letter_index('n'));
	printf("Index of z: %d\n", letter_index('z'));
	
	//testing first_letter
	char s1[12] = "hello";
	char s2[12] = "alphabet";
	printf("\nFirst letter testing:\n");
	printf("hello: %c\n",first_letter(s1));
	printf("alphabet: %c\n",first_letter(s2));
	
}


