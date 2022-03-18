program: main.o linkList.o fileControl.o
	gcc linkList.o main.o fileControl.o -o program

main.o: main.c header.h
	gcc -c main.c

linkList.o: linkList.c header.h
	gcc -c linkList.c

fileControl.o: fileControl.c header.h
	gcc -c fileControl.c

clean:
	rm -f *.o
