#include<bits/stdc++.h>
using namespace std;

//! Extream Bruete force approach
void brueteForce(vector<int> arr, int n) {
	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (arr[i] != 0) ans.push_back(arr[i]);

	int zeroCount = n - ans.size();
	for (int i = 0; i < zeroCount; i++)
		ans.push_back(0);

	cout << "Array after shifting zeroes to the end of the array: ";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}

vector<int> moveZeros(int n, vector<int> a) {
	int j = -1;
	//place the pointer j:
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			j = i;
			break;
		}
	}

	//no non-zero elements:
	if (j == -1) return a;

	//Move the pointers i and j
	//and swap accordingly:
	for (int i = j + 1; i < n; i++) {
		if (a[i] != 0) {
			swap(a[i], a[j]);
			j++;
		}
	}
	return a;
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

	// brueteForce(arr, n);

	//! Optimized approach
	vector<int> ans = moveZeros(n, arr);
	cout << "Array after shifting zeroes to the end of the array: ";
	for (auto &it : ans) {
		cout << it << " ";
	}
	cout << '\n';

	return 0;
}