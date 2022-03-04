program: linkList.o main.o
	gcc linkList.o main.o -o program

linkList.o: linkList.c header.h
	gcc -c linkList.c

main.o: main.c header.h
	gcc -c main.c

clean:
	rm -f *.o
