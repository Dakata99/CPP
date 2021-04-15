CC = g++
COMPILE = $(CC) -c
CFLAGS = -I.

%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o Vector.o Iterator.o Tests.o
	$(CC) main.o Vector.o Iterator.o Tests.o -o a.out
	
all: main clean

clean:
	rm *.o
