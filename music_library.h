
int letter_index(char letter);
char first_letter(char * string);
void add_song(struct song_node * playlist[26], struct song_node * insert);
struct song_node * search_song(struct song_node * playlist[26], char * song, char * person);
struct song_node * search_artist(struct song_node * playlist[26], char * person);
void print_letter(struct song_node * playlist[26], char letter);
void print_artist(struct song_node * playlist[26], char * person);
void print_all(struct song_node * playlist[26]);
void shuffle(struct song_node * playlist[26], int n);
void delete_song(struct song_node * playlist[26], char * person, char * song);
void delete_all(struct song_node * playlist[26]);
