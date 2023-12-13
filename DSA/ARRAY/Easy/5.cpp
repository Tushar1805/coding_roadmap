
#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
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

	cout << "Left Rotation\n";
	cout << "Array without rotation: ";
	display(arr);

	int temp = arr[0];
	for (int i = 0; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;

	cout << "\nArray after rotation: ";
	display(arr);

	cout << "\n\nRight Rotation\n";
	cout << "Array without rotation: ";
	display(arr);
	int t = arr[n - 1];
	for (int i = n - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = t;
	cout << "\nArray after rotation: ";
	display(arr);

	return 0;
}