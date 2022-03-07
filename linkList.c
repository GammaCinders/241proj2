#include"header.h"

struct Item *initInventory() {
	return (struct Item*)malloc(sizeof(struct Item));
}

void wipeInventory(struct Item *head) {
	struct Item *nextItem = head->next;

	while(nextItem != NULL) {
		free(head->name);
		free(head->unit);
		free(head);
		head = nextItem;
		nextItem= head->next;
	}

	free(head->name);
	free(head->unit);
	free(head);
}

void addItem(struct Item *inventoryHead, char *name, char *unit, int price, int quantity) {
	struct Item *newItem = (struct Item*)malloc(sizeof(struct Item));
	newItem->name = name;
	newItem->unit = unit;
	newItem->price = price;
	newItem->quantity = quantity;

	newItem->next = inventoryHead->next;
	inventoryHead->next = newItem;
}

struct Item *search(struct Item *inventoryHead, char *productName) {
	inventoryHead = inventoryHead->next;	
	while(inventoryHead != NULL) {
		if(strcmp(productName, inventoryHead->name) == 0) {
			return inventoryHead;
		}

		inventoryHead = inventoryHead->next;	
	}

	return NULL;
}

void printInventory(struct Item *inventoryHead) {
	while(inventoryHead->next != NULL) {
		inventoryHead = inventoryHead->next;
		printf("%s %s %d %d\n", inventoryHead->name, inventoryHead->unit, inventoryHead->price, inventoryHead->quantity);
	}
}
