CPP = g++
COMPILE = $(CPP) -c
CPPFLAGS = -I.

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

main: main.o Vector.o Iterator.o Tests.o
	$(CPP) $(CPPFLAGS) main.o Vector.o Iterator.o Tests.o -o a.out
 
all: main clean

clean:
	rm *.o
