#include"header.h"

void delNodeAfter(struct Item *node) {
	if(node == NULL || node->next == NULL) {
		return;
	}


	struct Item *toBeDel = node->next;
	node->next = toBeDel->next;
	
	printf("%s deleted from list\n", toBeDel->name);
	free(toBeDel->name);
	free(toBeDel->unit);
	free(toBeDel);
}

/* Should always be called first */
struct Item *initInventory() {
	struct Item *newHead = (struct Item*)malloc(sizeof(struct Item));
	newHead->next = NULL;
	return newHead;
}

void printInventory(struct Item *inventoryHead) {
	if(inventoryHead == NULL || inventoryHead->next == NULL) {
		printf("No Items to print\n");
		return;
	}

	while(inventoryHead->next != NULL) {
		inventoryHead = inventoryHead->next;
		printf("%s %s %d %d\n", inventoryHead->name, inventoryHead->unit, inventoryHead->price, inventoryHead->quantity);
	}
}

void wipeInventory(struct Item *head) {
	if(head == NULL) {
		return;
	}

	while(head->next != NULL) {
		delNodeAfter(head);
	}

	free(head);
}



/* ALL METHODS BELOW WILL CRASH THE PROGRAM IF CALLED BEFORE initInventory() */

void addItem(struct Item *inventoryHead, char *name, char *unit, int price, int quantity) {
	struct Item *newItem = (struct Item*)malloc(sizeof(struct Item));
	newItem->name = name;
	newItem->unit = unit;
	newItem->price = price;
	newItem->quantity = quantity;

	newItem->next = inventoryHead->next;
	inventoryHead->next = newItem;
}

struct Item *getNodeBefore(struct Item *inventoryHead, char *productName) {
	while(inventoryHead->next != NULL) {
		if(!strcmp(productName, inventoryHead->next->name)) {
			return inventoryHead;
		}

		inventoryHead = inventoryHead->next;	
	}

	return NULL;
}

