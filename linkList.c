#include"header.h"

/* Should always be called first */
struct Item *initInventory() {
	struct Item *newHead = (struct Item*)malloc(sizeof(struct Item));
	newHead->next = NULL;
	return newHead;
}

void delNodeAfter(struct Item *node) {
	if(node == NULL || node->next == NULL) {
		return;
	}

	struct Item *toBeDel = node->next;
	node->next = toBeDel->next;
	free(toBeDel->name);
	free(toBeDel->unit);
	free(toBeDel);
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

void printInventory(struct Item *inventoryHead) {
	if(inventoryHead == NULL || inventoryHead->next == NULL) {
		return;
	}

	while(inventoryHead->next != NULL) {
		inventoryHead = inventoryHead->next;
		printf("%s %s %d %d\n", inventoryHead->name, inventoryHead->unit, inventoryHead->price, inventoryHead->quantity);
	}
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

//TODO make this always return the node before the desired one so that it can be used for insert and delete
struct Item *getNodeBefore(struct Item *inventoryHead, char *productName) {
	while(inventoryHead->next != NULL) {
		//TODO make sure this works otherwise do '== 0'
		if(!strcmp(productName, inventoryHead->next->name)) {
			return inventoryHead;
		}

		inventoryHead = inventoryHead->next;	
	}

	return NULL;
}

