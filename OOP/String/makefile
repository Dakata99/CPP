CC = g++
CFLAGS = -I.

%.o: %.cpp %.h 
	$(CC) $(CFLAGS) -c -o $@ $<

main: main.o String.o Tests.o
	$(CC) main.o String.o Tests.o -o a.out  
	
all: main clean
	
clean:
	rm *.o
