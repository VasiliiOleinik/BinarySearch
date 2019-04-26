// BinSearch.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
	const int N = 200, M = 10, A = -100, B = 100;
	SetConsoleOutputCP(1251);
	srand(GetTickCount());

	int a[N];
	int i;

	// Заполнение случайными числамиx
	for(i = 0; i < N; i++) a[i] = A + rand() % (B - A + 1);

	// Сортировка методом пузырька
	for(i = 0; i < N; i++) {
		for(int j = 0; j < N - i - 1; j++) 
			if (a[j] > a[j+1]) swap(a[j], a[j+1]);
	} // for i

	// Вывод массива на экран
	cout << "\nОтсортированный массив:\n";
	for(i = 0; i < N; i++) {
		cout << setw(7) << a[i];
		if ((i+1) % M == 0) cout << "\n";
	} // for i
	if (N%M) cout << "\n";

	// Бинарный поиск
	int left, right, middle;
	int key;
	bool flag;

	while(true) {
		cout << "\nВведите число, которое надо найти в массиве (-999 для выхода)> ";
		cin >> key;
		if (key == -999) break;

		left = 0; right = N - 1; flag = false;
		while(right >= left) {
			middle = left + (right - left)/2;
			if (a[middle] == key) {
				flag = true;
				break;
			} // if

			if (a[middle] < key)
				left = middle + 1;
			else 
				right = middle - 1;
		} // while

		if (flag) {
			cout << "Элемент со значением " << key << " найден в массиве :)\n"
				<< "его индекс = " << middle << "\n";
			// Вывод всех элементов, значение которых совпадает с ключом поиска
			cout << "i\ta[i]\n--------------------------\n";
			for (i = middle; a[i] == key; i++) {
				cout << i << "\t" << a[i] << "\n";
			} // for i
		} 
		else
		{
			cout << "Элемент со значением " << key << " не найден в массиве :(\n";
		} // if
	} // while

	return 0;
} // main

