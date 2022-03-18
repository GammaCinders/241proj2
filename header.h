#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef HEADER
#define HEADER

struct Item {
	char *name;
	char *unit;
	int price;
	int quantity;	
	struct Item *next;
};



/* All of the Link List related functions (linkList.c) (that cannot crash) */

void delNodeAfter(struct Item *node);
struct Item *initInventory(); 
void printInventory(struct Item *inventoryHead);
void wipeInventory(struct Item *head);



/* All of the Link List related functions (linkList.c) (that can crash) */

void addItem(struct Item *inventoryHead, char *name, char *unit, int price, int quantity);				   
struct Item *getNodeBefore(struct Item *inventoryHead, char *productName); 



/* All of the main display / input functions (main.c) */

void handleInput();
void printMenu();



/* All of file control functions (fileControl.c) */

void saveToFile(struct Item *header);



#endif
