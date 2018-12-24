#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char* argv[])
{
	system("clear");

	Vector *vec = createVector();

	size_t arraySize = 0;

	printf("Specify the size of the array: ");
	scanf("%lu", &arraySize);

	int number = 0;
	printf("Please enter the elements(%lu):\n", arraySize);

	for (size_t i = 0; i < arraySize; i++) {

		scanf("%i", &number);
		append(vec, number);
	}

	printf("\nYour array: ");
	print(vec);

	int rangeA = 0, rangeB = 0;
	printf("\nEnter the range [a, b]: ");
	scanf("%i %i", &rangeA, &rangeB);

	if (rangeA > rangeB) {
		printf("\nError. a > b \n\n");
		return 1;
	}

	for (size_t i = 0; i < vec->size; i++) {

		if (vec->data[i] >= rangeA && vec->data[i] <= rangeB) {

			erase(vec, i);
			i--;
		}
	}

	printf("\nYour new array: ");
	print(vec);

	deleteVector(vec);

	printf("\n");
	return 0;
}
