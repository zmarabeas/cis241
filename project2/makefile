all: main.o
	gcc main.o cipher.o -o project2

test: all
	./project2 e "goodmorning" data.txt data.out
	./project2 d "goodmorning" data.out data.bak
	diff -s data.txt data.bak

main.o: cipher.o main.c
	gcc -c main.c

cipher.o: cipher.c
	gcc -c cipher.c

clean:
	rm -f *.o project2 *.out *.bak
