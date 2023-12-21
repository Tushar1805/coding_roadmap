#include<bits/stdc++.h>
using namespace std;

void solution1(vector<int> &arr, int n) {
	vector<int> pos;
	vector<int> neg;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			pos.push_back(arr[i]);
		} else {
			neg.push_back(arr[i]);
		}
	}
	// int k = 0, l = 0;
	// for (int i = 0; i < n; i++) {
	// 	if (i % 2 == 0) {
	// 		arr[i] = pos[k++];
	// 	} else {
	// 		arr[i] = neg[l++];
	// 	}
	// }
	for (int i = 0; i < n / 2; i++) {
		arr[2 * i] = pos[i];
		arr[2 * i + 1] = neg[i];
	}
}

// Variant 1: Optimal approach
// Here positive and negative elements will be present in equal ammount

vector<int> solution2(vector<int> arr, int n) {
	vector<int> ans(n);
	int pos = 0, neg = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			ans[neg] = arr[i];
			neg += 2;
		} else {
			ans[pos] = arr[i];
			pos += 2;
		}
	}
	return ans;
}

// Varient 2: Optimal Approach
// Here +ve and -ve elements are not equally present in the array

void solution3(vector<int>& arr, int n) {
	vector<int> pos, neg;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			pos.push_back(arr[i]);
		} else {
			neg.push_back(arr[i]);
		}
	}

	if (pos.size() > neg.size()) {
		for (int i = 0; i < neg.size(); i++) {
			arr[2 * i] = pos[i];
			arr[2 * i + 1] = neg[i];
		}
		int index = neg.size() * 2;
		for (int i = neg.size(); i < pos.size(); i++) {
			arr[index++] = pos[i];
		}
	} else {
		for (int i = 0; i < pos.size(); i++) {
			arr[2 * i] = pos[i];
			arr[2 * i + 1] = neg[i];
		}
		int index = pos.size() * 2;
		for (int i = pos.size(); i < neg.size(); i++) {
			arr[index++] = neg[i];
		}
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

	// solution1(arr, n);
	// arr = solution2(arr, n);
	solution3(arr, n);
	cout << "Array after alternations: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}