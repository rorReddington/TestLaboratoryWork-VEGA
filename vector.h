#pragma once

extern int *vector; // указатель на массив
extern size_t vecSize; // количество элементов массива
extern size_t vecCapacity; // максимальное количество элементов, которое можно
						// хранить в выделенной памяти

void append(int value); // добавляет value в конец массива
//void append(int *array, size_t count); // добавляет count чисел из array в конец массива
void insert(size_t pos, int value); // вставляет value на позицию pos и сдвигает 
									// элементы справа
void erase(size_t pos); // удаляет элемент на позиции pos и сдвигает элементы справа
//int indexOf(int value); // возвращает индекс элемента со значением value
void reserve(size_t newCap); // устанавливает значение vecCapacity большее или равное
							 // newCap, если newCap < vecCapacity ничего не делает
void squeeze(); // изменяет размер выделенной памяти так, чтобы он соответствовал
				// количеству элементов, если vecSize = 0, вызывает free
//void clear(); // заполняет массив нулями и изменяет vecSize
void print(); // выводит в консоль элементы массива