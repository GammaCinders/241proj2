#include"header.h"

struct Item *initInventory() {
	return (struct Item*)malloc(sizeof(struct Item));
}

void wipeInventory(struct Item *head) {
	struct Item *next = head->next;

	while(next != NULL) {
		free(head);
		head = next;
		next = next->next;
	} free(head);
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

void printInventory(struct Item *inventoryHead) {

	while(inventoryHead->next != NULL) {
		inventoryHead = inventoryHead->next;
		printf("%s %s %d %d\n", inventoryHead->name, inventoryHead->unit, inventoryHead->price, inventoryHead->quantity);
	}
	
}
