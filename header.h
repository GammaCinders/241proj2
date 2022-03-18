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
//This returns the pointer to the node before the node with the product name
//Do nodeBefore->next to get the actual node you searched for
struct Item *getNodeBefore(struct Item *inventoryHead, char *productName); //returns pointer to item in LL with arg name (null if not found)
//delete (free) the node after the given node (including name and unit)
void delNodeAfter(struct Item *node);

/* All of the main display / input functions (in main) */
void handleInput();
void printMenu();

/* All of file control functions */
//TODO update these later
void saveToFile(struct Item *header);
//void loadFromFile();

#endif
