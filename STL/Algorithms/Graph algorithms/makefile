CPP = g++
CPPFLAGS = -I .

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o main
	./main
	rm -f main

test:
	$(CPP) $(CPPFLAGS) test.cpp -o test
	./test
	rm -f test

all: main test clean

clean:
	rm -f *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
