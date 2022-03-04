#include<stdio.h>
#include<stdlib.h>

struct Item {
	char *name;
	char *unit;
	int price;
	int quantity;	
	struct *Item next;
};

/* starts an empty LL to add Items to for store */
struct *Item initInventory();

/* Not sure how this will work yet
struct *Item addItem(struct Item newItem);
*/

/* Free all of inventory from memory */
void wipeInventory(struct *Item head);
