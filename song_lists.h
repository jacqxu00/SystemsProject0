struct song_node{
	char name[256];
	char artist[256];
	struct song_node *next;
};

/* declare all functions */
int compare_nodes(struct song_node * a, struct song_node * b);
struct song_node * insert_front(struct song_node * list, struct song_node * insert);
struct song_node * insert_end(struct song_node * list, struct song_node * insert);
struct song_node * insert_song(struct song_node * list, struct song_node * insert);
struct song_node * free_list(struct song_node * list);
struct song_node * find_song(struct song_node * list, char * song, char * person);
struct song_node * find_artist(struct song_node * list, char * person);
struct song_node * initialize_song(struct song_node * node, char * person, char * song);
int length_of(struct song_node * list);
struct song_node * find_random();
struct song_node * remove_song(struct song_node * list, struct song_node * one);
