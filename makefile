program: linkList.o main.o fileControl.o
	gcc linkList.o main.o fileControl.o -o program

linkList.o: linkList.c header.h
	gcc -c linkList.c

main.o: main.c header.h
	gcc -c main.c

fileControl.o: fileControl.c header.h
	gcc -c fileControl.c

clean:
	rm -f *.o
