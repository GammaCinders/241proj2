#include"header.h"

struct *Item initInventory() {
	return (struct *Item)malloc(sizeof(struct Item));
}

void wipeInventory(struct *Item head) {
	struct *Item next = head->next;

	while(next != NULL) {
		free(head);
		head = next;
		next = next->next;
	} free(head);
}
