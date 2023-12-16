#include<bits/stdc++.h>
using namespace std;

int solution1(vector<int> arr, int n) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	for (auto i : mp) {
		if (i.second == 1) return i.first;
	}
	// It will not be executed if there exist an element with frequency 1
	return -1;
}

int solution2(vector<int> arr, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans ^= arr[i];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << "Elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	// Using hashmap
	// int ans = solution1(arr, n);

	// Using the XOR properties
	int ans = solution2(arr, n);

	cout << "number that appear onl once: " << ans;
	return 0;
}