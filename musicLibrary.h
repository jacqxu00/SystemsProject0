struct song_node{ 
	char name[256];
	char artist[256];
	struct song_node *next;
};

/* declare all functions */
void print_list(struct song_node * list);
struct song_node * insert_front(struct song_node * list, char * artist, char * song);
struct song_node * free_list(struct song_node * list);
int compare_nodes(struct song_node * a, struct song_node * b);
struct song_node * find_song(struct song_node * list);
struct song_node * find_artist(struct song_node * list);
struct song_node * find_random();
void remove_song(struct song_node * list);
struct song_node * insert_song(struct song_node * list, char * artist, char * song);
