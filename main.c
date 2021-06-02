#include <stdio.h>
#include <stdlib.h>
// for Files
#include <errno.h>
#include <string.h>

#define SIZE 5


// Struct for burgers
struct burger {
	const char *name;
	int number;
	float price;
};
typedef struct burger Burger;

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
void fillStore(Burger * const B,const char * C[]) {
	int azar = 2;

	for (size_t i = 0; i < SIZE; i++) {
		B[i].name = C[i];
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

	
	
	// Trying to get all the names from CSV file 
	FILE* burgersData;
	errno_t err;
	
	

	err = fopen_s(&burgersData, "prices.csv", "r");
	if(err == 0){
		
		char names[SIZE][20];
		char buffer[1024];

		int column = 0; // 1 'cause the name is in the column 1
		int row = 0; //  avoid to print the name of the columns	
		int i = 0;
		char* token = NULL;
		char* next_token = NULL;

		while(fgets(buffer, 1024, burgersData)){
			
			column = 0;
			row++;
			

			// to avoid the name of the column
			if (row == 1)
				continue;

			// Establish string and get the first token:
			token = strtok_s(buffer, ", ", &next_token);
			printf("%s\n", token);

				while (token) {
					
					if (column == 1) {
						strcpy_s(names[i], _countof(names), token);
						printf("%s\n", names[i]);
						i++;
						printf("%i", i);
					}
					token = strtok_s(NULL, ", ", &next_token);
					printf("%s\n", token);
					column++;
				}
				
				
		}
			
	}
	else {
		printf("The file was not opened\n");
	}
	// Close file
	closeFile(burgersData);







	// Create the burgers for my store and structs for store and shopping cart.
	const char* name[] = { "Black", "Green", "Yellow", "Blue ", "Orange" };

	Burger newBurgers[SIZE];

	// Fill store with burgers.
	fillStore(newBurgers,name);



	show(newBurgers);



	return 0;
}