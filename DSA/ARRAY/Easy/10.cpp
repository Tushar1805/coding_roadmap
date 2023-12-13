#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

// Using the map property
void solution1(vector<int> arr1, vector<int> arr2, int m, int n) {
	map<int, int> mp;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		mp[arr1[i]]++;
	}
	for (int i = 0; i < n; i++) {
		mp[arr2[i]]++;
	}
	for (auto i : mp) {
		if (i.second > 1) ans.push_back(i.first);
	}
	cout << "Intersection of Two array: ";
	display(ans);
}

void solution2(vector<int> arr1, vector<int> arr2, int m, int n) {
	vector<int> ans;
	int i = 0;
	int j = 0;
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	while (i < m && j < n) {
		if (arr1[i] < arr2[j]) {
			i++;
		} else if (arr2[j] < arr1[i]) {
			j++;
		} else {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	cout << "Intersection of two arrays: ";
	display(ans);
}

int main(int argc, char const *argv[])
{
	int m, n;
	cout << "Enter the size of the array 1: ";
	cin >> m;
	cout << "Enter the " << m << " elements of the array 1: ";
	vector<int> arr1;
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		arr1.push_back(data);
	}
	cout << "Enter the size of the array 2: ";
	cin >> n;
	cout << "Enter the " << n << " elements of the array 2: ";
	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr2.push_back(data);
	}

	// solution1(arr1, arr2, m, n);
	solution2(arr1, arr2, m, n);
	return 0;
}