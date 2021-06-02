#include <stdio.h>
#include <stdlib.h>
// for Files
#include <string.h>



// Struct for burgers
struct burger {
	//const char *name;
	char name[20];
	double price;
	int number;
};
typedef struct burger Burger;





void show(const Burger* const B) {
	printf("\t**** COLOR - BURGERS ****\n");
	printf("//Burger\t//Cantidad Disponible\t//Precio\n\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%i. %s\t\t%i\t\t$%.2f\n", i + 1, B[i].name, B[i].number, B[i].price);
	}
}