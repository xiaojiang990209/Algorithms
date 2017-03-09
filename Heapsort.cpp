#include<iostream>
#define SIZE 8
using namespace std;

void heapsort(int *ar, int n);
void heapify(int *ar, int i, int n);

int main() {
	int ar[8] = { 1,5,99,76,3,55,23,17 };
	heapsort(ar, 8);
	for (int i = 0; i < 8; i++) {
		cout << ar[i] << ' ';
	}
	system("pause");
}

void heapsort(int *ar, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(ar, i, n);
	}
	for (int i = n-1; i >= 0; i--) {
		int temp = ar[i];
		ar[i] = ar[0];
		ar[0] = temp;
		heapify(ar, 0, i);
	}
}

void heapify(int *ar, int i, int n) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n&&ar[largest] < ar[l]) {
		largest = l;
	}
	if (r < n&&ar[largest] < ar[r]) {
		largest = r;
	}
	if (largest != i) {
		int temp = ar[largest];
		ar[largest] = ar[i];
		ar[i] = temp;
		heapify(ar, largest, n);
	}

}
