// Printing all subsequences of an array

#include<bits/stdc++.h>
using namespace std;

// Using recursion
void printSub(int ind, vector<int> &arr, int n, vector<int> &sub) {
	if (ind >= n) {
		for (auto i : sub) {
			cout << i << " ";
		}
		if (sub.size() == 0) cout << "{}";
		cout << endl;
		return;
	}

	// Take operation: Current element will be added to the subsequence
	sub.push_back(arr[ind]);
	printSub(ind + 1, arr, n, sub);

	// Not Take operation: Current element will be ignored and next subsequence will be generated
	sub.pop_back();
	printSub(ind + 1, arr, n, sub);

}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << " elements of array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	cout << "Subsequences: " << endl;
	vector<int> sub;
	printSub(0, arr, n, sub);
	return 0;
}