#include <stdio.h>
#include <stdlib.h>
// for Files
#include <errno.h>
#include <string.h>

#define SIZE 5


// Struct for burgers
struct burger {
	double code;
	char name[20];
	double price;
	double number;
};
typedef struct burger Burger;

struct name {
	char name[20];
};
typedef struct name Name;




// show kind of burgers
void show(const Burger * const B) {
	printf("\t**** COLOR - BURGERS ****\n");
	printf("//Burger\t//Cantidad Disponible\t//Precio\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%.0f %s\t\t%.0f\t\t$%.2f\n", B[i].code, B[i].name, B[i].number, B[i].price);
	}
}



// Fill the struct, 1. Security, 2. for real data
void fillStore(Burger * const B) {

	double code = -1;
	char *name = "empty";
	double price = -1;
	double number = -1;

	for (size_t i = 0; i < SIZE; i++) {
		B[i].code = code;
		strcpy_s(B[i].name, 20, name);
		//B[i].name = name;
		B[i].number = number;
		B[i].price = price;
	}
}

// Close FILE
void closeFile(FILE* file) {
	errno_t err;
	if (file)
	{
		err = fclose(file);
		if (err == 0)
		{
			printf("The file was closed\n");
		}
		else
		{
			printf("The file was not closed\n");
		}
	}
}

int main() {

	// ---------------------------
	// 	   Fill struct Burger, for security.

	Burger newBurgers[SIZE];
	
	// Fill store with empty burgers.
	// data for empty

	fillStore(newBurgers);
	show(newBurgers);

	// end
	// ---------------------------

	// ---------------------------
	// Trying to get all the names from CSV file 
	FILE* burgersData;
	errno_t err;

	char* stringPtr;

	err = fopen_s(&burgersData, "prices.csv", "r");
	if (err == 0) {
		char buffer[1024];

		int row = 0;
		int column = 0;
		int i = 0;

		while (fgets(buffer, 1024, burgersData)) {
			column = 0;
			row++;
			char* value = NULL;
			char* next_value = NULL;
			// To avoid printing of column
			// names in file can be changed
			// according to need
			if (row == 1)
				continue;

			// Splitting the data
			value = strtok_s(buffer, ",", &next_value);

			while (value) {
				// Column 1 CODE
				if (column == 0) {
					newBurgers[i].code = strtod(value, &stringPtr);
					// printf("Code es: %.2f\n", newBurgers[i].code);
				}

				// Column 2 NAME
				if (column == 1) {
					// printf("NAME: ");
					// printf("%s", value);
					// strcpy_s(names[i].name,20,value);
					strcpy_s(newBurgers[i].name, 20, value);
					// printf("names es: %s\n", newBurgers[i].name);
				}

				// Column 3 PRICE
				if (column == 2) {
					newBurgers[i].price = strtod(value, &stringPtr);
					// printf("price es: %.2f\n", newBurgers[i].price);
				}

				// Column 4 NUMBER
				if (column == 3) {
					newBurgers[i].number = strtod(value, &stringPtr);
					// printf("number es: %.2f\n", newBurgers[i].number);
					i++; // move to other struct
				}
				value = strtok_s(NULL, ",", &next_value);
				column++;
			}

		}
		// printf("i = %i\n", i);
	}
	else {
		printf("The file was not opened\n");
	}
	// Close file
	closeFile(burgersData);

	// END
	// ---------------------------
	show(newBurgers);

	

	// Create the burgers for my store and structs for store and shopping cart.
	//const char* name[] = { "Black", "Green", "Yellow", "Blue ", "Orange" };


	

	return 0;
}
 

