#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char* argv[])
{
    system("clear");
	
	size_t arraySize = 0; 
	
	printf("Specify the size of the array: ");
	scanf("%i", &arraySize);
	
	int number = 0;
	printf("Please enter the elements(%d):\n", arraySize);
	
	for (int i = 0; i < arraySize; i++) {
		
		scanf("%i", &number);
		append(number);
	}
	
	printf("\nYour array: ");
	print();
	
	int rangeA = 0, rangeB = 0, rangeCurrent = 0;
	printf("\nEnter the range [a, b]: ");
	scanf("%i %i", &rangeA, &rangeB);
	
	if (rangeA > rangeB) {
		printf("\nError. a > b \n\n");
	}
	
	for (size_t i = 0; i < size; i++) {
		
		for (int j = rangeA; j <= rangeB; j++) {
			
			if (data[i] == j)
				erase(i);
		}
	}
	
	for (int j = rangeA; j <= rangeB; j++) {
		
		for (size_t i = 0; i < size; i++) {
				
			if (data[i] == j)
				erase(i);
		}
	}
	
	printf("\nYour new array: ");
	print();
	
	printf("\n");	
    return 0;
}
