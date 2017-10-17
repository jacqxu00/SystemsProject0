all: song_lists.c
  gcc -o song_lists.exe song_lists.c

main.o: song_lists.c
  gcc song_lists.c

clean:
  rm *.o
  rm *~

run: all
  ./song_lists.exe
