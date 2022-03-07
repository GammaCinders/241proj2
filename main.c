#include"header.h"

char *menuOptions[] = {	"Create an empty list",	"Insert a product", 
			"Delete a product", 	"Delete the entire list",
			"Search a product", 	"Display products in the list",
			"Purchase a product", 	"Sell a product",
			"Save to file", 	"Exit"};

char searchName[20];
int isInventoryInit = 0;
int chosenOption = -1;
struct Item *inventoryHead;
struct Item *searcher;

void main() {

	printMenu();

	while(chosenOption != 0) {
		scanf("%d", &chosenOption);
		handleInput(chosenOption);
	}

	wipeInventory(inventoryHead);
	return;
}


void handleInput(int option) {

	if(option <= 0 || option > 9) {
		return;
		//TODO maybe something or just do nothing? idk
	}

	switch(option) {

		case 1: //Create empty list
			//TODO after i create size/len method for LL then do if size<1 then wipeInventory
			//wipeInventory(inventoryHead); //no memory leaks here
			inventoryHead = initInventory();	
			break;

		case 2: //Add new item
			char *name = (char*)malloc(sizeof(char)*20);
			char *unit = (char*)malloc(sizeof(char)*20);
			int price, quantity;
			printf("Enter new item information in following format: \"name unit price quantity\"\n");
			scanf("%s %s %d %d", name, unit, &price, &quantity); 
			addItem(inventoryHead, name, unit, price, quantity);
			break;

		case 3: //Remove item
			struct Item *beforeSearcher = inventoryHead;
			printf("Please enter the product name\n");
			scanf("%s", searchName);
			
			searcher = search(inventoryHead, searchName);
			if(searcher != NULL) {
				//TODO make sure this works by testing
				while(beforeSearcher->next != searcher) {
					beforeSearcher = beforeSearcher->next;	
				}
				beforeSearcher->next = searcher->next;
				free(searcher->name);
				free(searcher->unit);
				free(searcher);
				printf("Product removed\n");
			} else {
				printf("Product not found\n");
			}

			break;

		case 4: //Wipe list
			wipeInventory(inventoryHead);
			inventoryHead = NULL;
			break;

		case 5: //Search for product
			printf("Please enter the product name\n");
			scanf("%s", searchName);

			searcher = search(inventoryHead, searchName);
			if(searcher != NULL) {
				printf("Product found: %s %s %d %d\n", searcher->name, searcher->unit, searcher->price, searcher->quantity);
			} else {
				printf("Product not found\n");
			}

			break;
		
		case 6: //Display all products
			printInventory(inventoryHead);	
			break;

		//case 7: //purchase a product
		//case 8: //sell product
		//case 9: //save to file
	}
}

void printMenu() {

	printf("\n");
	for(int i=0; i<9; i++) {
		char spacer = i%2 ? '\n' : '\t';
		printf("%d :   %s%c%c", i+1, menuOptions[i], strlen(menuOptions[i]) > strlen(menuOptions[2]) ? '\0' : '\t', spacer);
	}
		
	printf("0 :   %s\n\n", menuOptions[9]);
}
