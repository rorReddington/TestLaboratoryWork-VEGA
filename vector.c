#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "vector.h"

Vector *createVector() 
{
	vector *newVector = (vector *)malloc(sizeof(Vector));

	newVector->data = 0;
	newVector->size = 0;
	newVector->capacity = 0;

	return newVector;
}

void deleteVector(Vector *v) 
{
	if (v->data != 0)
		free(v->data);

	free(v);
}

Vector *copyVector(Vector *v) 
{
	vector *newVector = createVector();

	newVector->capacity = v->capacity;
	newVector->size = v->size;
	newVector->data = 0;

	newVector->capacity = (newVector->capacity == 0) ? 1 : newVector->capacity;

	newVector->data = (int *)malloc(v->capacity * sizeof(int));

	for (int i = 0; i < v->size; i++)
		newVector->data[i] = v->data[i];

	return newVector;
}

void swapVector(Vector *v1, Vector *v2) 
{
	int *tempData = v2->data;
	size_t tempSize = v2->size;
	size_t tempCapacity = v2->capacity;

	v2->data = v1->data;
	v2->size = v1->size;
	v2->capacity = v1->capacity;

	v1->data = tempData;
	v1->size = tempSize;
	v1->capacity = tempCapacity;
}

void reserve(Vector *v, size_t newCap) 
{
	if (newCap > v->capacity)
	{
		v->capacity = (v->capacity == 0) ? 1 : v->capacity;

		while (newCap > v->capacity)
			v->capacity <<= 1;

		if (v->data == 0)
			v->data = (int *)malloc(v->capacity * sizeof(int));
		else
			v->data = (int *)realloc((void *)v->data, v->capacity * sizeof(int));
	}
}

void append(Vector *v, int value) 
{
	reserve(v, v->size + 1);

	v->data[v->size] = value;

	v->size++;
}

void append(Vector *v, int *array, size_t count)
{
	assert(count != 0);

	for (size_t i = 0; i < count; i++)
		append(v, array[i]);
}

void insert(Vector *v, size_t pos, int value)
{
	assert(pos < v->size);

	reserve(v, v->size + 1);

	for (size_t i = v->size; i > pos; i--)
		v->data[i] = v->data[i - 1];

	v->data[pos] = value;

	v->size++;
}

void erase(Vector *v, size_t pos) 
{
	assert(pos < v->size);

	for (size_t i = pos; i < v->size; i++)
		v->data[i] = v->data[i + 1];

	v->size--;
}

void print(Vector *v)
{
	for (size_t i = 0; i < v->size; i++)
		printf("%i ", v->data[i]);

	printf("\n");
}

void squeeze(Vector *v)
{
	if (v->data == 0)
		return;

	if (v->size == 0)
	{
		free(v->data);
		return;
	}

	v->data = (int *)realloc((void *)v->data, v->size * sizeof(int));
	v->capacity = v->size;
}

void clear(Vector *v)
{
	if (NULL == v->data)
		return;

	free(v->data);
	v->data = 0;
	v->capacity = 0;
	v->size = 0;
}

int indexOf(Vector *v, int value)
{
	for (size_t i = 0; i < v->size; i++)
		if (v->data[i] == value)
			return i;

	return -1;
}