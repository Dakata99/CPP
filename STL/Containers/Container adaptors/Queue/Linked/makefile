CPP = g++
COMPILE = $(CPP) -c
CPPFLAGS = -I.

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $<

main: main.o Queue.o
	$(CPP) $(CPPFLAGS) main.o Queue.o -o a.out
 
all: main clean

clean:
	rm *.o
