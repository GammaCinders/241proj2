#include"header.h"

char *menuOptions[] = {	"Create an empty list",	"Insert a product", 
			"Delete a product", 	"Delete the entire list",
			"Search a product", 	"Display products in the list",
			"Purchase a product", 	"Sell a product",
			"Save to file", 	"Exit"};

int isInventoryInit = 0;
int chosenOption = -1;

struct Item *inventoryHead;

void main() {

	printMenu();

	while(chosenOption != 0) {
		scanf("%d", &chosenOption);
		handleInput(chosenOption);

		printInventory(inventoryHead);	
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
			char *name, *unit;
			int price, quantity;
			printf("Enter new item information in following format: \"name unit price quantity\"\n");
			
			/* TODO this shitter line right here wont work, idk why
			 * it refuses to scan in values and instead they just stay uninitialized 
			 */
			scanf("%s %s %d %d", name, unit, &price, &quantity); 
			addItem(inventoryHead, name, unit, price, quantity);
			break;

		//case 3: //Remove item
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
