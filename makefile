all: song_lists.c music_library.c
	gcc music_library.c song_lists.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
