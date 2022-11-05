#include <vector>    
#include <algorithm>
#include <iostream>
#include "Header.h"
using namespace std;
 
int main() {
	setlocale(0, "");


	cout << "Введите количество элементов последовательности: "; cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ") "; cin >> a;
		vec.push_back(a);
	}
	cout << "Выберите, какую сортировку использовать: \n";
	cout << "1) Сортировка вставками (Insertion sort)\n";
	cout << "2) Сортировка выбором(Selection sort)\n";
	cout << "3) Пузырьковая сортировка(Bubble sort)\n";
	cout << "4) Сортировка слиянием(Merge sort)\n";
	cout << "5) Сортировка Шелла(Shell sort)\n";
	cout << "6) Быстрая сортировка(Quick sort)\n";
	cout << "7) Встроенная сортировка языка\n";
	int sw; cin >> sw;
	switch (sw)
	{
	case 1:
		cout << "Сортировка вставками (Insertion sort)\n";
		cout << "Вот как выглядит последовательность до: ";
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		
		Insertion_sort();

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		
		break;
	case 2: 
		cout << " Сортировка выбором(Selection sort)\n";

		cout << "Вот как выглядит последовательность до: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		Selection_sort();

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		
		break;
	case 3:
		cout << "Пузырьковая сортировка(Bubble sort)\n";

		cout << "Вот как выглядит последовательность до: ";

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}

		Bubble_sort();

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		break;

	case 4:
		cout << "Сортировка слиянием(Merge sort)\n";		
	
		cout << "Вот как выглядит последовательность до: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		{
			auto start_time = chrono::high_resolution_clock::now();
			Merge_sort(vec, 0, n - 1);

			auto end_time = chrono::high_resolution_clock::now();

			chrono::duration<float> duration = end_time - start_time;

			cout << "\nВремя выполнения - " << duration.count() * 100 << endl;

		}
		

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		
		break;
	case 5:
		cout << "Сортировка Шелла(Shell sort)\n";

		cout << "Вот как выглядит последовательность до: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		Shell_Sort();

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		
		break;
	case 6:
		cout << "Быстрая сортировка(Quick sort)\n";


		cout << "Вот как выглядит последовательность до: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		{
			auto start_time = chrono::high_resolution_clock::now();
			Quick_sort(vec, 0, n - 1);

			auto end_time = chrono::high_resolution_clock::now();

			chrono::duration<float> duration = end_time - start_time;

			cout << "\nВремя выполнения - " << duration.count() * 100 << endl;

		}


		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}


		
		break;
	case 7:
		cout << "Встроенная сортировка \n";

		Inbuilt_sort();

		cout << "\nПосле сортировки: ";

		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}

		break;
	}
 
  
  return 0;
}