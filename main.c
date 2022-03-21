#include"header.h"

char *menuOptions[] = {	"Create an empty list",	"Insert a product", 
			"Delete a product", 	"Delete the entire list",
			"Search a product", 	"Display products in the list",
			"Purchase a product", 	"Sell a product",
			"Save to file", 	"Exit"};

char searchName[20];
int chosenOption = -1;
struct Item *inventoryHead = NULL;
struct Item *searcher = NULL;

void main() {
	printMenu();

	while(chosenOption != 0) {
		scanf("%d", &chosenOption);
		handleInput(chosenOption);
	}

	if(inventoryHead != NULL) {
		wipeInventory(inventoryHead);
	}

	return;
}


void handleInput(int option) {
	if(option <= 0 || option > 9) {
		return;
	}

	if(option >= 2 && option <= 9 && inventoryHead == NULL) {
		printf("Must create list with option 1 first\n");
		return;
	}

	switch(option) {
		case 1: //Create empty list
			wipeInventory(inventoryHead); 
			inventoryHead = initInventory();	

			break;

		case 2: //Add new item
			char *name = (char*)malloc(sizeof(char)*20);
			char *unit = (char*)malloc(sizeof(char)*20);
			int price, quantity;

			printf("Enter new item information in following format: \"name unit price quantity\"\n");
			scanf("%s %s %d %d", name, unit, &price, &quantity); 

			if(getNodeBefore(inventoryHead, name) != NULL) {
				printf("%s already exists\n");
				free(name);
				free(unit);
				break;
			}

			if(price <= 0 || quantity <= 0) {
				free(name);
				free(unit);
				printf("Invalid price or quantity\n");
				break;
			}

			addItem(inventoryHead, name, unit, price, quantity);

			break;

		case 3: //Remove item
			printf("Please enter the product name\n");
			scanf("%s", searchName);

			delNodeAfter(getNodeBefore(inventoryHead, searchName));

			break;

		case 4: //Wipe list
			wipeInventory(inventoryHead);
			inventoryHead = NULL;
			printf("Product list wiped\n");

			break;

		case 5: //Search for product
			printf("Please enter the product name\n");
			scanf("%s", searchName);

			searcher = getNodeBefore(inventoryHead, searchName);

			if(searcher != NULL) {
				searcher = searcher->next;
				printf("Product found: %s %s %d %d\n", searcher->name, searcher->unit, searcher->price, searcher->quantity);
			} else {
				printf("Product not found\n");
			}

			break;
		
		case 6: //Display all products
			printInventory(inventoryHead);	

			break;

		case 7: //purchase a product
			printf("Please enter the name of the product bought\n");
			scanf("%s", searchName);

			searcher = getNodeBefore(inventoryHead, searchName);

			if(searcher != NULL) {
				searcher = searcher->next;
				searcher->quantity++;
				printf("%s quantity increased\n", searcher->name);
			} else {
				printf("Product not found\n");
			}

			break;

		case 8: //sell product
			printf("Please enter the name of the product sold\n");
			scanf("%s", searchName);

			searcher = getNodeBefore(inventoryHead, searchName);

			if(searcher != NULL) {
				searcher->next->quantity--;
				if(searcher->next->quantity <= 0) {
					delNodeAfter(searcher);
					printf("Product is all gone and removed from list\n");
				} else {
					printf("%s quantity decreased\n");
				}
			} else {
				printf("Product not found\n");
			}

			break;

		case 9: //save to file
			saveToFile(inventoryHead);

			break;
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

