#include"header.h"

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

