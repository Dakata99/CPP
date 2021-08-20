CPP = g++
CPPFLAGS = -I .

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: String.o main.o
	$(CPP) $(CPPFLAGS) String.o main.o -o main
	./main

test:
	$(CPP) $(CPPFLAGS) String.cpp tests.cpp -o test
	./test

all: main test clean
	rm -f main test

clean:
	rm -f *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
