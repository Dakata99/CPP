CPP = g++
CPPFLAGS = -I.

default = all

%.o:	%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

main:	String.o Tests.o main.o
	$(CPP) $(CPPFLAGS) String.o Tests.o main.o -o a.out  
	
all:	main clean
	
clean:
	rm -f *.o
