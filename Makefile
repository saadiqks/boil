CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all

boil: boil.o
	$(CC) -o boil boil.o 

boil.o: boil.c
	$(CC) $(CFLAGS) -c boil.c

clean:
	rm -f *.o boil