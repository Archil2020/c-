#include <iostream>
#include <fstream>
#include "String.h"
#include "List.h" 
#include <ctime>

using namespace std;
typedef String word;
#pragma warning(disable: 4996)
bool desc(int* a, int* b) {
	if (*a > *b) {
		return true;
	}
	else
	{
		return false;
	}
}

bool inc(int* a, int* b) {
	if (*a < *b) {
		return true;
	}
	else
	{
		return false;
	}
}

void BubbleSort(int* arr,int length,bool (*check)(int*,int*)){
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < (length-1); j++)
		{
			if (check(&arr[j], &arr[j+1]) == true) {
				int swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}

		}
	}
}

void SelectionSort(int* arr,int length,bool (*check)(int*,int*)) {
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = i+1; j < length; j++)
		{
			if (check(&arr[j], &arr[i]) == true) {
				int swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}
}

int main(){
	srand(time(0));
	int arr[10000] = { 10,9,11,7,6,5 };
	for (size_t i = 0; i < 10000; i++)
	{
		arr[i] = rand() % 1000;
	}
	time_t start, end,t;
	start = clock();
	SelectionSort(arr, 10000, inc);

	end = clock();
	t = (end - start) / CLOCKS_PER_SEC;

	cout << t << endl;;
	/*for (size_t i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}*/

	return 0;
}
