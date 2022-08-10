all: main.o
	gcc main.o operations.o -o p3	

run: all
	./p3 "data"

main.o: operations.o main.c
	gcc -c main.c

operations.o: operations.c
	gcc -c operations.c

clean:
	rm -f *.o p3
