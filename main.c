#include <stdio.h>
#include <stdlib.h>


// Structure for burgers
struct Burger {
	char name[20];
	int number;
	float price;
};

void show(struct Burger B[]) {
	printf("\t\tCOLOR - BURGERS\n");
	printf("//Burger\t//Cantidad Disponible\t//Precio\n\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%i. %s\t\t%i\t\t$%.2f\n", i + 1, (B+i)->name, (B+i)->number, (B + i)->price);
	}
}

void fillStore(struct Burger B[], char* C[]) {
	int azar = 2;

	for (int i = 0; i < 5; i++) {
		(B + i)->number = azar * 5;
		(B + i)->price = azar * 13.25;
		strcpy((B+i)->name, *(C + i));
		azar++;
	}
}

int main() {

	// Create the burgers for my store and structs for store and shopping cart.
	char* colors[5] = { "Black", "Green", "Yellow", "Blue ", "Orange" };
	struct Burger newBurgers[5];
	struct Burger shoppingCart[5];

	// Fill store with burgers.
	fillStore(newBurgers,colors);


	show(newBurgers);


	return 0;
}