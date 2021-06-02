#include <stdio.h>
#include <stdlib.h>
// for Files
#include <errno.h>
#include <string.h>

#define SIZE 5


// Struct for burgers
struct burger {
	//const char *name;
	char name[20];
	double price;
	int number;
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
		printf("%i. %s\t\t%i\t\t$%.2f\n", i + 1, B[i].name, B[i].number, B[i].price);
	}
}

// Fill the struct
void fillStore(Burger * const B, Name * const C) {
	int azar = 2;

	for (size_t i = 0; i < SIZE; i++) {
		strcpy_s(B[i].name,20,C[i].name);
		//B[i].name = C[i].name;
		B[i].number = azar * 5;
		B[i].price = 13.5 + i;
		azar++;
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
	// Trying to get all the names from CSV file 
	FILE* burgersData;
	errno_t err;
	Name names[5];
	int i = 0;

	err = fopen_s(&burgersData, "prices.csv", "r");
	if(err == 0){
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,1024, burgersData)) {
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
				// Column 1
				if (column == 0) {
					
				}

				// Column 2
				if (column == 1) {
					printf("NAME: ");
					printf("%s", value);
					strcpy_s(names[i].name,20,value);
					i++;
				}

				// Column 3
				if (column == 2) {
				}

				// Column 4
				if (column == 3) {	
				}

				value = strtok_s(NULL, ",", &next_value);
				column++;
			}

			printf("\n");
		}
	}
	else {
		printf("The file was not opened\n");
	}
	// Close file
	closeFile(burgersData);
	// ---------------------------
	
	printf("%s\n", names[2].name);



	

	// Create the burgers for my store and structs for store and shopping cart.
	//const char* name[] = { "Black", "Green", "Yellow", "Blue ", "Orange" };

	Burger newBurgers[SIZE];

	// Fill store with burgers.
	fillStore(newBurgers,names);



	show(newBurgers);

	

	return 0;
}

/*
code	name	price	amount
1	blue	12.3	9
2	green	15	8
3	yellow	13.5	7
4	red	14.99	1
5	purple	15	3
*/