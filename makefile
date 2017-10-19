all: song_lists.c music_library.c
	gcc song_lists.c music_library.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
