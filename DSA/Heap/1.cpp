//! Heap Implementation using array

#include<iostream>
using namespace std;

class Heap {
public:
	int arr[100];
	int size;

	Heap() {
		size = 0;
		arr[0] = -1;
	}

	void insert(int val) {
		size = size + 1;
		int i = size;

		// Step 1: Insert at the end;
		arr[i] = val;

		// Step 2: Take it to its correct position
		while (i > 1) {
			int parent = i / 2;
			if (arr[parent] < arr[i]) {
				swap(arr[parent], arr[i]);
				i = parent;
			} else {
				return;
			}
		}
	}

	void deleteFromHeap() {
		if (size == 0) {
			cout << "Nothing to delete\n";
			return;
		}

		// Step 1: put last element at index 1
		arr[1] = arr[size];
		// Step 2: Remove the last index
		size--;

		// Step 3: Take the root at its correct position
		int i = 1;
		while (i < size) {
			int leftIndex = 2 * 1;
			int rightIndex = 2 * 1 + 1;
			if (leftIndex < size && arr[i] < arr[leftIndex]) {
				swap(arr[i], arr[leftIndex]);
				i = leftIndex;
			} else if (rightIndex < size && arr[i] < arr[rightIndex]) {
				swap(arr[i], arr[rightIndex]);
				i = rightIndex;
			} else {
				return;
			}
		}
	}

	void print() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

void maxHeapify(int arr[] , int n , int i) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left <= n && arr[largest] < arr[left]) {
		largest = left;
	}
	if (right <= n && arr[largest] < arr[right]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[largest], arr[i]);
		maxHeapify(arr, n, largest);
	}
}

void minHeapify(int arr[] , int n , int i) {
	int smallest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < n && arr[smallest] > arr[left]) {
		smallest = left;
	}
	if (right < n && arr[smallest] > arr[right]) {
		smallest = right;
	}
	if (smallest != i) {
		swap(arr[smallest], arr[i]);
		minHeapify(arr, n, smallest);
	}

}

void heapSort(int arr[], int n) {
	int size = n;
	while (size > 1) {
		// Step 1: swap 1st element with last element
		swap(arr[size], arr[1]);
		size--;

		// Step 2: correct the positions
		maxHeapify(arr, size, 1);
	}
}

int main(int argc, char const *argv[])
{
	Heap h;
	h.insert(20);
	h.insert(30);
	h.insert(60);
	h.insert(40);
	h.insert(50);
	h.print();
	h.deleteFromHeap();
	h.print();

	int arr[6] = { -1, 54, 53, 55, 52, 50};
	int n = 5;
	// for (int i = n / 2; i >= 0 ; i--) {
	// 	maxHeapify(arr, n, i);
	// }
	// cout << "\nPrinting the result: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << arr[i] << " ";
	// }

	heapSort(arr, n);
	cout << "\nPrinting the sorted array: ";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}