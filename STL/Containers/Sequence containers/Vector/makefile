CC = g++
COMPILE = $(CC)
CFLAGS = -I.

.cpp.o:
	$(COMPILE) $(CFLAGS) $< -o $@
	
main: Vector.h Iterator.h Tests.h Vector.o Iterator.o Tests.o main.o
	$(LINK) Vector.o Iterator.o Tests.o main.o -o $@
	
all: main

clean:
	rm *.o
