#include<iostream>
using namespace std;

int v=1;

int partition (int array[], int l, int h, int n) {
	int pivot = array[l];
	int i = 0;
	int j = h;
	while (i < j) {
		while (array[i] <= pivot) {
			i++;
		}
		while(array[j] > pivot) {
			j--;
		} 
		if (i < j) {
			swap(array[i], array[j]);
		}
	}
	swap(array[j], array[l]);
	cout << "\nPass " << v <<": "<< endl;
	v++;
	for (int i=0; i<n; i++) {
		cout << " " << array[i];
	}
	cout << endl;
	return j;
}

void quickSort (int array[], int l, int h, int n) {
	if (l < h) {
		int p = partition (array, l, h, n);
		quickSort(array, l, p - 1, n);
		quickSort(array, p + 1, h, n);
	}
}

int main() {
	cout << "Enter total number of elements of array: ";
	int n;
	cin >> n;
	int array[n];
	cout << "Enter the elements of the array: ";
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	quickSort(array, 0, n-1, n);
	cout << "\n\nSorted Array is: ";
	for (int i=0; i<n; i++) {
		cout << " " << array[i];
	}
	cout << endl;
	return 0;
}
