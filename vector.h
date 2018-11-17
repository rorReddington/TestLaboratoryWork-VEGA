#pragma once

typedef struct Vector
{
	int *data; // указатель на массив
	size_t size; // количество элементов массива
	size_t capacity; // максимальное количество элементов, которое можно хранить в выделенной памяти
} vector;

Vector *createVector(); // динамически создает структуру, заполняет нулями и возвращает указатель на нее
void deleteVector(Vector *v); // удаляет вектор
Vector *copyVector(Vector *v); // динамически создает вектор newVec, выделяет память для newVec.data и копирует данные из v
void swapVector(Vector *v1, Vector *v2); // меняет местами содержимое векторов

void append(Vector *v, int value); // добавляет value в конец массива
void append(Vector *v, int *array, size_t count); // добавляет count чисел из array в конец массива
void insert(Vector *v, size_t pos, int value); // вставляет value на позицию pos и сдвигает элементы справа
void erase(Vector *v, size_t pos); // удаляет элемент на позиции pos и сдвигает элементы справа
int indexOf(Vector *v, int value); // возвращает индекс элемента со значением value
void reserve(Vector *v, size_t newCap); // устанавливает значение capacity большее или равное newCap, если newCap < capacity ничего не делает
void squeeze(Vector *v); // изменяет размер выделенной памяти так, чтобы он соответствовал количеству элементов, если size = 0, вызывает free
void clear(Vector *v); // заполняет массив нулями и изменяет size
void print(Vector *v); // выводит в консоль элементы массива