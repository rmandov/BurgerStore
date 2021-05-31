#include <stdio.h>
#include <stdlib.h>

#define SIZE 5


// Structure for burgers
struct burger {
	const char *name;
	int number;
	float price;
};
typedef struct burger Burger;

void show(const Burger * const B) {
	printf("\t**** COLOR - BURGERS ****\n");
	printf("//Burger\t//Cantidad Disponible\t//Precio\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%i. %s\t\t%i\t\t$%.2f\n", i + 1, B[i].name, B[i].number, B[i].price);
	}
}

void fillStore(Burger * const B,const char * C[]) {
	int azar = 2;

	for (size_t i = 0; i < SIZE; i++) {
		B[i].name = C[i];
		B[i].number = azar * 5;
		B[i].price = 13.5 + i;
		azar++;
	}
}

int main() {

	// Create the burgers for my store and structs for store and shopping cart.
	const char* name[] = { "Black", "Green", "Yellow", "Blue ", "Orange"};
	
	
	Burger newBurgers[SIZE];

	// Fill store with burgers.
	fillStore(newBurgers,name);



	show(newBurgers);



	return 0;
}