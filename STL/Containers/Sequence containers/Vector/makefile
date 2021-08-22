CPP = g++
CPPFLAGS = -I .

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := main.o

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o main
	./main

test: 
	$(CPP) $(CPPFLAGS) tests.cpp -o test
	./test

all: main test clean
	rm -f main test

clean:
	rm -f *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
