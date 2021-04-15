CC = g++
CFLAGS = -I.

%.o: %.cpp %.h 
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o String.o Tests.o
	$(CC) -o main main.o String.o Tests.o 
	
all: main
	
clean:
	rm *.o
