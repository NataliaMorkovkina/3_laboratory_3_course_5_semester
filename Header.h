#include <vector>    
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std; 

int n; vector <int> vec;

void Insertion_sort() {
	
	auto start_time = chrono::high_resolution_clock::now();
	//Insertion sort
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && vec[j - 1] > vec[j]; j--)
			swap(vec[j - 1], vec[j]);
	auto end_time = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end_time - start_time;

	cout << "\nВремя выполнения - " << duration.count() * 100 << endl;


	
}


void Selection_sort() {
	


	auto start_time = chrono::high_resolution_clock::now();
	//Selection sort
	int m = 0;
	int buf = 0;
	for (int i = 0; i < n; i++)
	{
		m = i;
		for (int j = i + 1; j < n; j++)
			m = (vec[j] < vec[m]) ? j : m;
		if (i != m)
		{
			buf = vec[i];
			vec[i] = vec[m];
			vec[m] = buf;
		}
	}
	
	auto end_time = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end_time - start_time;

	cout << "\nВремя выполнения - " << duration.count() * 100 << endl;

}


void Bubble_sort(){
	

		auto start_time = chrono::high_resolution_clock::now();

		//Bubble sort
		int temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (vec[j] > vec[j + 1]) {

					temp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = temp;
				}
			}
		}

		auto end_time = chrono::high_resolution_clock::now();

		chrono::duration<float> duration = end_time - start_time;

		cout << "\nВремя выполнения - " << duration.count() * 100 << endl;
}





void Merge_sort(vector<int>& v, int begin, int end) {

	if (begin == end)
		return;

	int mid = (begin + end) / 2;

	Merge_sort(v, begin, mid);
	Merge_sort(v, mid + 1, end);

	vector<int> t;
	for (int i = begin, j = mid + 1; i <= mid || j <= end;) {
		if (i > mid) {
			t.push_back(v[j++]);
		}
		else if (j > end) {
			t.push_back(v[i++]);
		}
		else if (v[i] <= v[j]) {
			t.push_back(v[i++]);
		}
		else {
			t.push_back(v[j++]);
		}
	}

	for (int i = 0; i < t.size(); i++) {
		v[begin + i] = t[i];
	}



}




void Shell_Sort(){
	

	auto start_time = chrono::high_resolution_clock::now();


	//Shell sort

	for (int step = (n + 1) / 2; step > 0; step /= 2)
	{
		for (int i = step; i < n; i += 1)
		{
			int j = i;
			while (j >= step && vec[j - step] > vec[i])
			{
				swap(vec[j], vec[j - step]);
				j -= step;
			}
		}
	}

	auto end_time = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end_time - start_time;

	cout << "\nВремя выполнения - " << duration.count() * 100 << endl;

}



void Quick_sort(vector<int>& v, int begin, int end) {


	if (begin >= end)
		return;

	int pivot = v[begin];
	int count = 0;
	for (int i = begin + 1; i <= end; i++)
		if (v[i] <= pivot)
			count++;

	int pivotIndex = begin + count;
	swap(v[pivotIndex], v[begin]);

	int i = begin, j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (v[i] <= pivot)
			i++;
		while (v[j] > pivot)
			j--;
		if (i < pivotIndex && j > pivotIndex)
			swap(v[i++], v[j--]);
	};

	Quick_sort(v, begin, pivotIndex - 1);

	Quick_sort(v, pivotIndex + 1, end);


	

}




void Inbuilt_sort() {

	auto start_time = chrono::high_resolution_clock::now();

	sort(vec.begin(), vec.end());

	auto end_time = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end_time - start_time;

	cout << "\nВремя выполнения - " << duration.count() * 100 << endl;

}