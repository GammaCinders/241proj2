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

/* Not sure how this will work yet
struct *Item addItem(struct Item newItem);
*/

/* All of the Link List related functions */
struct Item *initInventory(); // Creates and returns empty head Item 
void wipeInventory(struct Item *head); //Free inventory from memory
void addItem(struct Item *inventoryHead, char *name, char *unit, int price, int quantity); //adds new item after head				   
void printInventory(struct Item *inventoryHead);

/* All of the main display / input functions (in main) */
void handleInput();
void printMenu();

#endif
