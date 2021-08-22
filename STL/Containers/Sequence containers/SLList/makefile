CPP = g++
CPPFLAGS = -I .

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: main.o
	$(CPP) $(CPPFLAGS) main.o -o main
	./main

test:
	$(CPP) $(CPPFLAGS) test.cpp -o test
	./test

all: main test clean
	rm -f main test

clean:
	rm -f *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
