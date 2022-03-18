#include"header.h"

//TODO project instructions don't talk about naming the file so...
//This will only be able to save one file though, and it will be overwritten each time
void saveToFile(struct Item *header) {
	if(header == NULL || header->next == NULL) {
		printf("Nothing to save\n");
		return;
	}

	header = header->next;
	FILE *out = fopen("productSave.txt", "w");
	
	while(header != NULL) {
		fprintf(out, "%s %s %d %d\n", header->name, header->unit, header->price, header->quantity);
		header = header->next;
	}
	
	fclose(out);
	printf("Current product information saved to file \"%s\"\n", "productSave.txt");
}

/* TODO just realized this doesn't exist
void loadFromFile(Item *header) {
	header = header->next;
	FILE *in = fopen(saveFileName, "r");
	
	while(header != NULL) {
		header = header->next;
	}
}
*/
