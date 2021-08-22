CPP = g++
COMPILE = $(CPP) -c
CPPFLAGS = -I.

default: all

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $<

main: main.o 
	$(CPP) $(CPPFLAGS) main.o -o main
	./main
	rm -f main

test:
	$(CPP) $(CPPFLAGS) test.cpp -o test
	./test
	rm -f test

all: main test clean

clean:
	rm -f *.o
