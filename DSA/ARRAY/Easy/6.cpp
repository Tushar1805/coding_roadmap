#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

void reverse(vector<int> &arr, int start, int end) {
	while (start <= end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

//! Brute force: Rotate right
void rotateRight1(vector<int> &arr, int d, int n) {
	if (n == 0) return;
	d = d % n;
	if (d > n) return;
	int temp[d];

	for (int i = 0; i < d; i++) {
		temp[i] = arr[i + d - 1];
	}
	for (int i = n - d - 1; i >= 0; i--) {
		arr[i + d] = arr[i];
	}
	for (int i = 0; i < d; i++) {
		arr[i] = temp[i];
	}
}

//! Brute force: Rotate left
void rotateLeft1(vector<int> &arr, int d, int n) {
	if (n == 0) return;
	d = d % n;
	if (d > n) return;
	int temp[d];

	for (int i = 0; i < d; i++) {
		temp[i] = arr[i];
	}
	for (int i = 0; i < n - d; i++) {
		arr[i] = arr[i + d];
	}
	for (int i = n - d; i < n; i++) {
		arr[i] = temp[i - n + d];
	}
}

//! Approach 2: Right Rotation: Using Reversal Algorithm
void rotateRight2(vector<int> &arr, int d, int n) {
	reverse(arr, n - d, n - 1);
	reverse(arr, 0, n - d - 1);
	reverse(arr, 0, n - 1);
}

//! Approach 2: Left Rotation Using Reversal Algorithm
void rotateLeft2(vector<int> &arr, int d, int n) {
	reverse(arr, 0, d - 1);
	reverse(arr, d, n - 1);
	reverse(arr, 0, n - 1);
}


int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	int d;
	cout << "Enter how many times you want to rotate the array: ";
	cin >> d;

	//! Extream Bruete force
	// for (int i = 0; i < d; i++) {
	// 	int temp = arr[0];
	// 	for (int j = 0; j < n - 1; j++) {
	// 		arr[j] = arr[j + 1];
	// 	}
	// 	arr[n - 1] = temp;
	// }
	rotateRight2(arr, d, n);
	cout << "Array after right rotations: ";
	display(arr);
	rotateLeft2(arr, d, n);
	cout << "\nArray after left rotations: ";

	display(arr);

	return 0;
}