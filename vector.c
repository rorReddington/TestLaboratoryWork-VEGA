#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "vector.h"

int *vector = 0; // указатель на массив
size_t vecSize = 0; // количество добавленных элементов
size_t vecCapacity = 0; // максимальное количество элементов, которое можно
							// хранить в выделенной памяти

void reserve(size_t newCap)
{
	if (newCap > vecCapacity)
	{
		vecCapacity = (vecCapacity == 0) ? 1 : vecCapacity;

		while (newCap > vecCapacity)
			vecCapacity <<= 1;

		if (vector == 0)
			vector = (int *)malloc(vecCapacity * sizeof(int));
		else
			vector = (int *)realloc((void *)vector, vecCapacity * sizeof(int));
	}
}

void append(int value)
{
	reserve(vecSize + 1);

	vector[vecSize] = value;

	vecSize++;
}

void insert(size_t pos, int value)
{
	assert(pos < vecSize);

	reserve(vecSize + 1);

	for (int i = vecSize; i > pos; i--)
		vector[i] = vector[i - 1];

	vector[pos] = value;

	vecSize++;
}

void erase(size_t pos)
{
	assert(pos < vecSize);

	for (int i = pos; i < vecSize; i++)
		vector[i] = vector[i + 1];

	vecSize--;
}

void print()
{
	
	for (int i = 0; i < vecSize; i++)
		printf("%i ", vector[i]);

	printf("\n");
}

void squeeze()
{
	if (vector == 0)
		return;

	if (vecSize == 0)
	{
		free(vector);
		return;
	}

	vector = (int *)realloc((void *)vector, vecSize * sizeof(int));
	vecCapacity = vecSize;
}
